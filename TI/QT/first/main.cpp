#include <QtWidgets>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QWidget window;
	window.resize(320, 240);
	window.setWindowTitle("Ma première fenêtre");
	window.show();
	return app.exec();
}