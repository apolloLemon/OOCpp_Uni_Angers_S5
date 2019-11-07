#include "sizepos.h"
#include <string>

Position::Position(coord x, coord y): _x(x), _y(y) {}
Position::Position(const Position & p):_x(p.X()), _y(p.Y()) {}
Position::~Position() {}

bool Position::Equals(Position p) {
	return (_x==p._x ) && (_y==p._y);
}

std::string Position::toString() const {
	return "x: "+std::to_string(_x)+", y: "+std::to_string(_y);
}

Size::Size(coord w, coord h): _w(w), _h(h) {}
Size::Size(const Size & s): _w(s._w), _h(s._h) {}


std::string Size::toString() const {
	return "width: "+std::to_string(_w)+", height: "+std::to_string(_h);
}