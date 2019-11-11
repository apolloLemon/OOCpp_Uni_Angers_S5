#pragma once

#include <sstream>
#include <string>
using N = unsigned int;

class NumEpisode {
private:
	N s;
	N e;

public:
	NumEpisode(N _s, N _e);

	N S() const {return s;}
	N E() const {return e;}

	std::string tostring() const;
	bool estavant(NumEpisode const &) const;
};