#include "questionform.hh"

questionform::questionform(question const & q)
    :QWidget(), _question(q){}

void questionform::ajouter()
{
    QString textQ = QString::fromStdString(_question.getIntitule());
    QHBoxLayout* lh = new QHBoxLayout;
    QRadioButton *radioVrai = new QRadioButton(tr("Vrai"));
    QRadioButton *radioFaux = new QRadioButton(tr("Faux"));
    lh->addWidget(radioVrai);
    lh->addWidget(radioFaux);
}
