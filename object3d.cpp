#include "object3d.h"

Object3D::Object3D ()
    : parent (nullptr)
    , x (0), y (0), z (0)
    , rotationX (0), rotationY (0), rotationZ (0)
    , scaleX (1), scaleY (1), scaleZ (1)
    , userData (nullptr)
{
}

float Object3D::getGlobalX ()
{
	float globalX = x;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalX += curr -> x;
	}
	return globalX;
}

float Object3D::getGlobalY ()
{
	float globalY = y;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalY += curr -> y;
	}
	return globalY;
}

float Object3D::getGlobalZ ()
{
	float globalZ = z;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalZ += curr -> z;
	}
	return globalZ;
}

float Object3D::getGlobalRotationX ()
{
	float globalRotationX = rotationX;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalRotationX += curr -> rotationX;
	}
	return globalRotationX;
}

float Object3D::getGlobalRotationY ()
{
	float globalRotationY = rotationY;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalRotationY += curr -> rotationY;
	}
	return globalRotationY;
}

float Object3D::getGlobalRotationZ ()
{
	float globalRotationZ = rotationZ;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalRotationZ += curr -> rotationZ;
	}
	return globalRotationZ;
}

float Object3D::getGlobalScaleX ()
{
	float globalScaleX = scaleX;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalScaleX *= curr -> scaleX;
	}
	return globalScaleX;
}

float Object3D::getGlobalScaleY ()
{
	float globalScaleY = scaleY;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalScaleY *= curr -> scaleY;
	}
	return globalScaleY;
}

float Object3D::getGlobalScaleZ ()
{
	float globalScaleZ = scaleZ;
	Object3D * curr = this;
    while (curr -> parent)
	{
        curr = curr -> parent;
        globalScaleZ *= curr -> scaleZ;
	}
	return globalScaleZ;
}

void Object3D::addChild (Object3D * obj)
{
    obj -> parent = this;
	children.push_back (obj);
}

void Object3D::addChildAt (Object3D * obj, ulong i)
{
    obj -> parent = this;
	children.insert (children.begin () + i, obj);
}

void Object3D::removeChild (Object3D * obj)
{
	for (ulong i = 0; i < children.size (); i++)
		if (children [i] == obj)
		{
            children [i] -> parent = nullptr;
            children.erase (children.begin () + i);
			break;
		}
}

void Object3D::removeChildAt (ulong i)
{
    children [i] -> parent = nullptr;
    children.erase (children.begin () + i);
}

ulong Object3D::numChildren ()
{
	return children.size ();
}
