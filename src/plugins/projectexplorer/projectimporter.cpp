/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#include "projectimporter.h"

#include "kit.h"
#include "kitinformation.h"
#include "kitmanager.h"
#include "project.h"
#include "projectexplorerconstants.h"
#include "target.h"

#include <coreplugin/idocument.h>

#include <utils/qtcassert.h>

namespace ProjectExplorer {

static const Core::Id KIT_IS_TEMPORARY("PE.TempKit");
static const Core::Id KIT_TEMPORARY_NAME("PE.TempName");
static const Core::Id KIT_FINAL_NAME("PE.FinalName");
static const Core::Id TEMPORARY_OF_PROJECTS("PE.TempProject");

ProjectImporter::ProjectImporter(const QString &path) : m_projectPath(path)
{ }

ProjectImporter::~ProjectImporter()
{
    foreach (Kit *k, KitManager::kits())
        removeProject(k);
}

Target *ProjectImporter::preferredTarget(const QList<Target *> &possibleTargets)
{
    // Select active target
    // a) The default target
    // c) Desktop target
    // d) the first target
    Target *activeTarget = nullptr;
    if (possibleTargets.isEmpty())
        return activeTarget;

    activeTarget = possibleTargets.at(0);
    bool pickedFallback = false;
    foreach (Target *t, possibleTargets) {
        if (t->kit() == KitManager::defaultKit())
            return t;
        if (pickedFallback)
            continue;
        if (DeviceTypeKitInformation::deviceTypeId(t->kit()) == Constants::DESKTOP_DEVICE_TYPE) {
            activeTarget = t;
            pickedFallback = true;
        }
    }
    return activeTarget;
}

void ProjectImporter::markTemporary(Kit *k)
{
    QTC_ASSERT(!k->hasValue(KIT_IS_TEMPORARY), return);

    UpdateGuard guard(*this);

    const QString name = k->displayName();
    k->setUnexpandedDisplayName(QCoreApplication::translate("ProjectExplorer::ProjectImporter",
                                                  "%1 - temporary").arg(name));

    k->setValue(KIT_TEMPORARY_NAME, k->displayName());
    k->setValue(KIT_FINAL_NAME, name);
    k->setValue(KIT_IS_TEMPORARY, true);
}

void ProjectImporter::makePermanent(Kit *k)
{
    if (!k->hasValue(KIT_IS_TEMPORARY))
        return;

    UpdateGuard guard(*this);

    k->removeKey(KIT_IS_TEMPORARY);
    k->removeKey(TEMPORARY_OF_PROJECTS);
    const QString tempName = k->value(KIT_TEMPORARY_NAME).toString();
    if (!tempName.isNull() && k->displayName() == tempName)
        k->setUnexpandedDisplayName(k->value(KIT_FINAL_NAME).toString());
    k->removeKey(KIT_TEMPORARY_NAME);
    k->removeKey(KIT_FINAL_NAME);
}

void ProjectImporter::cleanupKit(Kit *k)
{
    Q_UNUSED(k);
}

void ProjectImporter::addProject(Kit *k)
{
    if (!k->hasValue(KIT_IS_TEMPORARY))
        return;

    UpdateGuard guard(*this);
    QStringList projects = k->value(TEMPORARY_OF_PROJECTS, QStringList()).toStringList();
    projects.append(m_projectPath); // note: There can be more than one instance of the project added!
    k->setValueSilently(TEMPORARY_OF_PROJECTS, projects);
}

void ProjectImporter::removeProject(Kit *k)
{
    if (!k->hasValue(KIT_IS_TEMPORARY))
        return;

    UpdateGuard guard(*this);
    QStringList projects = k->value(TEMPORARY_OF_PROJECTS, QStringList()).toStringList();
    projects.removeOne(m_projectPath);

    if (projects.isEmpty())
        KitManager::deregisterKit(k);
    else
        k->setValueSilently(TEMPORARY_OF_PROJECTS, projects);
}

bool ProjectImporter::isTemporaryKit(Kit *k) const
{
    return k->hasValue(KIT_IS_TEMPORARY);
}

Kit *ProjectImporter::createTemporaryKit(const KitSetupFunction &setup)
{
    Kit *k = new Kit;
    UpdateGuard guard(*this);
    {
        KitGuard kitGuard(k);
        k->setUnexpandedDisplayName(QCoreApplication::translate("ProjectExplorer::ProjectImporter", "Imported Kit"));;
        markTemporary(k);

        setup(k);

        // Set up values:
        foreach (KitInformation *ki, KitManager::kitInformation())
            ki->setup(k);
    } // ~KitGuard, sending kitUpdated
    KitManager::registerKit(k); // potentially adds kits to other targetsetuppages
    return k;
}

} // namespace ProjectExplorer
