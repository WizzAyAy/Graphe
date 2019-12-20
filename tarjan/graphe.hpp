#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <array>
#include <limits>

const int Max = 1000;
using noeud = int;


struct infonoeud {
    noeud a;
    noeud b;
    char plus;
    char moins;
};

class Graphe{
  private : 
    std::array<std::array<double,Max>, Max> matrice;
    std::array<bool,Max> parcourus;
    int nbSommets;
    bool oriente;
    
    //----------------------------------------------------------------------------------------//

    std::vector<infonoeud> _vectinfostruct;
  public :

    Graphe();
    ~Graphe();
    void initMatrice(int nbSommets);
    int getNbSommets(int i) {return nbSommets;}
    void setOriente(bool o) {oriente = o;}
    void ajoutArc(int,int,double); 
    void affichageMatrice(); 
    void parcoursProfondeur();
    void explorer(int s);
    void parcoursLargeur();

    //________________________________________________________________________________________//

    void init_vectinfostruct();
};
