#include <exception>
#include <vector>
#include <string>

class IntArrayException : public std::exception {
public:
	IntArrayException(int,std::string);

	const char * what() const noexcept override;
private:
	int _i;
	std::string _errmsg;
};
class IntArray {
private:
	int _li,_hi; //lowindex, highindex
	std::vector<int> _array;

public:
	
	IntArray(int,int);
	IntArray(IntArray const &) = default;
	IntArray & operator= (IntArray const &)=default;

	int const & li() const {return _li;}
	int const & hi() const {return _hi;}

	void set(int,int);	
	int at(int) const;

	
	int & operator[](int);
	bool operator== (IntArray const &)const;
};
std::ostream & operator<<(std::ostream &, IntArray const &);