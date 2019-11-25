#include "chess.h"
#include <algorithm>
#include <ostream>
#include <sstream>

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
	return std::string() + symbol() + ((colour == Colour::black) ? "B" : "N") +std::to_string(position.X())+std::to_string(position.Y());
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

	return out;
}

int main(int argc, char const *argv[]) {

	return 0;
}