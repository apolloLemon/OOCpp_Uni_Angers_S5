#include "gameoflife.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include "sizepos.h"

Grid::Grid(coord w, coord h) : _size(w,h), _g() {
	_g.resize(_size.GetW(), std::vector<CellState>(_size.GetH(), CellState::Dead ));
}

Grid::Grid(const Grid & g) : _size(g.GetW(), g.GetH()), _g(g.GetGrid()) {}

void Grid::Empty() {
	for(int i(0);i<_size.GetW();i++){
		for(int j(0);j<_size.GetH();j++){
			_g[i][j]=CellState::Dead;
		}
	}
}

bool Grid::isAlive(coord x, coord y) {
	return (_g[x][y]==CellState::Alive);
}

void Grid::Birth(coord x, coord y) {
	_g[x][y]=CellState::Alive;
}

void Grid::Kill(coord x, coord y) {
	_g[x][y]=CellState::Dead;
}

void Grid::Print() {
	std::system("clear");
	for(int j(0);j<_size.GetH();j++){
		for(int i(0);i<_size.GetW();i++){
			switch (_g[i][j]){
				case  CellState::Alive :
					std::cout<<"X";
					break;
				case CellState::Dead :
				default:
					std::cout<<" ";
					break;
			}
		}
		std::cout<<std::endl;
	}	
}

void Grid::AddStructure(Structure s, coord x, coord y){
	switch (s) {
		case Spinner :
			Birth(x,y); Birth(x+1,y); Birth(x+2,y);
			break;
		case Glider :
			AddStructure(Structure::Spinner, x, y);
			Birth(x+2,y+1); Birth(x+1,y+2);
			break;
		case Flower :
			AddStructure(Structure::Spinner, x+1, y);
			AddStructure(Structure::Spinner, x+1, y+2);
			Birth(x,y+1); Birth(x+2,y+1); Birth(x+4,y+1);
 			break;
		default:
		case Cross :
			AddStructure(Structure::Spinner, x, y-1);
			Birth(x+1,y); Birth(x+1,y+2);
			break;
	}
}

unsigned int Grid::Living(coord x, coord y) {
	unsigned int out(0);
	for(int i(x-1); i<=x+1 && i<_size.GetW();i++){
		if(i<0) continue;
		for(int j(y-1); j<=y+1 && j<_size.GetH();j++){
			if(j<0) continue;
			if(i==x & j==y) continue;
			if(isAlive(i,j)) out-=-1;
		}
	}
	return out;
}

void Grid::Evolve(Grid & g) {
	g = *this;
	for(int i(0); i<GetW(); i++) {
		for(int j(0); j<GetH(); j++) {
			unsigned int neighbours(Living(i,j));
			if(neighbours==3){
				g.Birth(i,j);
			} else if(neighbours<2 or neighbours>3) {
				g.Kill(i,j);
			} else continue;
		}
	}
}

int main(int argc, char const *argv[]) {
	if(argc!=6){
		std::cout << "./GoL width heigh x y structure" <<std::endl;
		return 0;
	}	
	coord w(atoi(argv[1])), h(atoi(argv[2])), x(atoi(argv[3])), y(atoi(argv[4]));
	Structure s;
	switch(atoi(argv[5])){
		case 0:
		//case 'Spinner':
			s=Structure::Spinner;
			break;
		case 1:
		//case 'Glider':
			s=Structure::Glider;
			break;
		case 2:
		//case 'Flower':
			s=Structure::Flower;
			break;
		default:
		case 3:
		//case 'Cross':
			s=Structure::Cross;
			break;
	}

	Grid g(w,h);
	g.AddStructure(s,x,y);
	g.Print();

	while(1){
		std::string s;
		std::getline(std::cin,s);
		Grid b(w,h);
		g.Evolve(b);
		b.Print();
		g=b;
	}

	return 0;
}