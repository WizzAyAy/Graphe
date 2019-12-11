#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <array>
#include <limits>

struct structinfo
{
    int a;
    int b;
    int poids;
};


const int Max = 1000;

class krustkalalgo
{
public:
    krustkalalgo();
    ~krustkalalgo();
    void initMatrice(int nbS);
    int getNbSommets(int i) {return nbSommets;}
    void affichageMatrice();
    void ajoutArc(int,int,double);
    void setOriente(bool o) {oriente = o;}

    void tri_arcs();
    void inittabstruct (int nbs);
    bool sera_cyclique(int const & a, int const & b);
    int noeud_suivant(int const & a);
    void initArbre(int nbS);
    void krustkal();
private :
  std::array<std::array<double,Max>, Max> matrice;
  std::array<bool,Max> parcourus;
  int nbSommets;
  bool oriente;


  std::array<structinfo, Max> _tabstruct;
  std::array<std::array<double,Max>, Max> arbre;


};
