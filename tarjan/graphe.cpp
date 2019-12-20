#include "graphe.hpp"
#include <sstream>
#include <iostream>
#include <queue>
#include <limits>

double inf = std::numeric_limits<double>::infinity();

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

void Graphe::explorer(int s){
  parcourus[s]=true;
  std::cout << "S" << s+1 << " ";
  for (int i=0;i<nbSommets;++i) {
    if (!parcourus[i] and (matrice[s][i]!=std::numeric_limits<double>::infinity()))
      explorer(i);
  }   
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

void Graphe::init_vectinfostruct()
{
    for(auto i : _vectinfostruct)
    {
        i.a= inf;
        i.b = inf;
        i.moins = '-';
        i.plus = '+';
    }
}

