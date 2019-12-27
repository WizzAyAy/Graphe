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
    bool toutestparcouru(false);
    jointure_a = 0;
  for (int i=0; i<nbSommets; ++i){
    parcourus[i]=false;
  } 
  for (int i = 0; i < nbSommets; ++i) {
      if(!parcourus[i])
      {
          jointure_b = i;
          if (i>0) {
            matrice [jointure_a][jointure_b] = 1;
            std::cout << std::endl << "Jointure entre : " << jointure_a +1 << ", " << jointure_b +1 << std::endl;
          }
          explorer(i);
      }


  }
  std::cout << std::endl;


  std::cout << std::endl;

}

void Graphe::explorer(int s){
  parcourus[s]=true;
  _vectsommet.push_back(s);

  bool onarretetout(false);
  bool toutestparcouru(false);
  int compteur(0);
  for (int i = 0; i < nbSommets; ++i) {
      if (parcourus[i] == true)
          compteur++;
  }
  if(compteur == nbSommets)
      toutestparcouru = true;

  std::cout << std::endl;
  for (int i = 0; i < nbSommets; ++i) {
      std::cout << i + 1<< " ";
  }

  std::cout << std::endl;

  for (int i = 0; i < nbSommets; ++i) {
      std::cout << parcourus[i] << " ";
  }
  std::cout << std::endl;


  infonoeud in;
  _vectinfostruct.push_back(in);
  _vectinfostruct.at(_vectinfostruct.size()-1).sommet = s;
  _vectinfostruct.at(_vectinfostruct.size()-1).v_num = s;
  _vectinfostruct.at(_vectinfostruct.size()-1).v_num_accessible = s;

  std::cout << std::endl << "sommet : " << _vectinfostruct.at(_vectinfostruct.size()-1).sommet  + 1 << ", ";
  std::cout << "vnum : " << _vectinfostruct.at(_vectinfostruct.size()-1).v_num  + 1 << ", ";
  std::cout << "vnum accessible : " << _vectinfostruct.at(_vectinfostruct.size()-1).v_num_accessible  + 1 << ", ";


  std::cout << std::endl << "=== S" << s+1 << " " << std::endl;
  std::cout << "==========================================================" << std::endl;
  for (int i=0;i<nbSommets;++i) {                                                   //A CHANGER POUR ORIENTE
       if((matrice[s][i]!=std::numeric_limits<double>::infinity())) {
           compteur = 0;
           for (int i = 0; i < nbSommets; ++i) {
               if (parcourus[i] == true)
                   compteur++;
           }
           if(compteur == nbSommets)
               toutestparcouru = true;

            if (!parcourus[i]) {
                if((matrice[s][i]!=std::numeric_limits<double>::infinity()))
                     explorer(i);
                else
                     std::cout << std::endl << "On a un inf ici : "<< i << std::endl;
            }
            else if (onarretetout == true)
                return;
            else if (toutestparcouru == true)
            {
                std::cout << std::endl << "Parcours de graphe terminé " << std::endl;
                onarretetout = true;
            }
            else {
                compteur = 0;
                for (int j = 0; j < nbSommets; ++j) {
                    if (parcourus[j] == true)
                        compteur++;
                }
                if(compteur == nbSommets)
                    toutestparcouru = true;

                if(!toutestparcouru) {
                    std::cout << std::endl <<"------- > On a un cycle ici : " << s + 1 << ", " << i + 1 << std::endl; //s = 2 & i = 4
                    std::cout << std::endl;


                    for (int k = i; k >= s; --k) {

                        _vectinfostruct.at(k).v_num_accessible = _vectinfostruct.at(s).v_num_accessible;

                        _element_partition.push_back(_vectinfostruct.at(k));
                    }
                    _partition.push_back(_element_partition);

                    for(auto i : _partition)
                    {
                        for(auto j : _element_partition)
                        {
                            std::cout << "- " << j.v_num +1 << "." << j.v_num_accessible +1 << " -";
                        }
                        break;
                        std::cout << std::endl;
                    }



                    _element_partition.clear();
                    std::cout << std::endl;

                    jointure_a = s;
                }
                else
                    return;
            }
       }

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

void Graphe::tarjan()
{
    parcoursProfondeur();
    bool connexe(false);
    for(auto i : _partition)
    {
        for(auto j : i)
        {
            std::cout << "- " << j.v_num +1 << "." << j.v_num_accessible +1 << " -";
        }
        std::cout << std::endl << std::endl;
    }

    std::cout << "_-_-_-_ Les sommets parcourus dans l'ordre : ";
    for(int i = 0; i <nbSommets; i++)
        std::cout << "  " << _vectsommet.at(i) + 1 << "  ";
    std::cout << std::endl << std::endl << std::endl;
}



