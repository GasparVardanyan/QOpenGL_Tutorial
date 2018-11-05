#ifndef TEXTUREMATERIAL_H
#define TEXTUREMATERIAL_H

#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QImage>
#include <QOpenGLTexture>
#include <QMatrix4x4>
#include "material.h"

class TextureMaterial : public Material
{
public:
	QOpenGLTexture * texture;
    TextureMaterial () {}
	TextureMaterial (QImage);
	virtual void initShaders (QOpenGLShaderProgram *);
	virtual void init (QImage);
	virtual void draw (QOpenGLShaderProgram *);
	virtual ~ TextureMaterial ();
};

#endif // TEXTUREMATERIAL_H
