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

    // Shapes entity (we create two entities because we have two objects) ***
    Qt3DCore::QEntity *shapesEntity1 = new Qt3DCore::QEntity(rootEntity);
    Qt3DCore::QEntity *shapesEntity2 = new Qt3DCore::QEntity(rootEntity);
    Qt3DCore::QEntity *shapesEntity3 = new Qt3DCore::QEntity(rootEntity);
    Qt3DCore::QEntity *shapesEntity4 = new Qt3DCore::QEntity(rootEntity);

    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // Load the front ***
    Qt3DRender::QMesh *base = new Qt3DRender::QMesh(rootEntity);
    base->setSource(QUrl("qrc:/BASE.obj"));
    // Position the front so that it is extended straight and pieced with the middle arm piece ***
    Qt3DCore::QTransform *transformbase = new Qt3DCore::QTransform;
    //play around with coordinates to line up with middle arm piece
    transformbase->setTranslation(QVector3D(0, .58, .35));
    double angle = 0;
    // rotate arm ***
    transformbase->setRotationX(angle);

    // Load the front ***
    Qt3DRender::QMesh *front = new Qt3DRender::QMesh(rootEntity);
    front->setSource(QUrl("qrc:/FRONTPART.obj"));
    // Position the front so that it is extended straight and pieced with the middle arm piece ***
    Qt3DCore::QTransform *transformfront = new Qt3DCore::QTransform;
    //play around with coordinates to line up with middle arm piece
    transformfront->setTranslation(QVector3D(0, 0.35, 0.9));
    double angle1 = -14;
    // rotate arm ***
    transformfront->setRotationX(angle1);

    // Load the MIDDLE PIECE object file ***
    Qt3DRender::QMesh *middle = new Qt3DRender::QMesh(rootEntity);
    middle->setSource(QUrl("qrc:/MIDDLEPART.obj"));
    // Position the MIDDLE PIECE at the origin and straight ***
    Qt3DCore::QTransform *transformmiddle = new Qt3DCore::QTransform;
    transformmiddle->setTranslation(QVector3D(0, 0, 0));
        //straighten out the arm ***
        double angle2 = 5;
        // rotate the arm now ***
        transformmiddle->setRotationX(angle2);
    //double angleCos = qCos(qDegreesToRadians(angle));
    //double angleSin = qSin(qDegreesToRadians(angle));
    //transformmiddle->setTranslation(QVector3D(2*angleCos, 2*angleSin, 0));
    //transformmiddle->setRotationX(90);
    //transformmiddle->setTranslation(QVector3D(0, 0, 0));


    // Load the end ***
    Qt3DRender::QMesh *end = new Qt3DRender::QMesh(rootEntity);
    end->setSource(QUrl("qrc:/ENDPART.obj"));
    // Position the end so that it is extended straight and pieced with the middle arm piece ***
    Qt3DCore::QTransform *transformend = new Qt3DCore::QTransform;
    //play around with coordinates to line up with middle arm piece
    transformend->setTranslation(QVector3D(0, -1.095, -1.087));
    double angle3 = 23;
    // rotate arm ***
    transformend->setRotationX(angle3);

    // Add all the components to each entity ***
    shapesEntity1->addComponent(middle);
    shapesEntity1->addComponent(transformmiddle);
    shapesEntity2->addComponent(end);
    shapesEntity2->addComponent(transformend);
    shapesEntity3->addComponent(front);
    shapesEntity3->addComponent(transformfront);
    shapesEntity4->addComponent(base);
    shapesEntity4->addComponent(transformbase);

    shapesEntity1->addComponent(material);
    shapesEntity2->addComponent(material);
    shapesEntity3->addComponent(material);
    shapesEntity4->addComponent(material);

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
    camera->lens()->setPerspectiveProjection(90.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    // Positions the camera on the axis
    camera->setPosition(QVector3D(3, 0, 0));
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


