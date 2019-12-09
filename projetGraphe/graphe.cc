#include "graphe.hh"

#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>


bool graphe::ajouter(const maison &m){
    if(std::find(_lesmaisons.begin(), _lesmaisons.end(), m) == _lesmaisons.end()) {
        _lesmaisons.push_back(m);
        return true;
    }
    else return false;
}

bool graphe::ajouterArcEntre(maison &depart, maison &arrive){
    auto it = std::find(_lesmaisons.begin(), _lesmaisons.end(), depart);
    if(it != _lesmaisons.end()) {
            return ((*it).ajouterArc(arrive));
    }
    //on a pas depart dans le graphe
    else return false;
}

void graphe::afficher() const{
    for(auto sommet : _lesmaisons){
        std::cout << sommet.toString() << std::endl;
        for(auto arc : sommet.getArcSortant()){
            std::cout << "   Vers -> " << arc.toString() << std::endl;
        }
    }
}


void graphe::Astar(maison const & start, maison const & finale){
    //heuristique basée sur les distances entres les maisons a vol d'oiseau
    //chaque maison va se voir attribuer une distance a vol d'oiseau vers finale (x.distanceHeuristque)
    //chaque maison va aussi avoir, comme avec Diksjtra, un chemin plus court (x.cheminPlusCourt)
    //la maison courante sera choisit comme suit : on prend distanceHeuritique + cheminPlusCourt des "non vue"
    std::cout << std::endl;
    std::vector<AstarStruct> temp = initAstar(start, finale);
//    graphe::tousVue(temp) == false
//    graphe::donneCourant(temp) != finale.getId()
    while (graphe::tousVue(temp) == false) {
        int intcourant = graphe::donneCourant(temp);
        for(auto courant : temp){
            if(courant.mais.getId() == intcourant){
               temp.at(courant.mais.getId()-1).estVue = true;
                std::cout << "Maison courante : " << std::setprecision(2) << intcourant << std::endl;
               for(auto x2 : courant.mais.getArcSortant()){
                   float poids = maison::distance(courant.mais, x2);
                   std::cout << "   distance avec maison " << x2.getId() << " = " << poids << std::endl;
                   if(poids + temp.at(courant.mais.getId()-1).cheminPlusCourt < temp.at(x2.getId()-1).cheminPlusCourt){
                       std::cout << "   " << poids << " est plus petit que " << temp.at(x2.getId()-1).cheminPlusCourt << std::endl;
                       temp.at(x2.getId()-1).cheminPlusCourt = poids + temp.at(courant.mais.getId()-1).cheminPlusCourt;
                   }
               }
            }
        }
        std::cout << std::endl;
        std::cout << "table de l'avancement de Astar" << std::endl;
        afficherAstar(temp);
        std::cout << std::endl;
        }

        std::cout << "notre table finale est : " << std::endl;
        afficherAstar(temp);
        std::cout << std::endl;
        std::cout << "la distance minimal entre la maison " << start.getId() << " et " << " la maison " << finale.getId();
        std::cout << " est donc de " << temp.at(finale.getId()-1).cheminPlusCourt << std::endl;


}


std::vector<AstarStruct> graphe::initAstar(const maison &start, const maison &final){
    std::vector<AstarStruct> structure;
    for(auto x : _lesmaisons){
        AstarStruct temp = {maison(0,0,0),0,0,0};
        if(x == start){
            temp.cheminPlusCourt = 0;
            temp.distanceHeuristque = maison::distance(start, final);
            temp.estVue = 0;
            temp.mais = x;
        }
        else if(x == final){
           temp.cheminPlusCourt = std::numeric_limits<double>::infinity();
           temp.distanceHeuristque = 0;
           temp.estVue = 0;
           temp.mais = x;
        }
        else {
            temp.cheminPlusCourt = std::numeric_limits<double>::infinity();
            temp.distanceHeuristque = maison::distance(x, final);
            temp.estVue = 0;
            temp.mais = x;
        }
        structure.push_back(temp);
    }
    return structure;
}

void graphe::afficherAstar(const std::vector<AstarStruct> &a){
    std::cout << "id sommet          : ";
    for(auto x : a){
       std::cout << std::setw(5) << x.mais.getId();
    }
    std::cout << std::endl;

    std::cout << "est vue            : ";
    for(auto x : a){
        if(x.estVue == true){
            std::cout << "\033[1;32m";
            std::cout << std::setw(5) << "oui";
            std::cout << "\033[0m";
        }
        else{
            std::cout << "\033[1;31m";
            std::cout << std::setw(5) << "non";
            std::cout << "\033[0m";
        }
    }
    std::cout << std::endl;

    std::cout << "plus court chemin  : ";
    for(auto x : a){
       std::cout << std::setw(5) << std::setprecision(2) << x.cheminPlusCourt;
    }
    std::cout << std::endl;

    std::cout << "distance to final  : ";
    for(auto x : a){
       std::cout << std::setw(5) << std::setprecision(2) << x.distanceHeuristque;
    }
    std::cout << std::endl;
}

int graphe::donneCourant(const std::vector<AstarStruct> &a)
{
    AstarStruct courant{maison(0,0,0),0,0,0};
    for(auto x : a){
        if(x.estVue == false){
            courant = x;
            break;
        }
    }
    for(auto x : a){
        if(x.estVue == false && x.cheminPlusCourt + x.distanceHeuristque < courant.cheminPlusCourt + courant.distanceHeuristque){
            courant = x;
        }
    }
    return courant.mais.getId();
}

bool graphe::tousVue(const std::vector<AstarStruct> &a)
{
    for(auto x : a){
        if(x.estVue == false) return false;
    }
    return true;
}
