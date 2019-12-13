#pragma once
#include <vector>
#include <limits>


#include "maison.hh"

struct AstarStruct{
    maison mais;
    bool estVue;
    float cheminPlusCourt;
    float distanceHeuristque;
};

class graphe
{
public:
    graphe() = default;

    std::vector<maison> getLesMaisons()const{return _lesmaisons;}
    maison getMaison(int const & id)const;

    bool ajouter(maison const & m);
    void ajouterArcEntre(maison & depart, maison &arrive);
    void afficher()const;

    void Astar(maison const & start, const maison &finale);
    std::vector<AstarStruct> initAstar(maison const & start, maison const & final);
    static void afficherAstar(std::vector<AstarStruct> const & a);
    static int donneCourant(std::vector<AstarStruct> const & a);
    static bool tousVue(std::vector<AstarStruct> const & a);

    void arbreCouvrant();
    static void intMatrice(std::vector<std::vector<int> > &m, int const & taille);
    void creeMatrice(std::vector<std::vector<int>> & m);
    static void afficherMatrice(std::vector<std::vector<int>> const & m);
    static bool tousVue(const std::vector<bool> b);

    void parcoursProfondeur();
    void explorer(const maison &m, std::vector<bool> &parcourus);
private:
    std::vector<maison> _lesmaisons;
};

