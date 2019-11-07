#include "Ensemble.h"
#include <vector>

class EnsembleVector : public Ensemble {
	std::vector<int> e;

public:
	EnsembleVector();
	EnsembleVector(Ensemble const &);
};