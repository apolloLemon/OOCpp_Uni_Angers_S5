#pragma once
#include "include.h" //N str vstr defini ici
#include "horaire.h"

class Message {
	static N Mcnt;
	N id;
	str expediteur;
	vstr destinataires;

public:
	Message(str, vstr);

	//get
	N ID() const {return id;}
	str Expediteur() const {return expediteur;}
	vstr Destinataires() const {return destinataires;}

	virtual void SortieFlux(std::ostream & os) const;
	virtual bool ReunionDate(N,N) const =0;
};

class MessageText : public Message {
	str text;

public:
	MessageText(str, vstr, str);
	//get
	str Text() const {return text;}

	bool ReunionDate(N,N) const override;
};

class Proposition : public Message {
	str descriptif;
	std::vector<Horaire> horaires;

public:
	Proposition(str, vstr, str, std::vector<Horaire>);
	//get
	str Descriptif() const {return descriptif;}
	std::vector<Horaire> Horaires() const {return horaires;}

	bool ReunionDate(N,N) const override;
};

class Reponse : public Message {
	N id_proposition;
	Horaire horaire;

public:
	Reponse(str, vstr, N, Horaire);

	//get
	N ID_proposition() const {return id_proposition;}
	Horaire GetHoraire() const {return horaire;}

	bool ReunionDate(N,N) const override;
};

