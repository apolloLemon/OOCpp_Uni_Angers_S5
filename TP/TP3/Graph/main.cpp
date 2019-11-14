#include "graphe.hh"
#include <fstream>

void sauvergraphe(graphe const & g, std::string const & nomfichier) {
	std::ofstream f(nomfichier);
	g.dot_sortie(f);
}

int main() {
	graphe g;
	auto paris(g.ajoutersommet("Paris"));
	auto angers(g.ajoutersommet("Angers"));
	auto nantes(g.ajoutersommet("Nantes"));
	g.ajouterarc(angers, nantes, "Bus");
	g.ajouterarc(nantes, angers, "Bus");
	g.ajouterarc(angers, paris, "Train");
	g.ajouterarc(paris, nantes, "Avion");
	sauvergraphe(g, "tout.dot");
	g.supprimersommet(angers);
	sauvergraphe(g, "sansangers.dot");
	return 0;
}