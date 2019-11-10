#pragma once
#include <iostream>

class Set {
public:
	virtual bool Contains(int x)=0;
	virtual void VerifiedAdd(int x)=0;
	virtual bool IsEmpty()=0;
	virtual void COUT()=0;
	virtual void Remove(int x)=0;

	void Add(int x);
	
};