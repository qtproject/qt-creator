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

#ifndef QMT_SHAPEVALUE_H
#define QMT_SHAPEVALUE_H

#include "qmt/infrastructure/qmt_global.h"

#include <QPointF>
#include <QSizeF>

namespace qmt {

class QMT_EXPORT ShapeValueF
{
public:
    enum Origin {
        OriginSmart,
        OriginTop,
        OriginLeft = OriginTop,
        OriginTopOrLeft = OriginTop,
        OriginBottom,
        OriginRight = OriginBottom,
        OriginBottomOrRight = OriginBottom,
        OriginCenter
    };

    enum Unit {
        UnitAbsolute,
        UnitRelative,
        UnitScaled,
        UnitPercentage
    };

    ShapeValueF()
        : m_value(0.0),
          m_unit(UnitRelative),
          m_origin(OriginSmart)
    {
    }

    explicit ShapeValueF(qreal value, Unit unit = UnitRelative, Origin origin = OriginSmart)
        : m_value(value),
          m_unit(unit),
          m_origin(origin)
    {
    }

    qreal value() const { return m_value; }
    void setValue(qreal value) { m_value = value; }
    Unit unit() const { return m_unit; }
    void setUnit(Unit unit) { m_unit = unit; }
    Origin origin() const { return m_origin; }
    void setOrigin(Origin origin) { m_origin = origin; }

    qreal mapTo(qreal origin, qreal size) const;
    qreal mapScaledTo(qreal scaledOrigin, qreal originalSize, qreal actualSize) const;
    qreal mapScaledTo(qreal scaledOrigin, qreal originalSize, qreal baseSize,
                      qreal actualSize) const;

private:
    qreal m_value;
    Unit m_unit;
    Origin m_origin;
};

class QMT_EXPORT ShapePointF
{
public:
    ShapePointF()
    {
    }

    ShapePointF(const ShapeValueF &x, const ShapeValueF &y)
        : m_x(x),
          m_y(y)
    {
    }

    ShapeValueF x() const { return m_x; }
    void setX(const ShapeValueF &x) { m_x = x; }
    ShapeValueF y() const { return m_y; }
    void setY(const ShapeValueF &y) { m_y = y; }

    QPointF mapTo(const QPointF &origin, const QSizeF &size) const;
    QPointF mapScaledTo(const QPointF &scaledOrigin, const QSizeF &originalSize,
                        const QSizeF &actualSize) const;
    QPointF mapScaledTo(const QPointF &scaledOrigin, const QSizeF &originalSize,
                        const QSizeF &baseSize, const QSizeF &actualSize) const;

private:
    ShapeValueF m_x;
    ShapeValueF m_y;
};

class QMT_EXPORT ShapeSizeF
{
public:
    ShapeSizeF()
    {
    }

    ShapeSizeF(const ShapeValueF &width, const ShapeValueF &height)
        : m_width(width),
          m_height(height)
    {
    }

    ShapeValueF width() const { return m_width; }
    void setWidth(const ShapeValueF &width) { m_width = width; }
    ShapeValueF height() const { return m_height; }
    void setHeight(const ShapeValueF &height) { m_height = height; }

    QSizeF mapTo(const QPointF &origin, const QSizeF &size) const;
    QSizeF mapScaledTo(const QPointF &scaledOrigin, const QSizeF &originalSize,
                       const QSizeF &actualSize) const;
    QSizeF mapScaledTo(const QPointF &scaledOrigin, const QSizeF &originalSize,
                       const QSizeF &baseSize, const QSizeF &actualSize) const;

private:
    ShapeValueF m_width;
    ShapeValueF m_height;
};

} // namespace qmt

#endif // QMT_SHAPEVALUE_H
