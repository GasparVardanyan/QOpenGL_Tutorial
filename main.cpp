#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#ifndef QT_NO_OPENGL
#include "CubesDemo.h"
#endif

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("QOpenGL-3D-Library");
	app.setApplicationVersion("0.1");
#ifndef QT_NO_OPENGL
    CubesDemo widget;
    widget.show();
#else
	QLabel note("OpenGL Support required");
	note.show();
#endif
    return app.exec();
}
