#include "VectorSet.h"
//VectorSet::VectorSet() : e() {}

bool VectorSet::Contains(int x) {
	for(auto ei: e){
		if(ei==x) return true;
	}
	return false;
}

void VectorSet::VerifiedAdd(int x) {
	e.push_back(x);
}

bool VectorSet::IsEmpty() {
	return e.empty();
}

void VectorSet::COUT() {
	for(auto ei: e) {
		std::cout << ei;
	}
	std::cout << std::endl;
}

void VectorSet::Remove(int x){
	for(auto i=e.begin();i!=e.end();i++){
		if(*i==x){
			e.erase(i);
			return;
		}
	}
}

void VectorSet::Empty(){
	e.clear();
}

bool VectorSet::End(Crawler &c){
	return ((unsigned int)c.Index()>=e.size());
}

int VectorSet::Get(Crawler &c) {
	return e[c.Index()];
}