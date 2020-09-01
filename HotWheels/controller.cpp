#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), view(new MainWindow()), m(new Model()) {


    connect(m, SIGNAL(veicoloInLista()), this, SLOT(updateVeicoliTable()));
    connect(view->vistaAdd, SIGNAL(inviaStringaVeicoli(const QStringList)), this, SLOT(addVeicoloCont(const QStringList)));
    connect(view, SIGNAL(sEliminav(const int)), this, SLOT(elimina(const int)));

    view->show();
}

Controller::~Controller() {
    delete m;
}

void Controller::addVeicoloCont(const QStringList v) {
        m->addInList(v);
}

//void Controller::updateVeicoliTable() {
//    QString parolaNelCampoCerca = view->getParolaCercata();
//    view->mostraVeicoli(m->getListaVeicoli());
//    view->mostraVeicoli(m->getListaVeicoliFiltrata(parolaNelCampoCerca, indexTranslate));
//}

void Controller::updateVeicoliTable() {
    view->mostraVeicoli(m->getListaVeicoli());
}

void Controller::elimina(const int indice) {
    m->elimina(indice);
    view->veicoliTable->selectRow(indice);
    view->veicoliTable->removeRow(indice);
    view->veicoloRimossoShowBox();

    //view->nessunSelezionato();
}
