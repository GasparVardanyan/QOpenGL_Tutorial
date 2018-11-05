#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <QMatrix4x4>
#include <QQuaternion>
#include <vector>
#include <iostream>

class Object3D
{
public:
	std::vector <Object3D *> children;
	Object3D * parent;
public:
	float x, y, z;
	float rotationX, rotationY, rotationZ;
	float scaleX, scaleY, scaleZ;
    void * userData;
	Object3D ();
	virtual float getGlobalX ();
	virtual float getGlobalY ();
	virtual float getGlobalZ ();
	virtual float getGlobalRotationX ();
	virtual float getGlobalRotationY ();
	virtual float getGlobalRotationZ ();
	virtual float getGlobalScaleX ();
	virtual float getGlobalScaleY ();
	virtual float getGlobalScaleZ ();
	virtual void draw (QMatrix4x4) {}
	virtual void addChild (Object3D * obj);
	virtual void addChildAt (Object3D * obj, ulong i);
	virtual void removeChild (Object3D * obj);
	virtual void removeChildAt (ulong i);
	virtual ulong numChildren ();
	virtual ~ Object3D () {}
};

#endif // OBJECT3D_H
