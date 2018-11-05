#include "mesh.h"

Mesh::Mesh ()
    : material (nullptr)
{
}

void Mesh::draw (QMatrix4x4 projection)
{
	// Draw Material
    if (material)
    {
        material -> draw (& program);

        // Draw Transform
        {
            QMatrix4x4 transform;
            transform.translate (getGlobalX (), getGlobalY (), getGlobalZ ());
            transform.rotate (getGlobalRotationX (), 1.0, 0.0);
            transform.rotate (getGlobalRotationY (), 0.0, 1.0);
            transform.rotate (getGlobalRotationZ (), 0.0, 0.0, 1.0);
            transform.scale (getGlobalScaleX (), getGlobalScaleY (), getGlobalScaleZ ());
            program.setUniformValue("mvp_matrix", projection * transform);
        }

        // Draw Geometry
        {
            // Tell OpenGL which VBOs to use
//            geometry.vertices.bind ();
//            geometry.indices.bind ();

            // Offset for position
            int offset = 0;

            // Tell OpenGL programmable pipeline how to locate vertex position data
            int vertexLocation = program.attributeLocation ("a_position");
            program.enableAttributeArray (vertexLocation);
            program.setAttributeBuffer (vertexLocation, GL_FLOAT, offset, 3, sizeof (VertexData));

            // Offset for texture coordinate
            offset += sizeof (QVector3D);

            // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
            int texcoordLocation = program.attributeLocation ("a_texcoord");
            program.enableAttributeArray (texcoordLocation);
            program.setAttributeBuffer (texcoordLocation, GL_FLOAT, offset, 2, sizeof (VertexData));

            // Draw mesh geometry using indices from VBO 1
            glDrawElements (GL_TRIANGLE_STRIP, geometry.indices.size () / sizeof (Geometry::indicetype_t), Geometry::gl_enum_type, nullptr);
        }
    }
}

void Mesh::setMaterial (Material * material)
{
    this -> material = material;
    material -> initShaders (& program);
}
