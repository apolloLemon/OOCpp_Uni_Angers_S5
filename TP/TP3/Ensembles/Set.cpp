#include "Set.h"

void Set::Add(int x){
	if(!Contains(x)){
		VerifiedAdd(x);
	}
}

Crawler Set::Start() {
	Crawler c;
	return c;
}

void Set::Next(Crawler &c){
	c.Increment();
}

void Set::Show(){
	for(Crawler p=Start();!End(p);Next(p)){
		std::cout << Get(p);
	}
	std::cout<<std::endl;
}

void Set::Union(Set &a, Set & b){
	Empty();
	for(Crawler p=Start();!a.End(p);Next(p)){
		Add(a.Get(p));
	}
	for(Crawler p=Start();!b.End(p);Next(p)){
		Add(b.Get(p));
	}
}

void Set::Intersection(Set &a, Set &b){
	Empty();
	for(Crawler p=Start(); !a.End(p); Next(p))
		if(b.Contains(a.Get(p)))
			Add(a.Get(p));
}

void Set::Difference(Set &a, Set &b){
	Empty();
	for(Crawler p=Start(); !a.End(p); Next(p))
		if(!b.Contains(a.Get(p)))
			Add(a.Get(p));
}