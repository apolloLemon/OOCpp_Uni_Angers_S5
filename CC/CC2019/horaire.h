#pragma once
#include "include.h" //N definit ici

class Horaire {

	N mois;
	N jour;
	N heur;

public:
	Horaire(N,N,N);
	//Horaire()=0;

	//get
	N Mois() const { return mois;}
	N Jour() const { return jour;}
	N Heur() const { return heur;}

	str ToString() const;
};