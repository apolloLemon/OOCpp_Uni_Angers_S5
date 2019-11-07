#include "carte.1.h"
#include <sstream>

//Element::Element(coord x, coord y, coord w, coord h): 
//_p(x,y), _s(w,h) {}

Element::Element(Position const & p, Size const & s): 
_p(p), _s(s) {}


Player::Player(std::string const & str, Position const & p, Size const & s): _name(str), _score(0), Element(p,s) {}

//Player::Player(std::string const & s, Position const & p): 
//Player(s,p, Size(1,1)) {}

PickUp::PickUp(Score const & v, Position const & p, Size const & s): 
_value(v), Element(p,s) {}
//PickUp::PickUp(Score const & s, Position const & p):
//PickUp(s,p,Size(1,1)) {}


void Element::setPos(coord x, coord y) {
	_p.X(x);_p.Y(y);
}
void Element::setSize(coord w, coord h) {
	_s.W(w);_s.H(h);
}



std::string Element::toString() const {
	std::ostringstream out;
	out << _p.toString() << " " << _s.toString();
	return out.str();
}

std::string Player::toString() const {
	std::ostringstream out;
	out << Element::toString()<<" "<<_name<<" score: "<<_score;
	return out.str();

}

std::string PickUp::toString() const {
	std::ostringstream out;
	out << Element::toString()<<" score value: "<<_value;
	return out.str();
}

bool Element::Inside(Position const & p) const {
	return 
		((p.X() >= _p.X()) && (p.X() < (_p.X()+_s.W())))
	&&  ((p.Y() >= _p.Y()) && (p.Y() < (_p.Y()+_s.H())))
	;
}

void Player::pickup(PickUp const & p){
	_score+=p.getValue();
	//delete p; //on n'as pas le droit de le detruir si on l'as pas cree'
}