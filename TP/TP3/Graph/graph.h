#include "sommet.h"

class graph {
	std::list<Sommet> sommets;

	std::list<Sommet>::interator chercher(ID);

public:
	ID ajoutersommet(std::string const & s);
	bool ajouterarc(ID,ID,std::string);
	void supperimersommet(ID);
	void dot_sortie(std::ostream & os);	
};