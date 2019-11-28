#include "QTcalc.h"

calcul::calcul () : QWidget() {
	resize(450,50);
	operande1 = new QLineEdit("",this);

	//QStringList oplist = {"+","-"};
	operateur = new QComboBox(this);
	operateur->addItem("+");
	operateur->addItem("-");
	operateur->addItem("*");
	operateur->addItem("/");

	operande2 = new QLineEdit("",this);
	calculer = new QPushButton("=",this);
	resultat = new QLabel("",this);
	quitter = new QPushButton("Quitter",this);

	QObject::connect(quitter, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(calculer, &QPushButton::clicked,this, &calcul::onclickcalculer);

	QObject::connect(operande1, &QLineEdit::textChanged,this, &calcul::onclickcalculer);
	QObject::connect(operande2, &QLineEdit::textChanged,this, &calcul::onclickcalculer);
	QObject::connect(operateur, &QComboBox::currentTextChanged,this, &calcul::onclickcalculer);

	operande1->setGeometry(10,10,70,30);
	operande2->setGeometry(150,10,70,30);
	operateur->setGeometry(90,10,70,30);
	calculer->setGeometry(230,10,70,30);
	resultat->setGeometry(300,10,70,30);
	quitter->setGeometry(370,10,70,30);
}

void calcul::onclickcalculer() {
	float res;
	float op1, op2;
	char op;

	//op1 = std::stof(operande1->text().toStdString());
	//op2 = std::stof(operande2->text().toStdString());
	auto op1t = operande1->text().toStdString();
	if(!op1t.empty()) op1 = std::stof(op1t);
	else op1=0;
	auto op2t = operande2->text().toStdString();
	if(!op2t.empty()) op2 = std::stof(op2t);
	else op2=0;

	op = operateur->currentText().toStdString()[0]; //[] => no verif != .at()
	switch(op) {
		case '+':
			res = op1 + op2; 
			break;
		case '-':
			res = op1 - op2; 
			break;
		case '*':
			res = op1 * op2; 
			break;
		case '/':
			res = op1 / op2; 
			break;
		default: 
			break;
	}
	resultat->setText(QString::number(res));
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	calcul c1;
	c1.show();

	return app.exec();
}