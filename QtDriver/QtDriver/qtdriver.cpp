#include "qtdriver.h"
#include "qopenglcontext.h"
#include "game_core.h"
#include "qt_render_context.h"
QtDriver::QtDriver(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtDriver::~QtDriver()
{

}

void QtDriver::exit()
{
	this->close();
	_applicationContext->quit();
}

void QtDriver::initialize(QApplication& application)
{
	_applicationContext = &application;
	Render2D::GameCore::execute(new QtRenderContext);

	//ui.openGLWidget->context->doneCurrent();
	/*
	QOpenGLContext* gl_context = ui.openGLWidget->context();

	QSurfaceFormat format;
	format.setVersion(3, 0);
	format.setSamples(4);
	format.setProfile(QSurfaceFormat::NoProfile);
	format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	gl_context->setFormat(format);*/
	QObject::connect(ui.exit_button, SIGNAL(clicked()), this, SLOT(exit()));
}
