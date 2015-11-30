/**************************************************************************
**
** Copyright (C) 2011 - 2014 Research In Motion
**
** Contact: Research In Motion (blackberry-qt@qnx.com)
** Contact: KDAB (info@kdab.com)
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef PROJECTEXPLORER_DEVICECHECKBUILDSTEP_H
#define PROJECTEXPLORER_DEVICECHECKBUILDSTEP_H

#include "../buildstep.h"
#include "../projectexplorer_export.h"

namespace ProjectExplorer {

class BuildStepList;

class PROJECTEXPLORER_EXPORT DeviceCheckBuildStep : public BuildStep
{
    Q_OBJECT
public:
    DeviceCheckBuildStep(BuildStepList *bsl, Core::Id id);
    DeviceCheckBuildStep(BuildStepList *bsl, DeviceCheckBuildStep *bs);

    bool init(QList<const BuildStep *> &earlierSteps) override;

    void run(QFutureInterface<bool> &fi) override;

    BuildStepConfigWidget *createConfigWidget() override;

    static Core::Id stepId();
    static QString stepDisplayName();
};

} // namespace ProjectExplorer

#endif // PROJECTEXPLORER_DEVICECHECKBUILDSTEP_H
