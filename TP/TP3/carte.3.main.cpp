#include "carte.3.h"

int main(int argc, char const *argv[]) {
	
	Size mapSize(20,20);
	Map m(mapSize);

	Size playerSize(1,2);
	Position playerPos(3,3);
	Player p1("P1", PlayerPos, playerSize);

		 
	return 0;
}