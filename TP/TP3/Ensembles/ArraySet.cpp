#include "ArraySet.h"
/*ArraySet::ArraySet(): e(nullptr) {
}*/

bool ArraySet::Contains(int x) {
	for(int i(0);i<size;i++){
		if(e[i]==x){
			return true;
		}
	}
	return false;
}

void ArraySet::VerifiedAdd(int x) {
	int * tmp = new int[size+1];
	for(int i(0);i<size;i++){
		tmp[i]=e[i];
	} tmp[size++]=x;

	delete [] e; e = tmp;
}

bool ArraySet::IsEmpty() {
	return (size==0);
}

void ArraySet::COUT() {
	for(int i(0);i<size;i++){
		std::cout << e[i];
	}
	std::cout<<std::endl;
}

void ArraySet::Remove(int x){
	for(int i(0);i<size;i++){
		if(e[i]==x){
			if(size==1){
				delete [] e;
				e = nullptr;
			} else {
				e[i]=e[size---1];
			}
		}
	}
}

void ArraySet::Empty(){
	delete [] e;
	e=nullptr;
	size=0;
}

bool ArraySet::End(Crawler &c){
	return (c.Index()>=size);
}

int ArraySet::Get(Crawler &c) {
	return e[c.Index()];
}