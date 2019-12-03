#include "ChessBoard.h"

void ChessBoard::addPiece(std::unique_ptr<Piece> p){
	pieces.push_back(std::move(p));
}

int ChessBoard::PlayerPoints(Colour c) const {
	int out(0);
	for(auto const & i: pieces)
		if(i->clr() ==c )
			out+=i->value();
	return out;
}

bool ChessBoard::Move(Position const & src,Position const & dst){
	auto p;
	for(auto const & i: pieces)
		if(i->pos() == src )
			p=i;
}

int main(int argc, char *argv[]){
	std::unique_ptr<Piece> p1 = std::make_unique<Knight>(Colour::black,Position(2,6));
	return 0;
}