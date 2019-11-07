#pragma once
#include <vector>
#include "sizepos.h"

enum CellState { Dead, Alive };
enum Structure { Glider, Spinner, Flower, Cross};

class Grid {
private:
	Size _size;
	std::vector<std::vector<CellState>> _g;
public:

	Grid(coord,coord);
	Grid(const Grid &);

	coord GetW() const {return _size.GetW();}
	coord GetH() const {return _size.GetH();}
	std::vector<std::vector<CellState>> GetGrid() const {return _g;}

	void Empty();
	bool isAlive(coord,coord);
	void Birth(coord,coord);
	void Kill(coord,coord);
	void Print();


	void AddStructure(Structure, coord, coord);

	unsigned int Living(coord,coord);
	void Evolve(Grid &);

};