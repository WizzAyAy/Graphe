#include <iostream>


#include "graphe.hh"
#include "maison.hh"

//ma representation est un graphe orienté de maison

int main(){

    graphe g;

    maison m1 (0,0,0);
    maison m2 (1,0,-1);
    maison m3 (0,1,-1);
    maison m4 (-1,0,1);
    maison m5 (0,-1,1);
    maison m6 (0,-1,0);

    g.ajouter(m1);
    g.ajouter(m2);
    g.ajouter(m3);
    g.ajouter(m4);
    g.ajouter(m5);
    g.ajouter(m6);

    g.ajouterArcEntre(m1, m2);
    g.ajouterArcEntre(m1, m4);
    g.ajouterArcEntre(m1, m6);
    g.ajouterArcEntre(m2, m3);
    g.ajouterArcEntre(m3, m4);
    g.ajouterArcEntre(m4, m5);
    g.ajouterArcEntre(m5, m1);
    g.ajouterArcEntre(m6, m5);

    g.afficher();

    g.Astar(m1, m5);
    return 0;
}
