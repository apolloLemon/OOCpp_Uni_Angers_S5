#include "visionage.h"

std::string Visionage::typevisionage() const {
	if(typeid(*this)==typeid(VisionageFilm)) return "Film";
	if(typeid(*this)==typeid(VisionageSerie)) return "Episode";
	return "";
}

Visionage::Visionage(N _date, std::string _nom): 
date(_date), nom(_nom){}

VisionageFilm::VisionageFilm(N _date, std::string _nom, std::string _real): 
Visionage(_date, _nom), realisateur(_real) {}

VisionageSaga::VisionageSaga(N _date, std::string _nom, std::string _real, std::string _saga, N _e): 
VisionageFilm(_date, _nom, _real), saga(_saga), e(_e) {}

VisionageSerie::VisionageSerie(N _date, std::string _nom, NumEpisode _n): 
Visionage(_date, _nom), n(_n) {}

std::string Visionage::tostring() {
	std::stringstream out;
	out << date <<" "<< typevisionage()
		<<" "<< nom;
	return out.str();
}

std::string VisionageFilm::tostring() {
	std::stringstream out;
	out << Visionage::tostring() <<" - "<< realisateur;
	return out.str();
}

std::string VisionageSaga::tostring() {
	std::stringstream out;
	out << VisionageFilm::tostring() << " ("<<saga<<" "<<e<<")";
	return out.str();
}

std::string VisionageSerie::tostring() {
	std::stringstream out;
	out << Visionage::tostring() << " "<<n.tostring();
	return out.str();
}
//bool VisionageFilm::contientnumero(N _a){return false;}

bool VisionageSaga::contientnumero(N _a){
	if(e==_a) return true;
	return false;
}
bool VisionageSerie::contientnumero(N _a){
	if(n.S()==_a or n.E()==_a) return true;
	return false;
}

void EnsembleVisionage::ajoutervisionage(Visionage & _v) {
	ev.push_back(std::addressof(_v));
}