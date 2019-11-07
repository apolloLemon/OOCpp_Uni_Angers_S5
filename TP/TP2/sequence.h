#pragma once
#include <cstddef>
#include <iostream>

enum class couleur {
	rouge, bleu, vert, jaune
};


using indicesequence = std::size_t;

class sequence {
private:
	couleur * _couleurs;
	indicesequence _taille;	

public:
	sequence();
	sequence(couleur *, indicesequence);
	sequence(const sequence &);
	~sequence();

	//Gettersetters
	indicesequence taille();
	

	void ajouter(couleur);
	void copier(const sequence &);
	couleur acces(indicesequence i) const;
	void vider();
	void afficher(couleur) const;
	void afficher(couleur, std::ostream &) const;
	void afficher(std::ostream &) const;
	bool comparer(const sequence &);

};