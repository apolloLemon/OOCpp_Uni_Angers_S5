#include <QtWidgets>
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QWidget window; window.resize(320, 200);
	QLabel* monlabel(new QLabel("Un <i>QLabel</i>.", &window));
	monlabel->move(0,0);
	QCheckBox * macheckbox(new QCheckBox("QCheckBox", &window));
	macheckbox->move(10,30);
	QPushButton* monbutton(new QPushButton("QPushButton", &window));
	monbutton->setGeometry(10,90,300,100);
	QLabel* autrelabel(new QLabel("labeldansbouton", monbutton));
	autrelabel->move(200,80);
	window.show();
	return app.exec();
}