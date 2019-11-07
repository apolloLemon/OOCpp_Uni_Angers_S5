#include <iostream>
#include <vector>

#define NEWLINE std::cout<<std::endl

std::vector<int> NewVector();
void NewVector(std::vector<int> & r);

int Max_idx();
int Max_ite();
int Max_lop();

int main() {
	auto v(NewVector());
	//auto v = NewVector();

	std::vector<int> u;
	NewVector(u);

	NEWLINE;

	for(auto const& i : v)
		std::cout<<i;

	NEWLINE;

	/*std::vector<int> v1; // Construction à vide
	for (int i(0); i<10; i++)
		v1.push_back(i);
	std::vector<int> v2(v1); // Construction par recopie
	// Parcours par indice
	for (std::vector<int>::size_type i(0); i<v1.size(); ++i)
		std::cout << v1[i];
	// Parcours par itérateur
	for (std::vector<int>::const_iterator i(v1.begin()); i!=v1.end(); ++i)
		std::cout << *i;
	// Parcours et modification par itérateur
	for (std::vector<int>::iterator i(v1.begin()); i!=v1.end(); ++i)
		*i = *i +1;
	// Parcours et modification par itérateur
	for (auto i(v1.begin()); i!=v1.end(); ++i)
		*i = *i +1;
	// Parcours par boucle for d'intervalle (valeur)
	for (auto i : v1)
		std::cout << i;
	// Parcours par boucle for d'intervalle (référence)
	for (auto & i : v1)
		i *= 2;
	// Utilisation de l'opérateur d'affectation.
	v2 = v1;*/
	return 0;
}

std::vector<int> NewVector() {
	int a(0);
	std::cout<<"how many?: "; std::cin >> a;
	std::vector<int> out;
	
	while(a--) {
		int b;
		std::cout<<"gimme a number: "; std::cin >> b;
		out.push_back(b);
	}
	
	return out;
}

void NewVector(std::vector<int> & r) {
	int a(0);
	std::cout<<"how many?: "; std::cin >> a;
	while(a--) {
		int b;
		std::cout<<"gimme a number: "; std::cin >> b;
		r.push_back(b);
	}	
}

int Max_idx(std::vector<int> const & v) {
	int maxi(v[0]);
	for(std::vector<int>::size_type i=1;i<v.size();i-=-1)
		if(v[i]>maxi) maxi = v[i];
	return maxi;
}

int Max_ite(std::vector<int> const & v) {
	int maxi(v.front());
	
	//for(std::vector<int>::iterator i=v.begin();i<v.end();i-=-1) //ne Marche pas
	//for(std::vector<int>::const_iterator i=v.begin();i<v.end();i-=-1)	
	for(auto i=v.begin();i<v.end();i-=-1)
		if((*i)>maxi)
			maxi=(*i);
	return maxi;
}

int Max_lop(std::vector<int> const & v) {
	int maxi(v[0]);
	for(auto const & i : v)
		if(i>maxi)
			maxi=i;
}