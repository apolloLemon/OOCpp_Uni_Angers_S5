#include "numepisode.h"
#include "visionage.h"
#include <iostream>

int main() {
	
	NumEpisode a(1,1);
	NumEpisode b(1,2);
	NumEpisode d(2,1);

	std::cout << a.tostring() << std::endl;
	std::cout << a.estavant(b) << std::endl;
	std::cout << a.estavant(d) << std::endl;
	std::cout << d.estavant(b) << std::endl;

	VisionageSerie V1(191119,"Matthew Show",a);

	std::cout << V1.contientnumero(1) << std::endl;

	VisionageSerie V2(191119,"Matthew Show",b);
	VisionageSerie V3(191119,"Matthew Show",d);

	EnsembleVisionage EV;
	EV.ajoutervisionage(V1);
	EV.ajoutervisionage(V2);
	EV.ajoutervisionage(V3);

	std::cout << EV.ev[0]->tostring() << std::endl;
	return 0;
}