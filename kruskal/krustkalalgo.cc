#include "krustkalalgo.hh"
#include <sstream>
#include <iostream>
#include <queue>

double inf = std::numeric_limits<double>::infinity();


krustkalalgo::krustkalalgo()
    :nbSommets(0)
{

}

krustkalalgo::~krustkalalgo()
{

}


void krustkalalgo::initMatrice(int nbS){
  nbSommets = nbS;
  for (int i=0; i<nbSommets; ++i){
    for (int j=0; j<nbSommets; ++j){
      matrice[i][j]=std::numeric_limits<double>::infinity();
    }
  }
  std::cout << "Graphe initialisé " <<std::endl;
}

void krustkalalgo::ajoutArc(int origine,int destination, double poids){
  if (!oriente) matrice[destination-1][origine-1] = poids;
  matrice[origine-1][destination-1] = poids;
}

void krustkalalgo::inittabstruct(int nbs)
{
    nbSommets = nbs;
    for (int i = 0; i < nbSommets; ++i) {
        _tabstruct[0].a = inf;
        _tabstruct[0].b = inf;
        _tabstruct[0].poids = inf;
    }
}

bool krustkalalgo::sera_cyclique(const int &a, const int &b)
{
    int extremite = noeud_suivant(a);

    while(extremite != inf)
    {
        extremite = noeud_suivant(extremite);
        if(extremite == b)
        {
            return true;
        }
    }
    if(extremite == b)
    {
        return true;
    }
    else
        return false;
}

int krustkalalgo::noeud_suivant(const int &a) //donne le b  du noeud suivant de a
{
    int b(0);

    while(matrice[a][b] == inf)
        b++;
    if(b<=nbSommets)
        return b;
    else
        return inf;
}

void krustkalalgo::initArbre(int nbS)
{
    nbSommets = nbS;
    for (int i=0; i<nbSommets; ++i){
      for (int j=0; j<nbSommets; ++j){
        arbre[i][j]=std::numeric_limits<double>::infinity();
      }
    }
    std::cout << "Arbre initialisé " <<std::endl;
}

void krustkalalgo::krustkal()
{
    initArbre(nbSommets-1);
    inittabstruct(nbSommets-1);
    for (int i = 0; i < nbSommets; ++i) {
        parcourus[i] = false;
    }


    int estparcouru(0);
    int boucle(1);

    int a;
    int b;
    int poids;

    a = _tabstruct[0].a;
    b = _tabstruct[0].b;
    poids = _tabstruct[0].poids;
    arbre[a][b] = poids;
    std::cout << a << " --- " << b << " de poids : " << poids << std::endl;



    parcourus[a] = true;
    parcourus[b] = true;
    estparcouru += 2;

    while(estparcouru < nbSommets)
    {
        if(!sera_cyclique(_tabstruct[boucle].a, _tabstruct[boucle].b))
        {
            arbre[_tabstruct[boucle].a][_tabstruct[boucle].b] = _tabstruct[boucle].poids;
            std::cout << _tabstruct[boucle].a << " --- " << _tabstruct[boucle].b << " de poids : " << _tabstruct[boucle].poids << std::endl;
            std::cout << "Les sommets parcourus : ";
            for (int i = 0; i < nbSommets; ++i) {
                if (parcourus[i] == true)
                {
                    std::cout << i;
                }
            }
            std::cout << std::endl;

            if(parcourus[_tabstruct[boucle].b] == false)
            {
                parcourus[_tabstruct[boucle].b] = true;
                estparcouru++;
            }
            if(parcourus[_tabstruct[boucle].a] == false)
            {
                parcourus[_tabstruct[boucle].a] = true;
                estparcouru++;
            }
        }
        boucle++;
    }
}


void krustkalalgo::affichageMatrice(){
  std::vector<int> largeurColonne;
  for (int i=0; i<nbSommets; ++i){
    int max=0;
    for (int j=0; j<nbSommets; ++j){
      std::ostringstream tmp;
      tmp << matrice[j][i];
      if (tmp.tellp() > max) {max=tmp.tellp();}
    }
    largeurColonne.push_back(max);
  }
  std::cout << "    ";
  for (int i=0; i<nbSommets; ++i)
    printf("%*d ",largeurColonne[i],i+1);
  std::cout << std::endl;
  for (int i=0; i<nbSommets; ++i){
    printf("%3d|",i+1);
    for (int j=0; j<nbSommets; ++j){
      printf("%*.*g ",largeurColonne[j],largeurColonne[j],matrice[i][j]);
    }
    std::cout << std::endl;
  }
}

void krustkalalgo::tri_arcs()
{
    int min = inf;
    int k(0);
    while(k<nbSommets)
    {
        for (int i = 0; i < nbSommets; ++i) {
            for (int j = 0; j < nbSommets; ++j) {
                if (matrice[i][j] <= min) {
                    min = matrice[i][j];
    //                std::cout << i << "---" << j << " : " << min << std::endl;
                    _tabstruct[k].a = i;
                    _tabstruct[k].b = j;
                    _tabstruct[k].poids = min;
                }
            }
        }
        k++;
    }
}
