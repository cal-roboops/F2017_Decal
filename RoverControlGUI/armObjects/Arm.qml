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

import Qt3D.Core 2.0
import Qt3D.Render 2.0
import QtQuick 2.0
import Qt3D.Extras 2.0

Entity {
    id: sceneRoot
    objectName: "sceneRoot"

    property real l1_hyp: 2.203604
    property real l2_hyp: 3.57407
    property real l3_hyp: 3.74676

    property real l1_sx: 0.161196
    property real l1_sy: 0.379887

    property real l1_rad: (Math.PI*l1_ang)/180.0
    property real l2_rad: (Math.PI*l2_ang)/180.0
    property real l3_rad: (Math.PI*l3_ang)/180.0

    property real l1_xcos: l1_hyp*Math.cos(l1_rad) + l1_sx
    property real l1_ysin: l1_hyp*Math.sin(l1_rad) + l1_sy

    property real l2_xcos: l2_hyp*Math.cos(l2_rad) + l1_xcos
    property real l2_ysin: l2_hyp*Math.sin(l2_rad) + l1_ysin

    property real l3_xcos: l3_hyp*Math.cos(l3_rad) + l2_xcos
    property real l3_ysin: l3_hyp*Math.sin(l3_rad) + l2_ysin

    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 40
        aspectRatio: 4/3
        nearPlane : 0.1
        farPlane : 1000.0
        position: Qt.vector3d( view_x.value, view_y.value, viewCenter_z.value )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( viewCenter_x.value, 0.0, 0.0 )
    }

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: camera
                clearColor: "white"
            }
        }
    ]

    PhongMaterial {
        id: material
        ambient: Qt.rgba( 128/255, 128/255, 128/255, 1.0 )
//        diffuse: Qt.rgba( 0.1, 0.0, 0.1, 0.5 )
//        shininess: shining.value
    }

    /* Axis we are working with: (X, Z, Y), NOT (X, Y, Z) */

    /* h = 2.203604 */
    Transform {
        id: armFirstTransform
        rotation: fromEulerAngles(0, 0, l1_ang)
        translation: Qt.vector3d(l1_sx, l1_sy, -0.301277)
    }

    /* h = 3.57407 */
    Transform {
        id: armSecondTransform
        rotation: fromEulerAngles(0, 0, l2_ang)
        translation: Qt.vector3d(l1_xcos, l1_ysin, -0.016362)
    }

    /* h = 3.74676 */
    Transform {
        id: armThirdTransform
        rotation: fromEulerAngles(0, 0, l3_ang)
        translation: Qt.vector3d(l2_xcos, l2_ysin, 0.128035)
    }

    Transform {
        id: wristTransform
        rotation: fromEulerAngles(0, 0, w_ang)
        translation: Qt.vector3d(l3_xcos, l3_ysin, 0.15835)
    }

    Mesh {
        id: baseMesh
        source: "baseEntity.obj"
    }

    /* Rotation point located at (0.161196, -0.301277, 0.379887) */
    Mesh {
        id: armFirstMesh
        source: "armFirstEntity.obj"
    }

    /* Rotation point located at (2.3648, -0.016362, 0.379215) */
    Mesh {
        id: armSecondMesh
        source: "armSecondEntity.obj"
    }

    /* Rotation point located at (5.93887, 0.128035, 0.374635) */
    Mesh {
        id: armThirdMesh
        source: "armThirdEntity.obj"
    }

    /* Rotation point located at (9.68563, 0.15835, 0.37591) */
    Mesh {
        id: wristMesh
        source: "wristEntity.obj"
    }


    Entity {
        id: baseEntity
        components: [ baseMesh, material]
    }

    Entity {
        id: firstLinkEntity
        components: [ armFirstMesh, material, armFirstTransform]
    }

    Entity {
        id: secondLinkEntity
        components: [ armSecondMesh, material, armSecondTransform]
    }

    Entity {
        id: thirdLinkEntity
        components: [ armThirdMesh, material, armThirdTransform]
    }

    Entity {
        id: wristEntity
        components: [ wristMesh, material, wristTransform]
    }

}
