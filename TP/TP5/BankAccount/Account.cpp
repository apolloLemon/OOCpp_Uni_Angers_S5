#include "Account.h"

std::ostream & operator<<(std::ostream & os, Owner const & o){
	o.OutStream(os);
	return os;
};

//NAME
std::string Person::Name() const { return name;}
std::string Firm::Name() const { return name;}
std::string Couple::Name() const { return p1->Name()+" "+p2->Name;}

//OWNERTYPE
std::string Person::OwnerType() const { return Owner::ownertype::person;}
std::string Firm::OwnerType() const { return Owner::ownertype::firm;}
std::string Couple::OwnerType() const { return Owner::ownertype::couple;}

//COUPLE
std::string const & Person::Address() const { return address;}
std::string const & Firm::Address() const { return address;}
std::string const & Couple::Address() const { return p1->Address();}

std::string Owner::MaillingSticker() const {
	return Name()+" "+Address();
}

void Owner::OutSteam(std::ostream & os) const {
	os << Name() << std::endl;
	os << Address() << std::endl;
}

void Person::OutSteam(std::ostream & os) const {
	os << "Person";
	Owner::OutSteam(os);
	os << birthdate << std::endl;
}

void Firm::OutSteam(std::ostream & os) const {
	os << "Firm";
	Owner::OutSteam(os);
	os << "Manager" << (*manager) << std::endl;
}

void Couple::OutSteam(std::ostream & os) const {
	os << "Couple";
	Owner::OutSteam(os);
}