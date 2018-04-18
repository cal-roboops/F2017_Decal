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

    property real bicep_hyp: 2.203604
    property real biform_hyp: 3.57407
    property real forearm_hyp: 3.74676

    property real base_sx: 0.161196
    property real base_sy: 0.379887

    property real bicep_rad: (Math.PI*bicep_ang)/180.0
    property real biform_rad: (Math.PI*biform_ang)/180.0
    property real forearm_rad: (Math.PI*forearm_ang)/180.0

    property real bicep_xcos: bicep_hyp*Math.cos(bicep_rad) + base_sx
    property real bicep_ysin: bicep_hyp*Math.sin(bicep_rad) + base_sy

    property real biform_xcos: biform_hyp*Math.cos(biform_rad) + bicep_xcos
    property real biform_ysin: biform_hyp*Math.sin(biform_rad) + bicep_ysin

    property real forearm_xcos: forearm_hyp*Math.cos(forearm_rad) + biform_xcos
    property real forearm_ysin: forearm_hyp*Math.sin(forearm_rad) + biform_ysin

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
        id: bicepTransform
        rotation: fromEulerAngles(0, 0, bicep_ang)
        translation: Qt.vector3d(base_sx, base_sy, -0.301277)
    }

    /* h = 3.57407 */
    Transform {
        id: biformTransform
        rotation: fromEulerAngles(0, 0, biform_ang)
        translation: Qt.vector3d(bicep_xcos, bicep_ysin, -0.016362)
    }

    /* h = 3.74676 */
    Transform {
        id: forearmTransform
        rotation: fromEulerAngles(0, 0, forearm_ang)
        translation: Qt.vector3d(biform_xcos, biform_ysin, 0.128035)
    }

    Transform {
        id: wristTransform
        rotation: fromEulerAngles(0, 0, wrist_ang)
        translation: Qt.vector3d(forearm_xcos, forearm_ysin, 0.15835)
    }

    Mesh {
        id: baseMesh
        source: "baseEntity.obj"
    }

    /* Rotation point located at (0.161196, -0.301277, 0.379887) */
    Mesh {
        id: bicepMesh
        source: "bicepEntity.obj"
    }

    /* Rotation point located at (2.3648, -0.016362, 0.379215) */
    Mesh {
        id: biformMesh
        source: "biformEntity.obj"
    }

    /* Rotation point located at (5.93887, 0.128035, 0.374635) */
    Mesh {
        id: forearmMesh
        source: "forearmEntity.obj"
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
        components: [ bicepMesh, material, bicepTransform]
    }

    Entity {
        id: secondLinkEntity
        components: [ biformMesh, material, biformTransform]
    }

    Entity {
        id: thirdLinkEntity
        components: [ forearmMesh, material, forearmTransform]
    }

    Entity {
        id: wristEntity
        components: [ wristMesh, material, wristTransform]
    }

}
