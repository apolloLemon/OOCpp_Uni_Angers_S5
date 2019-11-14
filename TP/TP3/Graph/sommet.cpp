
Sommet::Sommet(std::string n) : nom(n) {
	id = ++NB;
}

void Sommet::AjouteArc(std::string str, ID eyedee ) {
	ArcSortant whatwereherefor(str,eyedee);
	arcs.push_back(whatwereherefor);
}

void Sommet::SupprimerArc(ID yardee){
	for (auto i=arcs.begin();i<arcs.end();i++)
		if(i->ID()==yardee)
			arcs.erase(i);
}

void Sommet::SupprimerTousArcs(){
	arcs.erase(arcs.begin(), arcs.end());
}


void Sommet::dot_etiquette(std::ostream & os) const {
	os << id << "[label=\""<<nom<< "\"] ;\n";
}

void Sommet::dot_arcsortants(std::ostream & os) const {
	for (auto const & i : arcs){
		os << "c" << id << " -> c" << i.dst << " ";
		if(!i.nom.empty())
			os << "[label=\""<<i.nom<< "\"] ";
		os << ";\n";
	}
}