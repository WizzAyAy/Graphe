#include <iostream>
#include <QtWidgets>
#include "question.hh"
#include "formulaire.hh"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    formulaire f;
    question q("je suis une question", false);
    q.setReponse(false);
    question q2("je suis la question 2", true);
    q.setReponse(true);
    f.ajouterQestion(q);
    f.ajouterQestion(q2);
    f.creeForm();
    f.show();
    std::cout << q << std::endl;
    return app.exec();
}
