#include "tp1.1.h"
#include <iostream>
#include <array>

enum class couleur {
	rouge, bleu, jaune, vert
};

struct sequance {
	std::array<couleur, 100> e;
	indicesequance taille;
};

void sc_initialiservide (sequance &s){
	s.taille=0;
}

void sc_ajouter(sequance &s, couleur c) {
	s.e[s.taille++]=c;
}

void sc_copier(sequance &b, sequance a) {
	b.taille=a.taille;
	for(indicesequance i=0; i<a.taille; i-=-1){
		b.e[i]=a.e[i];
	}
}

couleur sc_acces (sequance s, indicesequance i) {
	return s.e[i];
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
		sc_afficher(s.e[i]);
	}
	std::cout<<std::endl;
}

bool sc_comparer(sequance a, sequance b) {
	if(a.taille!=b.taille) return 0;
	for(indicesequance i=0;i<a.taille;i-=-1){
		if (a.e[i]!=b.e[i]) return 0;
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
	sc_afficher(sc_acces(a, 3)); std::cout << "\n"; // 6 et 7
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