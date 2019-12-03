#include "../../TP4/Chess/ChessPiece.h"
#include <memory>

class ChessBoard{
	std::list<std::unique_ptr<Piece>> pieces;

public:
	//ChessBoard()=default;
	//~ChessBoard()=default;
	void addPiece(std::unique_ptr<Piece>);
	int PlayerPoints(Colour) const;

	bool Move(Position const &,Position const &);
};