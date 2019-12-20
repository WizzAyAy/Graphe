#include "question.hh"

question::question(const std::string &i, const bool &r)
    :_intitule(i),_reponseAttendu(r){}

std::ostream &operator<<(std::ostream &os, const question &q){
    os << q.getNum() << " Question : " << q.getIntitule() << " (" << q.getReponseAttendu() << "->" << q.getReponseEleve() << ")";
    return os;
}
