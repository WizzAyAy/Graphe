#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <array>
#include <limits>

const int Max = 1000;

struct dijkstra{
    int sommet;
    bool estvue;
    double plusCourt;
};

class Graphe{
  private : 
    std::array<std::array<double,Max>, Max> matrice;
    std::array<bool,Max> parcourus;
    int nbSommets;
    bool oriente;
    
  public :

    Graphe();
    ~Graphe();
    void initMatrice(int nbSommets);
    int getNbSommets(int i) {return nbSommets;}
    void setOriente(bool o) {oriente = o;}
    void ajoutArc(int,int,double); 
    void affichageMatrice(); 
    void parcoursProfondeur();
    bool explorer(int s);
    void parcoursLargeur();

    void plusCourtCheminDijkstra();
    void calulerpluscourt(std::vector<dijkstra> &v, dijkstra const& courant);
    int donneCourant(std::vector<dijkstra> &v)const;
};
