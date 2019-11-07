#include "tp1.3.h"
#include <iostream>
#include <array>

using namespace std;

enum class couleur {
	rouge, bleu, jaune, vert
};

struct sequance {
	couleur * couleurs;
	indicesequance taille;
};

void sc_initialiservide (sequance &s){
	s.couleurs=nullptr;
	s.taille=0;
}

void sc_ajouter(sequance &s, couleur c) {
	//cout<<"ajouter";sc_afficher(c);cout<<endl;
	couleur * tmp = new couleur[s.taille+1];
	for(indicesequance i(0);i<s.taille;i++){
		tmp[i]=s.couleurs[i];
	} tmp[s.taille]=c;
	s.taille++;
	delete [] s.couleurs; s.couleurs = tmp;
	//sc_afficher(sc_acces(s,1));cout<<endl;
}

void sc_copier(sequance &b, sequance a) {
	b.taille=a.taille;
	b.couleurs = new couleur[b.taille];
	for(indicesequance i(0); i<a.taille; i-=-1){
		b.couleurs[i]=a.couleurs[i];
	}
}

couleur sc_acces (sequance s, indicesequance i) {
	return s.couleurs[i];
}

void sc_afficher(couleur c) {
	//std::cout << c;
	switch(c){
		using namespace std;
		case couleur::rouge:
			cout << "rouge";
			break;
		case couleur::bleu:
			cout << "bleu";
			break;
		case couleur::jaune:
			cout << "jaune";
			break;
		case couleur::vert:
			cout << "vert";
			break;
		default:
			break;
	}

}

void sc_vider (sequance &s) {
	sc_initialiservide(s);
}

void sc_afficher(sequance s) {
	for(indicesequance i=0;i<s.taille;i-=-1){
		sc_afficher(s.couleurs[i]);
	}
	std::cout<<std::endl;
}

bool sc_comparer(sequance a, sequance b) {
	if(a.taille!=b.taille) return 0;
	for(indicesequance i=0;i<a.taille;i-=-1){
		if (a.couleurs[i]!=b.couleurs[i]) return 0;
	}
	return 1;
}

int main() {
	sequance a, b;
	sc_initialiservide(a); // 3
	sc_initialiservide(b);
	sc_ajouter(a, couleur::rouge); // 4
	sc_ajouter(a, couleur::bleu);
	sc_ajouter(a, couleur::rouge);
	sc_ajouter(a, couleur::vert);
	sc_copier(b, a); // Copie a dans b // 5
	sc_afficher(sc_acces(a, 4)); std::cout << "\n"; // 6 et 7
	for (indicesequance i=0; i<a.taille; ++i){
		sc_afficher(sc_acces(a,i));
	}std::cout<<std::endl;
	sc_vider(a); // 8
	std::cout << "A: "; sc_afficher(a); // 9
	std::cout << "B: "; sc_afficher(b);
	std::cout << sc_comparer(a,b) << "\n"; // 10
	sc_copier(a,b);
	std::cout << sc_comparer(a,b) << "\n";
	return 0;
}