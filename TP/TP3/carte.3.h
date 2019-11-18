#pragma once
#include <list>
#include "carte.1.h"

enum class Direction {
	N, S, E, W
};

class Map {
	Size size;

	std::list<Player> players;
	std::list<Obstacle> obstacles;
	std::list<PickUp> pickups;

public:
	Map(Size const &);

	//set
	void AddPlayer(Player const &);
	void AddObstacle(Obstacle const &);
	void AddPickUp(PickUp const &);
	

	void Draw() const;

	bool Collision1D(int,int,int,int) const;
	bool Collision(Element const &, Element const &) const;

	void Move(Player &, Direction); 
};