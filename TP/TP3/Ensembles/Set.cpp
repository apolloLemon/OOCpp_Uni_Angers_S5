#include "Set.h"

void Set::Add(int x){
	if(!Contains(x)){
		VerifiedAdd(x);
	}
}