#pragma once
#include "Set.h"

class ArraySet : public Set {
	//int e[];
	int * e;
	int size;

public:
	//EnsembleTableau();
	//EnsembleTableau(Ensemble const &);
	void Empty() override;
	bool Contains(int x) override;
	void VerifiedAdd(int x) override;
	bool IsEmpty() override;
	void COUT() override;
	void Remove(int x) override;

	bool End(Crawler &c) override;
	int Get(Crawler &c) override;
};