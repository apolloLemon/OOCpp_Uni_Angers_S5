#pragma once
#include "Set.h"
#include <vector>

class VectorSet : public Set {
	std::vector<int> e;

public:
	//VectorSet();
	//VectorSet(Ensemble const &);

	bool Contains(int x) override;
	void VerifiedAdd(int x) override;
	bool IsEmpty() override;
	void COUT() override;
	void Remove(int x) override;
};