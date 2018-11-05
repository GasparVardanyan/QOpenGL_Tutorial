#include "CubesDemo.h"

CubesDemo::CubesDemo(QWidget *parent)
    : QOpenGLWidget(parent)
    , rootContainer(nullptr)
    , texturematerial1(nullptr)
    , texturematerial2(nullptr)
    , camera(nullptr)
{}

CubesDemo::~CubesDemo()
{
	// Make sure the context is current when deleting the texture
	// and the buffers.
    makeCurrent ();
    delete texturematerial1;
    delete texturematerial2;
    delete fillmaterial;
    delete rootContainer;
	delete camera;
    doneCurrent ();
}

void CubesDemo::timerEvent (QTimerEvent *)
{
        update ();
}

void CubesDemo::initializeGL ()
{
    initializeOpenGLFunctions ();

    glClearColor (0, 0, 0, 1);

	rootContainer = new Object3D;
    camera = new Camera3D;
    fillmaterial = new FillMaterial (218, 165, 32);
    texturematerial1 = new TextureMaterial (QImage (":/cube.png"));
    texturematerial2 = new TextureMaterial (QImage (":/cube1.png"));

    int c = 6;
    float space = .05f;
    float size = .1f;
    for (int i = 0; i < c; i++)
        for (int j = 0; j < c; j++)
        {
            boxes.push_back (new Box (size, size, size));
            boxes [boxes.size () - 1] -> x = i * (space + size) + size / 2 - (c * size + (c - 1) * space) / 2;
            boxes [boxes.size () - 1] -> y = j * (space + size) + size / 2 - (c * size + (c - 1) * space) / 2;
            boxes [boxes.size () - 1] -> z = -1.1f;
            boxes [boxes.size () - 1] -> setMaterial (i == j ? fillmaterial : (i % 2 == j % 2 ? texturematerial1 : texturematerial2));
            rootContainer -> addChild (boxes [boxes.size () - 1]);
        }

	// Enable depth buffer
    glEnable (GL_DEPTH_TEST);

	// Enable back face culling
    glEnable (GL_CULL_FACE);

    // Use QBasicTimer because its faster than QTimer
    timer.start (12, this);
}

void CubesDemo::resizeGL (int w, int h)
{
    camera -> resetProjection (45.0, float (w) / float (h ? h : 1), .1f, 10000.0f);
}

void CubesDemo::paintGL ()
{
	// Clear color and depth buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (Box * box : boxes)
        box -> rotationY += 1;
    camera -> renderer (rootContainer);
}
