#ifndef CubesDemo_H
#define CubesDemo_H


#include <QOpenGLWidget>
#include <QBasicTimer>
#include "texturematerial.h"
#include "fillmaterial.h"
#include "camera3d.h"
#include "box.h"
#include "object3d.h"
#include <vector>

class CubesDemo : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
    explicit CubesDemo(QWidget * parent = nullptr);
    ~ CubesDemo();

protected:
    void timerEvent(QTimerEvent *e) override;

	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
    QBasicTimer timer;

    Object3D * rootContainer;
    std::vector <Box *> boxes;
    TextureMaterial * texturematerial1;
    TextureMaterial * texturematerial2;
    FillMaterial * fillmaterial;
    Camera3D * camera;
};

#endif // CubesDemo_H
