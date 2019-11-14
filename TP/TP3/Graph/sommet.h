#include <list>
#include <string>

typedef unsigned int ID ;

struct ArcSortant {
	std::string nom;
	ID dst;
};

class Sommet {
	static NB=0;

	ID id;
	std::string nom;
	std::list<ArcSortant> arcs;

	Sommet(std::string);
	std::string Nom() const {return nom}
	ID ID() const {return id}

	void AjouteArc(std::string, ID);
	void SupprimerArc(ID);
	void SupprimerTousArcs();
	void dot_etiquette(std::ostream & os) const;
	void dot_arcssortants(std::ostream & os) const;
};