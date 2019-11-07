enum couleur {
	rouge, bleu, vert, jaune
}

#define sequance std::vector<couleur>

#define ajouter push_back
#define taille size
#define acces at
#define vider clear

int main() {
	sequence a;
	a.ajouter(couleur::rouge);
	a.ajouter(couleur::bleu);
	a.ajouter(couleur::rouge);
	a.ajouter(couleur::vert);
	sequence b(a); // voir question 3
	/*a.afficher(a.acces(0)); std::cout << "\n";
	for (indicesequence i=0; i<a.taille(); ++i)
		a.afficher(a.acces(i));
	std::cout << "\n";*/
	a.vider();
	//std::cout << "A: "; a.afficher(std::cout); // voir question 4
	//std::cout << "B: "; b.afficher(std::cout);
	//std::cout << a.comparer(b) << "\n";
	//a.copier(b); // voir question 5
	//std::cout << a.comparer(b) << "\n";
	return 0;
}