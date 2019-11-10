#pragma once
#include <iostream>

class Crawler {
private:
	int i;
public:
	Crawler(): i(0){}
	int Index() const{
		return i;
	}
	void Increment(){
		i++;
	}
};

class Set {
public:
	virtual	void Empty()=0;
	virtual bool Contains(int x)=0;
	virtual void VerifiedAdd(int x)=0;
	virtual bool IsEmpty()=0;
	virtual void COUT()=0;
	virtual void Remove(int x)=0;

	void Add(int x);
	void Show();

	void Union(Set &a, Set &b);
	void Intersection(Set &a, Set &b);
	void Difference(Set &a, Set &b);

	Crawler Start();
	void Next(Crawler &c);
	virtual bool End(Crawler &c)=0;
	virtual int Get(Crawler &c)=0;
};