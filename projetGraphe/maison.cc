#include "maison.hh"


#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>

int maison::compteur (1);
maison::maison(const int &x, const int &y, const int &z)
    :_x(x), _y(y), _z(z), _id(compteur++){}

maison::maison(const maison &m)
    :_x(m.getX()), _y(m.getY()), _z(m.getZ()), _id(m.getId()), _arcSortant(m.getArcSortant()){}

bool maison::operator==(const maison &m) const{
    return(getX() == m.getX() && getY() == m.getY() && getZ() == m.getZ());
}

float maison::distance(const maison &m1, const maison &m2){
    int x1 = m2.getX() - m1.getX();
    int y1 = m2.getY() - m1.getY();
    int z1 = m2.getZ() - m1.getZ();

    return sqrt(x1*x1 + y1*y1 + z1*z1);
}

void maison::ajouterArc(maison &m){
    if(std::find(_arcSortant.begin(), _arcSortant.end(), m) == _arcSortant.end()) {
        _arcSortant.push_back(m);
    }
}



std::string maison::toString() const{
return "Maison " + std::to_string(getId()) + " : (" + std::to_string(getX()) + "," + std::to_string(getY()) + "," + std::to_string(getZ()) + ")" + std::to_string(getArcSortant().size()) + "v";
}

std::ostream &operator<<(std::ostream &os, const maison &m)
{
    os << m.toString();
    return os;
}
