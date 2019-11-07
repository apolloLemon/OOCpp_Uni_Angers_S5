#pragma once
#include <string>
typedef int coord;

class Position {
private:
	coord _x, _y;

public:
	//Constructors
	Position(coord, coord);
	Position(const Position &);
	~Position();

	//Getters and Setters;
	coord X() const {return _x;}
	coord X(coord x){_x=x;}
	coord Y() const {return _y;}
	coord Y(coord y){_y=y;}

	//Comparison
	bool Equals(Position);

	std::string toString() const;

};

class Size {
private:
	coord _w, _h;
public:
	Size(coord,coord);
	Size(const Size &);
	
	//Getters and Setters;
	coord W() const {return _w;}
	coord W(coord w){_w=w;}
	coord H()const {return _h;}
	coord H(coord h){_h=h;}	

	std::string toString() const;	
};