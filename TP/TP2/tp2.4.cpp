#include <cstddef>
#include <iostream>
#include <vector>

enum class couleur {
	rouge, bleu, vert, jaune
};


using indicesequence = std::size_t;

class sequence {
private:
	std::vector<couleur> v;	

public:
	//constructeurs et destructeur par default

	int taille(){
		return v.size();
	}

	void ajouter(couleur const& c) {
		v.push_back(c);
	}

	void copier(const sequence & s) {
		v=s.v;
	}

	couleur acces(indicesequence i) const{
		return v[i];
	}
	
	void vider(){
		v.clear();
	}
	
	void afficher(couleur c) const {
		afficher(c,std::cout);
	}

	void afficher(couleur c, std::ostream & os) const{
		switch(c) {
			case couleur::rouge :
				os << "Rouge";
				break;
			case couleur::vert :
				os << "Vert";
				break;
			case couleur::bleu :
				os << "Bleu";
				break;
			case couleur::jaune :
			default:
				os << "Jaune";
				break;
		}
	}

	void afficher(std::ostream & os) const{
		for(indicesequence i(0); i<v.size(); i++){
			afficher(acces(i));
			os << " ";
		}
		os << "\n";
}
	bool comparer(const sequence & s) {
		return (v==s.v);
	}

};

int main() {
	sequence a;
	a.ajouter(couleur::rouge);
	a.ajouter(couleur::bleu);
	a.ajouter(couleur::rouge);
	a.ajouter(couleur::vert);
	sequence b(a); // voir question 3
	a.afficher(a.acces(0)); std::cout << "\n";
	for (indicesequence i=0; i<a.taille(); ++i)
		a.afficher(a.acces(i));
	std::cout << "\n";
	a.vider();
	std::cout << "A: "; a.afficher(std::cout); // voir question 4
	std::cout << "B: "; b.afficher(std::cout);
	std::cout << a.comparer(b) << "\n";
	a.copier(b); // voir question 5
	std::cout << a.comparer(b) << "\n";
	return 0;
}