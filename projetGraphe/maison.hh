#pragma once
#include <vector>
#include <string>
#include <ostream>


/* cette classe maison est une classe qui represente des sommmets pour un graphe*/

class maison
{
public:
    maison(int const &x, int const & y, int const & z);
    maison(maison const & m);
    bool operator==(maison const & m)const;

    static float distance(maison const & m1, maison const & m2);

    int getX()const{return _x;}
    int getY()const{return _y;}
    int getZ()const{return _z;}
    int getId()const{return _id;}
    std::vector<int> getArcSortant()const{return _arcSortant;}


    void ajouterArc(maison &m);
    void ajouterArc(int &n);

    std::string toString()const;
private:
    int _x, _y, _z;
    static int compteur;
    int _id;
    //ce vector de maison reprenste les arcs sortant de ma maison (il pointe vers les id des maisons)
    std::vector<int> _arcSortant;
};

std::ostream &operator<<(std::ostream &os, maison const & m);
