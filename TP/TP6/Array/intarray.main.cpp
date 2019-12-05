#include <iostream>
#include "intarray.h"

int main(int argc, char const *argv[]) {

	IntArray ia(-10,10);
	for(int i=ia.li(); i<=ia.hi(); i++)
		ia[i]=421-i;
	
	IntArray ia2(ia);
	ia[-9]=69;
	std::cout << ia.li() << ia.hi() << ia.at(-9) << (ia==ia2)<<std::endl;
	std::cout << ia2;
	//ia.at(-11);
	return 0;
}