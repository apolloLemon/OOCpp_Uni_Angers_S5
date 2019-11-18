#include "carte.3.h"

Map::Map(Size const & s) : size(s) {}

void Map::AddPlayer(Player const & p){
	players.push_back(p);
}

void Map::AddObstacle(Obstacle const & p){
	obstacles.push_back(p);
}

void Map::AddPickUp(PickUp const & p){
	pickups.push_back(p);
}

void Map::Draw() const{
	//
}

bool Map::Collision1D(int a1, int b1, int a2, int b2) const{
	return ((a1<a2 && a2<b1) || (a1<b2 && b2<b1));
}

bool Map::Collision(Element const & p1, Element const & p2) const {
	coord a1=p1.getPos().X(),
	 b1=a1+p1.getSize().W(),
	 a2=p2.getPos().X(),
	 b2=a2+p2.getSize().W();
	
	coord va1=p1.getPos().Y(),
	 vb1=va1+p1.getSize().H(),
	 va2=p2.getPos().Y(),
	 vb2=va2+p2.getSize().H();
	
	return (
		Collision1D(a1,b1,a2,b2)
		and Collision1D(va1,vb1,va2,vb2)
		);
}