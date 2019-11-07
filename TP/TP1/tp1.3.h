enum class couleur;
//using indicesequance = size_t;
typedef unsigned int indicesequance;
struct sequance;

void sc_initialiservide(sequance &);
void sc_ajouter(sequance &,couleur);
void sc_copier(sequance &,sequance);
couleur sc_acces(sequance,indicesequance);
void sc_afficher(couleur);
void sc_afficher(sequance);
void sc_vider(sequance &);
bool sc_comparer(sequance,sequance);