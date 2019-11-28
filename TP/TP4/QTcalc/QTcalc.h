#include <QtWidgets>

class calcul : public QWidget {
	Q_OBJECT
public:
	calcul();

	QLineEdit *operande1, *operande2;
	
	QComboBox *operateur; 
	QLabel *resultat;
	QPushButton *calculer, *quitter; 

public slots:
	void onclickcalculer();
};