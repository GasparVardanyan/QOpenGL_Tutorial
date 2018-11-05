#include "plane.h"

Plane::Plane (float w, float h)
    : width (w)
    , height (h)
{
    initializeOpenGLFunctions ();
    initGeometry ();
}

void Plane::initGeometry ()
{
	float hw = width / 2;
	float hh = height / 2;
	VertexData vertices [] = {
        {QVector3D(-1.0f * hw, 0.0f, -1.0f * hh), QVector2D(0.0f, 0.0f)},  // v0
        {QVector3D( 1.0f * hw, 0.0f, -1.0f * hh), QVector2D(1.0f, 0.0f)}, // v1
        {QVector3D(-1.0f * hw, 0.0f,  1.0f * hh), QVector2D(0.0f, 1.0f)},  // v2
        {QVector3D( 1.0f * hw, 0.0f,  1.0f * hh), QVector2D(1.0f, 1.0f)}, // v3
	};

	Geometry::indicetype_t indices [] = {
        0,  1,  2,  3, 2, 1, 0
	};

	// Transfer vertex data to VBO 0
    geometry.vertices.bind ();
    geometry.vertices.allocate (vertices , sizeof (vertices));

	// Transfer index data to VBO 1
    geometry.indices.bind ();
//    geometry.indices.allocate (indices, sizeof (indices) * 2);
    geometry.indices.allocate (indices, sizeof (indices));
}
