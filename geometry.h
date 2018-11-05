#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QOpenGLBuffer>

class Geometry
{
public:
    typedef GLushort indicetype_t;
    const static unsigned long long gl_enum_type = GL_UNSIGNED_SHORT;
	QOpenGLBuffer vertices;
	QOpenGLBuffer indices;
	Geometry ();
	virtual ~ Geometry();
};

#endif // GEOMETRY_H
