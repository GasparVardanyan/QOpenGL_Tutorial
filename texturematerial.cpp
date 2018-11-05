#include "texturematerial.h"

TextureMaterial::TextureMaterial (QImage image)
: texture (nullptr)
{
	init (image);
}

void TextureMaterial::initShaders (QOpenGLShaderProgram * program)
{
	QOpenGLShader vs (QOpenGLShader::Vertex, nullptr);
	vs.compileSourceCode (
        "#ifdef GL_ES\n"
        "// Set default precision to medium\n"
        "precision mediump int;\n"
        "precision mediump float;\n"
        "#endif\n"
        "\n"
        "uniform mat4 mvp_matrix;\n"
        "\n"
        "attribute vec4 a_position;\n"
        "attribute vec2 a_texcoord;\n"
        "\n"
        "varying vec2 v_texcoord;\n"
        "\n"
        "void main()\n"
        "{\n"
        "	// Calculate vertex position in screen space\n"
        "	gl_Position = mvp_matrix * a_position;\n"
        "\n"
        "	// Pass texture coordinate to fragment shader\n"
        "	// Value will be automatically interpolated to fragments inside polygon faces\n"
        "	v_texcoord = a_texcoord;\n"
        "}\n"
	);

	QOpenGLShader fs (QOpenGLShader::Fragment, nullptr);
	fs.compileSourceCode (
        "#ifdef GL_ES\n"
        "// Set default precision to medium\n"
        "precision mediump int;\n"
        "precision mediump float;\n"
        "#endif\n"
        "\n"
        "uniform sampler2D texture;\n"
        "\n"
        "varying vec2 v_texcoord;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    // Set fragment color from texture\n"
        "    gl_FragColor = texture2D(texture, v_texcoord);\n"
        "}\n"
	);

	// Compile vertex shader
    if (! program -> addShader (& vs))
		throw "";

	// Compile fragment shader
    if (! program -> addShader (& fs))
		throw "";

	// Link shader pipeline
    if (! program -> link ())
		throw "";

	// Bind shader pipeline for use
    if (! program -> bind ())
		throw "";
}

void TextureMaterial::init (QImage image)
{
	texture = new QOpenGLTexture (image.mirrored ());

	// Set nearest filtering mode for texture minification
    texture -> setMinificationFilter (QOpenGLTexture::Nearest);

	// Set bilinear filtering mode for texture magnification
    texture -> setMagnificationFilter (QOpenGLTexture::Linear);

	// Wrap texture coordinates by repeating
	// f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    texture -> setWrapMode (QOpenGLTexture::Repeat);
}

void TextureMaterial::draw (QOpenGLShaderProgram * program)
{
    texture -> bind ();
    program -> setUniformValue ("texture", 0);
}

TextureMaterial :: ~ TextureMaterial ()
{
	if (texture) delete texture;
}
