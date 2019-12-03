#pragma once
#include <string>
#include <list>
typedef signed short coord;

const coord PAWN_white = 1;
const int DIR_white = 1;
const coord PAWN_black = 6;
const int DIR_black = -1;

enum class Colour {
	black, white
};

class Position {
public:
	Position(coord _x,coord _y) : x(_x), y(_y){};
	Position(Position const &)=default;

	coord X() const {return x;}
	coord Y() const {return y;}
	void X(coord _x) {x=_x;}
	void Y(coord _y) {y=_y;}

	bool operator==(Position const & p) const {
		return (x==p.x) && (y==p.y);
	}

	bool operator!=(Position const & p) const {
		return !operator==(p);
	}

	bool estvalide() const {
		return ((x >= 0) && (x<8) && (y>=0) && (y<8));
	}

private:
	coord x,y;
};
typedef std::list<Position> Positions; //!!!! 

class Piece {
public:
	Piece(Colour _c, Position const & _p) : colour(_c), position(_p) {};
	virtual ~Piece()=default;
	virtual char symbol() const =0;
	virtual int value() const =0;
	virtual Positions validmoves() const =0;
	bool validmove(Position const &) const;
	bool move(Position const &);

	//virtual

	std::string tostring() const;

	Colour clr() const {return colour;}
	Position const & pos() const {return position;}
private:
	Colour colour;
	Position position;
};

class Pawn : public Piece {
public:
	Pawn(Colour _c, Position const & _p) : Piece(_c,_p) {};
	char symbol() const override;
	int value() const override;

	Positions validmoves() const override;
};

class King : public Piece {
public:
	King (Colour _c,Position const & _p) : Piece(_c,_p) {};
	char symbol() const override;
	int value() const override;

	Positions validmoves() const override;
};

class Queen : public Piece {
public:
	Queen(Colour _c,Position const & _p) : Piece(_c,_p) {};
	char symbol() const override;
	int value() const override;

	Positions validmoves() const override;
};

class Knight : public Piece {
public:
	Knight(Colour _c,Position const & _p) : Piece(_c,_p) {};
	char symbol() const override;
	int value() const override;

	Positions validmoves() const override;
};