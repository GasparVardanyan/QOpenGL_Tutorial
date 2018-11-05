#include "geometry.h"
#include <QVector3D>
#include <QVector2D>

Geometry::Geometry ()
    : indices (QOpenGLBuffer::IndexBuffer)
{
	// Generate 2 VBOs
	vertices.create ();
	indices.create ();
}

Geometry :: ~ Geometry ()
{
	vertices.destroy ();
	indices.destroy ();
}
