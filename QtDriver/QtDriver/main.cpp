#include "qtdriver.h"
#include <QtWidgets/QApplication>

#pragma comment(lib, "render2D.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QtDriver driver;
	driver.initialize(a);

	driver.show();

	return a.exec();
}
