#include "chess.h"
#include <algorithm>
#include <ostream>
#include <sstream>
#include <iostream>

std::ostream & operator<<(std::ostream & os, Position const & p){
	os << "(" << p.X() << "," << p.Y() << ")";
	return os;
}
char Pawn::symbol() const {return 'P';}
char King::symbol() const {return 'K';}
char Queen::symbol() const {return 'Q';}
char Knight::symbol() const {return 'C';}
int Pawn::value() const {return 1;}
int King::value() const {return 20;}
int Queen::value() const {return 9;}
int Knight::value() const {return 3;}

std::string Piece::tostring() const {
	/*std::ostringstream ss;
	ss << symbol()
	 << ((colour == Colour::black) ? "B" : "N");
	//if(colour == Colour::black) ss<<"B";
	//else ss<<"W";
	 << position.X() << position.Y();
	return ss.str();*/	
	return std::string() + symbol() + ((colour == Colour::black) ? "B" : "W") +std::to_string(position.X())+std::to_string(position.Y());
}

Positions Pawn::validmoves() const {
	Positions out;
	if(clr()==Colour::black){
		if(pos().Y()==PAWN_black)
			out.push_back(Position(pos().X(),pos().Y()+(2*DIR_black)));	
		
		Position p(pos().X(),pos().Y()+(1*DIR_black));
		if(p.estvalide())
			out.push_back(p);
	} else {
		if(pos().Y()==PAWN_white)
			out.push_back(Position(pos().X(),pos().Y()+(2*DIR_white)));	
		
		Position p(pos().X(),pos().Y()+(1*DIR_white));
		if(p.estvalide())
			out.push_back(p);
	}
	return out;

}

Positions King::validmoves() const {
	Positions out;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i==0&&j==0) continue;
			Position p(pos().X()+i,pos().Y()+j);
			if(p.estvalide())
				out.push_back(p);
		}	
	}

	return out;
}

Positions Queen::validmoves() const {
	Positions out;
	for(int i=0;i<8;i++){
		Position pv(pos().X(),i);
		Position ph(i,pos().Y());
		if(pv.estvalide() && pv!=pos()) out.push_back(pv);
		if(ph.estvalide() && ph!=pos()) out.push_back(ph);
	}

	// Left Down
	for(int x=pos().X()-1,y=pos().Y()-1; x>0 && y>0; x--,y--){
		Position p(x,y);
		if(p.estvalide()) out.push_back(p);
	}
	// Left Up
	for(int x=pos().X()-1,y=pos().Y()+1; x>0 && y<8; x--,y++){
		Position p(x,y);
		if(p.estvalide()) out.push_back(p);
	}
	// Right Up
	for(int x=pos().X()+1,y=pos().Y()+1; x<8 && y<8; x++,y++){
		Position p(x,y);
		if(p.estvalide()) out.push_back(p);
	}
	// Right Down
	for(int x=pos().X()+1,y=pos().Y()-1; x<8 && y>0; x++,y--){
		Position p(x,y);
		if(p.estvalide()) out.push_back(p);
	}

	return out;
}

Positions Knight::validmoves() const {
	Positions out;
	for(coord i : {-1,1}){
		for(coord j : {-1,1}){
			Position pv(pos().X()+(3*i),pos().Y()+j);
			Position ph(pos().X()+i,pos().Y()+(3*j));
			if(pv.estvalide()) out.push_back(pv);
			if(ph.estvalide()) out.push_back(ph);
		}
	}
	return out;
}

bool Piece::validmove(Position const & p) const{
	for(auto i : validmoves())
		if(i==p) return true;
	return false;
}

bool Piece::move(Position const & p) {
	if(validmove(p)){

		position.X(p.X()); position.Y(p.Y());

		return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {

	Pawn p(Colour::black, Position(3,PAWN_black));
	King k(Colour::white, Position(4,0));
	Queen q(Colour::white, Position(3,0));
	Knight c(Colour::black, Position(0,0));

	for(auto i : k.validmoves())
		std::cout << i;
	std::cout << std::endl;

	Position test(4,1);
	std::cout << "Test Position ("<<test<<") is"
	<< ((k.validmove(test)) ? " " : "n't ") 
	<<"acceptable for "<<k.tostring()<<std::endl;

	std::cout << ((k.move(test))? "":"un") <<"successful move, now: "
	<< k.tostring()<<std::endl;
	return 0;
}