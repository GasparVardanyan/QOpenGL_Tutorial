#ifndef MATERIAL_H
#define MATERIAL_H

#include <QOpenGLShaderProgram>
#include <QImage>

class Material
{
public:
	Material ();
	virtual void initShaders (QOpenGLShaderProgram *) {}
	virtual void draw (QOpenGLShaderProgram *) {}
    virtual ~ Material () {}
};

#endif // MATERIAL_H
