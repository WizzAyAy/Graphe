#include <iostream>


#include "graphe.hh"
#include "maison.hh"

//ma representation est un graphe orienté de maison


int main(){

    graphe g;

//    maison m1 (0,0,0);
//    maison m2 (1,0,-1);
//    maison m3 (0,1,-1);
//    maison m4 (-1,0,1);
//    maison m5 (0,-1,1);
//    maison m6 (0,-1,0);

//    g.ajouter(m1);
//    g.ajouter(m2);
//    g.ajouter(m3);
//    g.ajouter(m4);
//    g.ajouter(m5);
//    g.ajouter(m6);

//    g.ajouterArcEntre(m1, m2);
//    g.ajouterArcEntre(m1, m4);
//    g.ajouterArcEntre(m1, m6);
//    g.ajouterArcEntre(m2, m3);
//    g.ajouterArcEntre(m3, m4);
//    g.ajouterArcEntre(m4, m5);
//    g.ajouterArcEntre(m5, m1);
//    g.ajouterArcEntre(m6, m5);

//    g.afficher();

//    g.Astar(m1, m5);

    maison A(0,0,1);
    maison B(0,0,2);
    maison C(0,0,3);
    maison D(0,0,4);
    maison E(0,0,5);
    maison F(0,0,6);
    maison G(0,0,7);

    g.ajouter(A); g.ajouter(B); g.ajouter(C); g.ajouter(D); g.ajouter(E); g.ajouter(F); g.ajouter(G);

    g.ajouterArcEntre(A,B);
    g.ajouterArcEntre(A,C);
    g.ajouterArcEntre(A,E);
    g.ajouterArcEntre(B,F);
    g.ajouterArcEntre(B,D);
    g.ajouterArcEntre(C,G);
    g.ajouterArcEntre(F,E);

    for(auto x : B.getArcSortant()){
        std::cout << x.toString() << std::endl;
    }

    g.parcoursProfondeur();
    return 0;
}
