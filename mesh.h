#ifndef MESH_H
#define MESH_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>

#include "object3d.h"
#include "geometry.h"
#include "material.h"

struct VertexData;

class Mesh : public Object3D, protected QOpenGLFunctions
{
protected:
	virtual void initGeometry () {}
	struct VertexData;
public:
	Geometry geometry;
	QOpenGLShaderProgram program;
	Material * material;
	Mesh ();
    virtual void draw (QMatrix4x4 projection);
	virtual void setMaterial (Material * material);
};

struct Mesh::VertexData
{
	QVector3D position;
	QVector2D texCoord;
};

#endif // MESH_H
