#include <iostream>
#include <string>
#include "../TP2/sizepos.h"

//using Score = unsigned int;
typedef unsigned int Score;
//std::ostream & << (std::ostream &, Element const &);

class Element{
	Position _p;
	Size _s;
	
public:
	//Element(coord,coord,coord,coord);//
	Element(Position const &, Size const &);//

	//Getters and Setters
	Position const & getPos() const {return _p;}//
	Size const & getSize() const {return _s;}//
	void setPos(Position p) {_p=p;}//
	void setPos(coord, coord);//
	void setSize(Size s) {_s=s;}//
	void setSize(coord, coord);//

	std::string toString() const;//

	bool Inside(Position const &) const;

};




class Obstacle : public Element {
	Obstacle(Position const & p, Size const & s) : Element(p,s){};
};




class PickUp : public Element {
	Score _value;

public:
	//PickUp(Score const &, Position const &);
	PickUp(Score const &, Position const &, Size const &);

	std::string toString() const;

	Score getValue()const{return _value;};
};




class Player : public Element {
	std::string _name;
	Score _score;

public:
	//Player(std::string const &, Position const &);//
	Player(std::string const &, Position const &, Size const &);//

	std::string toString() const;//
	std::string getName()const{return _name;};
	Score getScore()const{return _score;};
	

	void pickup(PickUp const &);

};