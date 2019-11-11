#pragma once

#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>
#include "numepisode.h"



class Visionage {
	N date;
	std::string nom;

public:
	Visionage(N,std::string);
	std::string typevisionage() const;

	virtual bool contientnumero(N)=0;
	virtual std::string tostring();
};

class VisionageFilm : public Visionage {
	std::string realisateur;
public:
	VisionageFilm(N,std::string,std::string);

	std::string tostring() override;
};

class VisionageSaga : public VisionageFilm {
	std::string saga;
	N e;
public:
	VisionageSaga(N,std::string,std::string,std::string,N);

	bool contientnumero(N) override;
	std::string tostring() override;
};

class VisionageSerie : public Visionage {
	NumEpisode n;
public:
	VisionageSerie(N,std::string,NumEpisode);

	bool contientnumero(N) override;
	std::string tostring() override;
};

class EnsembleVisionage {

public:
	std::vector<Visionage *> ev;
	void ajoutervisionage(Visionage &);
};