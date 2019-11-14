#include "horaire.h"
#include "message.h"

void TimeTester(Horaire & H){
	std::cout << 
		H.Mois() << H.Jour() << H.Heur()<< std::endl <<
		H.ToString() << std::endl;
}

int main(int argc, char const *argv[]) {
	
	Horaire H1(11,14,15);
	Horaire H2(11,14,10);
	Horaire H3(11,15,15);

	std::vector<Horaire> Hs;
	Hs.push_back(H1);Hs.push_back(H2);Hs.push_back(H3);
	TimeTester(H1);
	TimeTester(Hs[2]);

	str foo="foo", bar="bar";
	Message M(foo,bar);


	return 0;
}