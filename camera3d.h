#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "object3d.h"
#include "view.h"
#include <QMatrix4x4>

class Camera3D : public Object3D
{
    QMatrix4x4 projection;
protected:
    virtual void drawContainer (Object3D * container);
public:
	float aspect;
	float nearClipping;
	float farClipping;
	float fov;
    View view;
    Camera3D ();
	virtual void resetProjection (float fov, float aspect, float nearClipping, float farClipping);
	virtual void renderer (Object3D * container);
	virtual ~ Camera3D () {}
};

#endif // CAMERA3D_H
