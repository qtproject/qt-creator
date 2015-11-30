/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
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

#ifndef THEMEHELPER_H
#define THEMEHELPER_H

#include "utils_global.h"
#include "theme/theme.h"

#include <QPair>
#include <QVector>

QT_FORWARD_DECLARE_CLASS(QColor)
QT_FORWARD_DECLARE_CLASS(QIcon)
QT_FORWARD_DECLARE_CLASS(QPixmap)
QT_FORWARD_DECLARE_CLASS(QString)

namespace Utils {

typedef QPair<QString, Theme::Color> IconMaskAndColor;

// Returns a recolored icon with shadow and custom disabled state for a
// series of grayscalemask|Theme::Color mask pairs
class QTCREATOR_UTILS_EXPORT Icon : public QVector<IconMaskAndColor>
{
public:
    enum class Style {
        Plain,
        Tinted,
        TintedWithShadow
    };

    Icon();
    Icon(std::initializer_list<IconMaskAndColor> args, Style style = Style::TintedWithShadow);
    Icon(const QString &imageFileName);

    QIcon icon() const;
    // Same as icon() but without disabled state.
    QPixmap pixmap() const;

    // Try to avoid it. it is just there for special API cases in Qt Creator
    // where icons are still defined as filename.
    QString imageFileName() const;

    Icon &operator=(const Icon &other);

private:
    Style m_style = Style::Plain;
};

} // namespace Utils

#endif // THEMEHELPER_H
