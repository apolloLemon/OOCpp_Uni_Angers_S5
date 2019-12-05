#include "intarray.h"
#include <ostream>
/*
IntArray
*/
#define ERR_OUTBOUNDS_INDEX " index out of bounds"

std::ostream & operator<<(std::ostream & os, IntArray const & ia) {
	for(int i=ia.li();i<=ia.hi();i++)
		os << ia.at(i) << ((i==ia.hi())? "\n" : ", ");
	return os;
}

IntArray::IntArray(int li, int hi) : 
	_li(li), _hi(hi), _array(_hi-_li+1,0) {}

void IntArray::set(int i, int v){
	if(i<_li or i>_hi) 
		throw IntArrayException(i,ERR_OUTBOUNDS_INDEX);
	else _array[i-_li]=v;
}

int IntArray::at(int i) const {
	if(i<_li or i>_hi) 
		throw IntArrayException(i,ERR_OUTBOUNDS_INDEX);
	return _array.at(i-_li);	
}
int & IntArray::operator [](int i) {
	if(i<_li or i>_hi) 
		throw IntArrayException(i,ERR_OUTBOUNDS_INDEX);
	return _array[i-_li];
}
bool IntArray::operator== (IntArray const & ia) const{
	return ( (_array==ia._array) && (_li==ia._li) );
}

/*
IntArrayException
*/
IntArrayException::IntArrayException(int i, std::string errmsg) :
	_i(i),_errmsg(errmsg) {}

const char * IntArrayException::what() const noexcept {
	return _errmsg.c_str();
}