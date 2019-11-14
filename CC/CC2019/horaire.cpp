#include "horaire.h"

Horaire::Horaire(N m, N j, N h) : 
 mois(m), jour(j), heur(h) {}

std::string Horaire::ToString() const {
	std::stringstream out;
	out << jour << "/" << mois << "-"<<heur<<"h.";
	return out.str();

}