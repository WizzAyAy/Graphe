#pragma once
#include <string>
#include <iostream>

static int compteur = 0;
class question
{
public:
    question(std::string const & i, bool const & r);
    void setReponse(bool const & r){_reponseEleve = r;}

    int getNum()const {return _num;}
    std::string getIntitule()const {return _intitule;}
    bool getReponseAttendu()const {return _reponseAttendu;}
    bool getReponseEleve()const {return _reponseEleve;}

    bool bonneReponse()const {return (_reponseAttendu == _reponseEleve);}

private:

    int _num = compteur++;
    std::string _intitule;
    bool _reponseAttendu;
    bool _reponseEleve;

};

std::ostream & operator<<(std::ostream & os, question const & q);

