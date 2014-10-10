/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

import QtQuick 2.1
import HelperWidgets 2.0
import QtQuick.Layouts 1.0

Column {
    anchors.left: parent.left
    anchors.right: parent.right

    Section {
        anchors.left: parent.left
        anchors.right: parent.right
        caption: qsTr("Window")

        SectionLayout {
            Label {
                text: qsTr("Title")
            }

            SecondColumnLayout {
                LineEdit {
                    backendValue: backendValues.title
                    Layout.fillWidth: true
                }

                ExpandingSpacer {

                }
            }

            Label {
                text: qsTr("Size")
            }

            SecondColumnLayout {
                Label {
                    text: "W"
                    width: 12
                }

                SpinBox {
                    backendValue: backendValues.width
                    minimumValue: 0
                    maximumValue: 10000
                    decimals: 0
                }

                Label {
                    text: "H"
                    width: 12
                }

                SpinBox {
                    backendValue: backendValues.height
                    minimumValue: 0
                    maximumValue: 10000
                    decimals: 0
                }

                ExpandingSpacer {

                }
            }

        }
    }

    Section {
        anchors.left: parent.left
        anchors.right: parent.right
        caption: qsTr("Color")

        ColorEditor {
            caption: qsTr("Color")
            backendValue: backendValues.color
            supportGradient: true
        }

    }

    Section {
        anchors.left: parent.left
        anchors.right: parent.right
        caption: "Rectangle"

        SectionLayout {
            rows: 2
            Label {
                text: qsTr("Visible")
            }
            SecondColumnLayout {
                CheckBox {
                    backendValue: backendValues.visible
                    Layout.preferredWidth: 80
                }
                ExpandingSpacer {

                }
            }
            Label {
                text: qsTr("Opacity")
            }
            SecondColumnLayout {
                SpinBox {
                    backendValue: backendValues.opacity
                    hasSlider: true
                    Layout.preferredWidth: 80
                    minimumValue: 0
                    maximumValue: 1
                    stepSize: 0.1
                    decimals: 2
                }
                ExpandingSpacer {

                }
            }
        }
    }
}
