#include <stdio.h>
#include "VectorSet.h"
#include "ArraySet.h"

void TestSets(Set & a, Set & b) {

	printf("a.IsEmpty=%d b.IsEmpty=%d\n", a.IsEmpty(), b.IsEmpty());	


	printf("Adding 2,3,5 to a and b\n");
	a.Add(2);a.Add(3);a.Add(5);
	b.Add(2);b.Add(3);b.Add(5);

	a.COUT();
	b.COUT();

	printf("a.Contains(2)=%d b.Contains(2)=%d\n", a.Contains(2), b.Contains(2));

	printf("Removing 2\n");
	a.Remove(2);
	b.Remove(2);

	printf("a.Contains(2)=%d b.Contains(2)=%d\n", a.Contains(2), b.Contains(2));

	a.COUT();
	b.COUT();
}

int main(){

	ArraySet et = ArraySet();
	VectorSet ev = VectorSet();

	//Set Sets[2] = {et,ev};

	TestSets(et,ev);

	return 0;
}