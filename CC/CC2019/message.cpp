#include "message.h"
#include <iostream>

N Message::Mcnt(0);

Message::Message(str exp, vstr dest) :
 expediteur(exp), destinataires(dest){
 	++Mcnt;
 	id=Mcnt;
 }

MessageText::MessageText(str exp, vstr dest, str t) : 
 Message(exp,dest), text(t){}

Proposition::Proposition(str exp, vstr dest, str desc, std::vector<Horaire> h) :
 Message(exp,dest), descriptif(desc), horaires(h){}

Reponse::Reponse(str exp, vstr dest, N id, Horaire h) :
 Message(exp,dest), id_proposition(id), horaire(h) {}


//Reunion Date
//bool Message::ReunionDate(N j, N m){return false;}
bool MessageText::ReunionDate(N j, N m) const {return false;}

bool Proposition::ReunionDate(N j, N m) const {
	for(auto const & i : horaires)
		if(i.Jour()==j && i.Mois()==m)
			return true;
	return false;
}

bool Reponse::ReunionDate(N j, N m) const {
	if(horaire.Jour()==j && horaire.Mois()==m) return true;
	return false;
}

//SortieFlux
void Message::SortieFlux(std::ostream & os) const{
	os << id <<" "<< expediteur << " ->";
	for(auto i : destinataires)
		os << " " << i;
}

void MessageText::SortieFlux(std::ostream & os) const {
	Message::SortieFlux(os);
	os <<" Text "<< text;
}

void Proposition::SortieFlux(std::ostream & os) const {
	Message::SortieFlux(os);
	os <<" PROPOSITION "<< descriptif <<" :";
	for(auto i : horaires)
		os <<" "<< i.ToString()
}

void Reponse::SortieFlux(std::ostream & os) const {
	Message::SortieFlux(os);
	os <<" REPONSE "<< descriptif <<" :";
	for(auto i : horaires)
		os <<" "<< i.ToString()
}