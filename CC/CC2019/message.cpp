#include "message.h"

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
	return;
}