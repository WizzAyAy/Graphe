#include "formulaire.hh"
#include "questionform.hh"
#include <QtWidgets>

formulaire::formulaire(const int &i)
    :QWidget(){}



void formulaire::creeForm(){

    QVBoxLayout * layoutV = new QVBoxLayout;


    for(auto x : _lesQuestions){
        questionform qf(x);
        layoutV->addWidget(qf);
    }

}

void formulaire::ajouterQuestionForm(const question &q, QHBoxLayout* & lH){



}

