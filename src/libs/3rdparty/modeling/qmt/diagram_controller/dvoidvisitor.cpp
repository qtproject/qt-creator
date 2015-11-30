/***************************************************************************
**
** Copyright (C) 2015 Jochen Becher
** Contact: http://www.qt.io/licensing
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

#include "dvoidvisitor.h"

#include "qmt/diagram/delement.h"
#include "qmt/diagram/dobject.h"
#include "qmt/diagram/dpackage.h"
#include "qmt/diagram/dclass.h"
#include "qmt/diagram/dcomponent.h"
#include "qmt/diagram/ddiagram.h"
#include "qmt/diagram/ditem.h"
#include "qmt/diagram/drelation.h"
#include "qmt/diagram/dinheritance.h"
#include "qmt/diagram/ddependency.h"
#include "qmt/diagram/dassociation.h"
#include "qmt/diagram/dannotation.h"
#include "qmt/diagram/dboundary.h"

namespace qmt {

DVoidVisitor::DVoidVisitor()
{
}

void DVoidVisitor::visitDElement(DElement *element)
{
    Q_UNUSED(element);
}

void DVoidVisitor::visitDObject(DObject *object)
{
    visitDElement(object);
}

void DVoidVisitor::visitDPackage(DPackage *package)
{
    visitDObject(package);
}

void DVoidVisitor::visitDClass(DClass *klass)
{
    visitDObject(klass);
}

void DVoidVisitor::visitDComponent(DComponent *component)
{
    visitDObject(component);
}

void DVoidVisitor::visitDDiagram(DDiagram *diagram)
{
    visitDObject(diagram);
}

void DVoidVisitor::visitDItem(DItem *item)
{
    visitDObject(item);
}

void DVoidVisitor::visitDRelation(DRelation *relation)
{
    visitDElement(relation);
}

void DVoidVisitor::visitDInheritance(DInheritance *inheritance)
{
    visitDRelation(inheritance);
}

void DVoidVisitor::visitDDependency(DDependency *dependency)
{
    visitDRelation(dependency);
}

void DVoidVisitor::visitDAssociation(DAssociation *association)
{
    visitDRelation(association);
}

void DVoidVisitor::visitDAnnotation(DAnnotation *annotation)
{
    visitDElement(annotation);
}

void DVoidVisitor::visitDBoundary(DBoundary *boundary)
{
    visitDElement(boundary);
}

DConstVoidVisitor::DConstVoidVisitor()
{
}

void DConstVoidVisitor::visitDElement(const DElement *element)
{
    Q_UNUSED(element);
}

void DConstVoidVisitor::visitDObject(const DObject *object)
{
    visitDElement(object);
}

void DConstVoidVisitor::visitDPackage(const DPackage *package)
{
    visitDObject(package);
}

void DConstVoidVisitor::visitDClass(const DClass *klass)
{
    visitDObject(klass);
}

void DConstVoidVisitor::visitDComponent(const DComponent *component)
{
    visitDObject(component);
}

void DConstVoidVisitor::visitDDiagram(const DDiagram *diagram)
{
    visitDObject(diagram);
}

void DConstVoidVisitor::visitDItem(const DItem *item)
{
    visitDObject(item);
}

void DConstVoidVisitor::visitDRelation(const DRelation *relation)
{
    visitDElement(relation);
}

void DConstVoidVisitor::visitDInheritance(const DInheritance *inheritance)
{
    visitDRelation(inheritance);
}

void DConstVoidVisitor::visitDDependency(const DDependency *dependency)
{
    visitDRelation(dependency);
}

void DConstVoidVisitor::visitDAssociation(const DAssociation *association)
{
    visitDRelation(association);
}

void DConstVoidVisitor::visitDAnnotation(const DAnnotation *annotation)
{
    visitDElement(annotation);
}

void DConstVoidVisitor::visitDBoundary(const DBoundary *boundary)
{
    visitDElement(boundary);
}

} // namespace qmt
