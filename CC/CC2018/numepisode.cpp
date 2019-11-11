#include "numepisode.h"

NumEpisode::NumEpisode(N _s, N _e) {
	s=_s;
	e=_e;
}

std::string NumEpisode::tostring() const{
	std::stringstream out;
	out << "S" << s << "E" << e;
	return out.str();
	//return sprintf("S%dE%d",s,e);
}

bool NumEpisode::estavant(NumEpisode const & autre) const{
	if(s<autre.S()) return true;
	if(s==autre.S() && e<autre.E()) return true;
	return false;
}