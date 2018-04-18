/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Scene3D 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    id: main
    objectName: "main"

    property real rotationValue: 0

    property real l1_ang: rotation_limb1.value
    property real l2_ang: rotation_limb2.value// + l1_ang
    property real l3_ang: rotation_limb3.value// + l2_ang
    property real w_ang: rotation_wrist.value// + l3_ang

    Scene3D {
        id: scene3D
        objectName: "scene3D"

        anchors.fill: parent
        anchors.verticalCenter: parent.verticalCenter
        focus: true
        aspects: "input"

        Arm {
            id: arm_graphic
            objectName: "arm_graphic"
        }
    }

    ColumnLayout {
        id: transformLayout

        anchors.left: parent.horizontalCenter
        anchors.leftMargin: parent.width * 0.25
        anchors.right: parent.right
        anchors.rightMargin: 15
        anchors.top: scene3D.top
        spacing: 5

        Text { text: "Item transform"; font.bold: true }
        Text { text: "Rotation" }

        RowLayout {
            Text { text: "L1" }
            Slider {
                id: rotation_limb1
                Layout.fillWidth: true
                minimumValue: -90
                maximumValue: 90
                value: rotationValue
            }
        }

        RowLayout {
            Text { text: "L2" }
            Slider {
                id: rotation_limb2
                Layout.fillWidth: true
                minimumValue: -90
                maximumValue: 90
                value: rotationValue
            }
        }

        RowLayout {
            Text { text: "L3" }
            Slider {
                id: rotation_limb3
                Layout.fillWidth: true
                minimumValue: -90
                maximumValue: 90
                value: rotationValue
            }
        }

        RowLayout {
            Text { text: "W" }
            Slider {
                id: rotation_wrist
                Layout.fillWidth: true
                minimumValue: -90
                maximumValue: 90
                value: rotationValue
            }
        }
    }


    ColumnLayout {
        id: cameraLayout

        anchors.left: transformLayout.left
        anchors.right: transformLayout.right
        anchors.top: transformLayout.bottom
        anchors.topMargin: 10
        spacing: 5

        Text { text: "Camera"; font.bold: true }
        Text { text: "View Center Z" }
        Slider {
            id: viewCenter_z
            Layout.fillWidth: true
            minimumValue: 5
            maximumValue: 25
            value: 20
        }

        Text { text: "Camera"; font.bold: true }
        Text { text: "View Center X" }
        Slider {
            id: viewCenter_x
            Layout.fillWidth: true
            minimumValue: 0
            maximumValue: 20
            value: 6.5
        }

        Text { text: "Camera"; font.bold: true }
        Text { text: "View Tilt X" }
        Slider {
            id: view_x
            Layout.fillWidth: true
            minimumValue: -20
            maximumValue: 30
            value: 0
        }

        Text { text: "Camera"; font.bold: true }
        Text { text: "View Tilt Y" }
        Slider {
            id: view_y
            Layout.fillWidth: true
            minimumValue: -20
            maximumValue: 20
            value: 0
        }

    }
}
