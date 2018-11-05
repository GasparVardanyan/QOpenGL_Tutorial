#include "camera3d.h"

Camera3D::Camera3D ()
    : aspect (0)
    , nearClipping (0)
    , farClipping (0)
    , fov (45.0)
{}

void Camera3D::resetProjection (float fov, float aspect, float nearClipping, float farClipping)
{
    this -> fov = fov; this -> aspect = aspect; this -> nearClipping = nearClipping; this -> farClipping = farClipping;
}

void Camera3D::renderer (Object3D * container)
{
    projection.setToIdentity ();
    projection.translate (getGlobalX (), getGlobalY (), getGlobalZ ());
    projection.rotate (getGlobalRotationX (), 1.0, 0.0);
    projection.rotate (getGlobalRotationY (), 0.0, 1.0);
    projection.rotate (getGlobalRotationZ (), 0.0, 0.0, 1.0);
    projection.scale (getGlobalScaleX (), getGlobalScaleY (), getGlobalScaleZ ());
    projection.perspective (fov, aspect, nearClipping, farClipping);
    drawContainer (container);
}

void Camera3D::drawContainer (Object3D * container)
{
    container -> draw (projection);
    for (Object3D * obj : container -> children)
        renderer (obj);
}
