#include "sequence.h"
#include <iostream>

sequence::sequence(): 
_couleurs(nullptr), _taille(0) {}

sequence::sequence(couleur * c, indicesequence i): 
_couleurs(c),_taille(0) {}

sequence::sequence(const sequence & s) : 
_taille(s._taille), 
_couleurs( (s._taille==0) ? nullptr : new couleur[s._taille]){
	for(indicesequence i(0); i<_taille; i++){
		_couleurs[i]=s._couleurs[i];
	}
}
sequence::~sequence() {
	delete [] _couleurs;
}

indicesequence sequence::taille(){
	return _taille;
}
void sequence::ajouter(couleur c){
	couleur * tmp = new couleur[_taille+1];
	
	for(indicesequence i(0);i<_taille;i++){
		tmp[i]=_couleurs[i];
	} tmp[_taille++]=c;

	delete [] _couleurs; _couleurs = tmp;
}

void sequence::copier(const sequence & s){
	if (s._taille!=_taille) {
		_taille=s._taille;
		delete [] _couleurs;
		if(_taille!=0)
			_couleurs = new couleur[_taille];
		else _couleurs = nullptr;
	}
	for(indicesequence i(0); i<_taille;i++){
		_couleurs[i]=s._couleurs[i];
	}
}

couleur sequence::acces(indicesequence i) const {
	return _couleurs[i];
}

void sequence::vider(){
	_taille=0;
	delete [] _couleurs;
	_couleurs = nullptr; //explicitement vider?
}

/*void sequence::afficher(couleur c) const{
	switch(c) {
		case couleur::Rouge :
			cout << "Rouge";
			break;
		case couleur::Vert :
			cout << "Vert";
			break;
		case couleur::Bleu :
			cout << "Bleu";
			break;
		case couleur::Jaune :
		default:
			cout << "Jaune";
			break;
	}
}*/ //remplace' par \/\/\/\/\/\/\/\/\/\/

void sequence::afficher(couleur c) const {
	afficher(c,std::cout);
}

void sequence::afficher(couleur c, std::ostream & os) const{
	switch(c) {
		case couleur::rouge :
			os << "Rouge";
			break;
		case couleur::vert :
			os << "Vert";
			break;
		case couleur::bleu :
			os << "Bleu";
			break;
		case couleur::jaune :
		default:
			os << "Jaune";
			break;
	}
}

void sequence::afficher(std::ostream & os) const{
	for(indicesequence i(0); i<_taille; i++){
		afficher(acces(i));
		os << " ";
	}
	os << "\n";
}


bool sequence::comparer(const sequence &){

}