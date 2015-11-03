#ifndef QTDRIVER_H
#define QTDRIVER_H


#include <QtWidgets/QMainWindow>
#include "ui_qtdriver.h"

class QtDriver : public QMainWindow
{
	Q_OBJECT
private:
	QApplication* _applicationContext;
public:
	QtDriver(QWidget *parent = 0);
	~QtDriver();
	void initialize(QApplication& application);
	public slots:
	void exit();
private:
	Ui::QtDriverClass ui;
};

#endif // QTDRIVER_H
