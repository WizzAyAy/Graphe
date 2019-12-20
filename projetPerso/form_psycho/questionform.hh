#pragma once
#include "question.hh"
#include <QtWidgets>

class questionform : public QWidget
{
public:
    questionform(const question &q);
    void ajouter();
private:
    question _question;
    bool _bonneReponse;
};
