#include "carte.1.h"
#include <iostream>

int	main(int argc, char const *argv[])
{
	Player p1("Bobby",Position(3,3),Size(2,2));
	PickUp p2(5,Position(4,4),Size(1,1));
	std::cout << p1.toString() <<std::endl<< p2.toString()<<std::endl;

	std::cout << p1.Inside(p2.getPos()) <<std::endl;

	return 0;
}