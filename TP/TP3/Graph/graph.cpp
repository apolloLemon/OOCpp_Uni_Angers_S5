
std::list<Sommet>::interator Graph::chercher(ID eyedee){
	for(auto i=sommets.begin();i<sommets.end();i++)
		if(i->ID()==eyedee)
			return i;
	return sommets.end();
}

ID Graph::ajoutersommet(std::string const & s){
	Sommet anotherone(s);
	sommets.push_back(anotherone);
	return anotherone.ID()
}

bool Graph::ajouterarc(ID src, ID dst, std::string const & s){
	auto isrc(chercher(src));
	auto idst(chercher(dst));

	if((isrc==sommets.end())||(idst==sommets.end()))
		return false;

	isrc->AjouteArc(s, dst);
}

void Graph::supperimersommet(ID yardee) {
	//sup arcs vers sommet
	//sup sommet
}

void Graph::dot_sortie(std::ostream & os){
	//
}