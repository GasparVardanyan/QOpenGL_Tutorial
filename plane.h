#ifndef PLANE_H
#define PLANE_H

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include "mesh.h"

class Plane : public Mesh
{
protected:
	virtual void initGeometry ();
public:
	const float width, height;
	Plane (float w, float h);
	virtual ~ Plane () {}
};

#endif // PLANE_H
