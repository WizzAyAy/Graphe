#include "graphe.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

Graphe::Graphe(): nbSommets(0), oriente(false){
}

Graphe::~Graphe(){
  
}

void Graphe::initMatrice(int nbS){
  nbSommets = nbS;
  for (int i=0; i<nbSommets; ++i){
    for (int j=0; j<nbSommets; ++j){
      matrice[i][j]=std::numeric_limits<double>::infinity();
    }
  }
  std::cout << "Graphe initialisé " <<std::endl;
}

void Graphe::ajoutArc(int origine,int destination, double poids){
  if (!oriente) matrice[destination-1][origine-1] = poids;
  matrice[origine-1][destination-1] = poids;
}

void Graphe::affichageMatrice(){
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

void Graphe::parcoursProfondeur(){
  for (int i=0; i<nbSommets; ++i){
    parcourus[i]=false;
  } 
  for (int i=0; i<nbSommets; ++i){
    if (!parcourus[i]) explorer(i);
  }
  std::cout << std::endl;

}

bool Graphe::explorer(int s){
    parcourus[s]=true;
    std::cout << "S" << s+1 << " ";
    for (int i=0;i<nbSommets;++i) {
        if (!parcourus[i] and (matrice[s][i]!=std::numeric_limits<double>::infinity())){
        explorer(i);
        }
    }
    bool temp = true;
    for(int i = 0; i < nbSommets; i++){
    temp = parcourus[i] && temp;
    }
    return temp;
}

void Graphe::parcoursLargeur(){
  for (int i=0; i<nbSommets; ++i){
    parcourus[i]=false;
  }  
  std::queue<int> file;
  file.push(0);
  parcourus[0]=true;
  while(!file.empty()){
    int s = file.front();
    std::cout << "S" << s+1 << " ";
    file.pop();
    for (int i = 0;i<nbSommets;++i){
      if (!parcourus[i] and (matrice[s][i]!=std::numeric_limits<double>::infinity())){
        file.push(i);
        parcourus[i]=true;
      }
    }
  }
  std::cout << std::endl;
}



void initDijkstra(std::vector<dijkstra> &v, int som, int entree){
    double inf = std::numeric_limits<double>::infinity();
    for(int i = 1; i < som+1; i++){
        if(i == entree){
            dijkstra temp;
            temp.estvue = false;
            temp.plusCourt = 0;
            temp.sommet = i;
            v.push_back(temp);
        }
        else{
            dijkstra temp;
            temp.estvue = false;
            temp.plusCourt = inf;
            temp.sommet = i;
            v.push_back(temp);
        }
    }

}

void afficheDijkstra(std::vector<dijkstra> const &v){
    for( auto i : v ){
        std::cout << i.estvue << " ";
    }
    std::cout << std::endl;
    for( auto i : v ){
        std::cout << i.sommet << " ";
    }
    std::cout << std::endl;
    for( auto i : v ){
        if(i.plusCourt == std::numeric_limits<double>::infinity() )
            std::cout << "i ";
        else
            std::cout << i.plusCourt << " ";
    }
     std::cout << std::endl;
}

void Graphe::calulerpluscourt(std::vector<dijkstra> &v, dijkstra const& courant){
    //les indices sont fuckeddddd
    double inf = std::numeric_limits<double>::infinity();
    for(auto &i : v){
        //prend le sommet courant
        if (i.sommet == courant.sommet){
            i.estvue = true;

            //pour tous les sommets sauf le courant
            for(int j = 1; j < nbSommets+1; j++){
                if(j == i.sommet);
                else{
                    //si le chemin entre notre sommet courant et j existe
                    if(matrice.at(courant.sommet-1).at(j-1) != inf && !(v.at(j-1).estvue)){
                    //calculechem = le plus court du courant + le poids entre le sommet courant et j
                    double poid = matrice.at(courant.sommet-1).at(j-1);
                    double calculeChem = courant.plusCourt + poid;
                    //plus cour = le plus court chemin pour j pour l'instant
                    double pluscour = v.at(j-1).plusCourt;

std::cout << "de " << j << "(indice) a ";
std::cout << i.sommet << "(courant) "  << "=(poids " <<poid << "+ courant " <<courant.plusCourt << ")";
std::cout << " plus cour de " << j << "=" << pluscour << std::endl;

                        if(  pluscour > calculeChem )
                            v.at(j-1).plusCourt = calculeChem;
                    }
                }
            }
            //on a calculer tous les plus court chemin avec notre sommet courant donc on return
            return;
        }

    }
}

int Graphe::donneCourant(std::vector<dijkstra> &v) const{
    dijkstra courant;
    for(auto i : v){
        if(i.estvue == false) {
            courant = i;
            break;
        }

    }

    int indcice = courant.sommet;
    for(auto i : v){
        if(i.estvue == false && courant.plusCourt > i.plusCourt) indcice = i.sommet;
    }
    return indcice - 1;
}


void Graphe::plusCourtCheminDijkstra(){
    std::vector<dijkstra> temp;

    initDijkstra(temp,nbSommets,1);



    afficheDijkstra(temp);
     for(int i = 0; i < nbSommets; i++){
         int courant = donneCourant(temp);
         std::cout << "le prochain sommet = " << courant+1 << std::endl;
         calulerpluscourt(temp, temp.at(courant));
         afficheDijkstra(temp);
     }

}

