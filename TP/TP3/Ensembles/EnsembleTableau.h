#include "Ensemble.h"

class EnsembleTableau : public Ensemble {
	int e[];

public:
	EnsembleTableau();
	EnsembleTableau(Ensemble const &);
};