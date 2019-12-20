#pragma once
#include <vector>
#include <QtWidgets>
#include "question.hh"
#include "questionform.hh"

class formulaire : public QWidget
{
public:
    formulaire();
    void ajouterQestion(question const & q){_lesQuestions.push_back(q);}
    void creeForm();
    void ajouterQuestionForm(question const & q, QHBoxLayout *&lH);


private:
    std::vector<questionform> _lesQuestions;
};
