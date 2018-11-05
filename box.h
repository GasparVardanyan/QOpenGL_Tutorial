#ifndef BOX_H
#define BOX_H

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include "mesh.h"

class Box : public Mesh
{
protected:
	virtual void initGeometry ();
public:
	const float width, height, length;
	Box (float w, float h, float l);
	virtual ~ Box() {}
};

#endif // BOX_H
