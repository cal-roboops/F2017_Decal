#include "mainwindow.h"
#include <QApplication>
#include "controlpanel.h"
#include <QQmlApplicationEngine>
#include <QComponent>
#include <QtMath>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <QPropertyAnimation>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/qcamera.h>
#include <Qt3DExtras/qcylindermesh.h>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QMorphPhongMaterial>
#include <Qt3DAnimation/QVertexBlendAnimation>
#include <Qt3DAnimation/QMorphTarget>
#include <Qt3DExtras/QCylinderGeometry>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

Qt3DCore::QEntity *createScene()
{
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // Shapes entity (we create two entities because we have two shapes) ***
    Qt3DCore::QEntity *shapesEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DCore::QEntity *shapesEntity2 = new Qt3DCore::QEntity(rootEntity);

    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // Load the box object file ***
    Qt3DRender::QMesh *box = new Qt3DRender::QMesh(rootEntity);
    box->setSource(QUrl("qrc:/box2.obj"));

    // Position the box at the origin ***
    Qt3DCore::QTransform *transformBox = new Qt3DCore::QTransform;
    transformBox->setTranslation(QVector3D(0, 0, 0));

    // Load the rectangle object file ***
    Qt3DRender::QMesh *rectangle = new Qt3DRender::QMesh(rootEntity);
    rectangle->setSource(QUrl("qrc:/rectangle.obj"));

    // Position the rectangle +6 on the x axis (so the box isn't covering it) ***
    Qt3DCore::QTransform *transformRect = new Qt3DCore::QTransform;
    transformRect->setTranslation(QVector3D(6, 0, 0));

    // Angle at which you want to rotate the rectangle about the box ***
    double angle = 90;

    // Operations to perform the rotation of the rectangle about the box ***
    transformRect->setRotationZ(angle);
    double angleCos = qCos(qDegreesToRadians(angle));
    double angleSin = qSin(qDegreesToRadians(angle));
    transformRect->setTranslation(QVector3D((6*angleCos), (6*angleSin), 0));

    // Add all the components to each entity ***
    shapesEntity->addComponent(box);
    shapesEntity->addComponent(transformBox);
    shapesEntity2->addComponent(rectangle);
    shapesEntity2->addComponent(transformRect);
    shapesEntity->addComponent(material);
    shapesEntity2->addComponent(material);

    return rootEntity;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Qt3DExtras::Qt3DWindow view;

    Qt3DCore::QEntity *scene = createScene();

    // Camera
    Qt3DRender::QCamera *camera = view.camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    // Positions the camera on the axis
    camera->setPosition(QVector3D(0, 0, 20));
    // Sets the camera to face the origin
    camera->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
    camController->setLinearSpeed( 10.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(camera);

    view.setRootEntity(scene);
    view.show();

    return a.exec();
}


