#include "krustkalalgo.hh"
#include <sstream>
#include <iostream>
#include <queue>
#include <iomanip>

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

void krustkalalgo::inittabstruct()
{
    for (int i = 0; i < _nbarcs; ++i) {
        _tabstruct[i].a = inf;
        _tabstruct[i].b = inf;
        _tabstruct[i].poids = inf;
    }
}

void krustkalalgo::affichertabstruct()
{

    std::cout << "a : ";
    for (int i = 0; i < _nbarcs; ++i) {
        std::cout << std::setw(4) << _tabstruct[i].a + 1;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "b : ";
    for (int i = 0; i < _nbarcs; ++i) {
        std::cout << std::setw(4) << _tabstruct[i].b + 1;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "p : ";
    for (int i = 0; i < _nbarcs; ++i) {
        std::cout << std::setw(4) << _tabstruct[i].poids;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

}

int krustkalalgo::nbarcs()
{
    int compteur(0);
    for (int i = 0; i < nbSommets; ++i) {
        for (int j = 0; j < nbSommets; ++j) {
            if(matrice[i][j] != inf)
                compteur++;
        }
    }
    return compteur;
}



void krustkalalgo::initArbre()
{
    std::vector<double> temp(nbSommets, inf);
    for(int i = 0; i<nbSommets; i++)
    {
        arbre.push_back(temp);
    }
std::cout << "Arbre initialisé. " << std::endl;
}

void krustkalalgo::krustkal()
{
    if(parcoursProfondeur())
    {
        initArbre();
        std::cout << std::endl;
        inittabstruct();
        std::cout << std::endl;

        for (int i = 0; i < nbSommets; ++i) {
            parcourus[i] = false;
        }
        tri_arcs();
        std::cout << std::endl;

    //    affichertabstruct();



        int estparcouru(0);
        int boucle(1);

        int a;
        int b;
        int poids;

        a = _tabstruct[0].a;
        b = _tabstruct[0].b;
        poids = _tabstruct[0].poids;
        arbre.at(a).at(b) = poids;




        parcourus[a] = true;
        parcourus[b] = true;
        estparcouru += 2;
        std::vector<couple> ordre;

        while(estparcouru < nbSommets)
        {
            if(!updategroupe(_tabstruct[boucle].a, _tabstruct[boucle].b))
            {
                arbre.at(_tabstruct[boucle].a).at(_tabstruct[boucle].b) = _tabstruct[boucle].poids;
                std::cout << _tabstruct[boucle].a + 1 << " --- " << _tabstruct[boucle].b + 1 << " de poids : " << _tabstruct[boucle].poids << std::endl;
                std::cout << "Les sommets parcourus : ";

                couple temp = {_tabstruct[boucle].a +1,_tabstruct[boucle].b +1};
                ordre.push_back(temp);
                affichercouple(ordre);
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
            boucle +=2;
        }
        std::cout << std::endl;
        std::cout << "Arbre couvrant minimal de Krustkal : ";
        affichercouple(ordre);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else
        std::cout << "Graphe non connexe. Ainsi Krustkal non effectué." << std::endl << std::endl;
}


bool krustkalalgo::updategroupe(int a, int b)
{
    bool A;
    bool B;
    bool lesdeuxDansungroup = false;

    for(auto x : _groupes){
        for(auto y : x){
            if(y == a) A = true;
            if(y == b) B = true;
        }
    }
    lesdeuxDansungroup = A&&B;

    for(auto& groupe : _groupes)
    {
        A = false;
        B = false;
        for(auto& entier : groupe)
        {
            if(entier==a) A = true;
            if(entier==b) B = true;

        }
        //on ajoute rien arc car ils sont dans le meme sousGroupe !
        if (A && B) {
            return true;
        }
        //on a A deja dans un groupe donc on ajoute b dans le meme groupe que a
        if(A){
            if(lesdeuxDansungroup){
                //on combine le groupe ou est a et le groupe ou est b
                for(auto it = _groupes.begin(); _groupes.end() != it; it++){
                    bool temp =  false;
                    for(auto x : *it){
                        //on est dans le groupe ou ya b (it)
                        if(x == b) temp = true;
                    }
                    for(auto x : *it){
                        //on a bien ajouter tous les element du groupe de b dans le groupe de a
                        groupe.push_back(x);
                    }
                   if(temp) _groupes.erase(it);
                   return false;
                }
            }
            else{
                //si a est dans un groupe mais pas b
                //donc on rajoute b dans le groupe de a
                groupe.push_back(b);
                return false;
            }
        }

        // on a B on ajoute a dans le groupe de b
        if(B){
            if(lesdeuxDansungroup){
                //on combine le groupe ou est b et le groupe ou est a
                for(auto it = _groupes.begin(); _groupes.end() != it; it++){
                    bool temp =  false;
                    for(auto x : *it){
                        //on est dans le groupe ou ya a (it)
                        if(x == a) temp = true;
                    }
                    for(auto x : *it){
                        //on a bien ajouter tous les element du groupe de a dans le groupe de b
                        groupe.push_back(x);
                    }
                   if(temp) _groupes.erase(it);
                   return false;
                }
            }
                else{
                    //si b est dans un groupe mais pas a
                    //donc on rajoute a dans le groupe de b
                    groupe.push_back(a);
                    return false;
            }
        }
    }
    //on a ni a ni b deja dans un groupe !
    std::vector<int> temp;
    temp.push_back(a);
    temp.push_back(b);
    _groupes.push_back(temp);
    return false;
}

void krustkalalgo::affichercouple(const std::vector<couple> c)
{
    for(auto i : c)
        std::cout << "(" << i.a << ", " << i.b << ") ";
}

bool krustkalalgo::parcoursProfondeur()
{
    for (int i=0; i<nbSommets; ++i){
      parcourus[i]=false;
    }

    explorer(0);

    int compteur(0);
    for (int i = 0; i < nbSommets; ++i) {
        if(parcourus[i] == true)
            compteur++;
    }
    std::cout << std::endl;

    return compteur == nbSommets;
}

void krustkalalgo::explorer(int s)
{
    parcourus[s]=true;
    for (int i=0;i<nbSommets;++i) {
      if (!parcourus[i] and (matrice[s][i]!=std::numeric_limits<double>::infinity()))
        explorer(i);
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
    double min;
    int k(0);
    int ii;
    int jj;
    while(k< _nbarcs)
    {
        min = inf;
        for (int i = 0; i < nbSommets; ++i) {
            for (int j = 0; j < nbSommets; ++j) {
                if (matrice[i][j] <= min) {
                    min = matrice[i][j];
                    _tabstruct[k].a = i;
                    _tabstruct[k].b = j;
                    _tabstruct[k].poids = min;
                    ii =i;
                    jj =j;
                }
            }
        }
        matrice[ii][jj] = inf;
        k++;
    }
}
