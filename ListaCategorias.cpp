#include "ListaCategorias.h"
#include <iostream>
#include <cstring>

using namespace std;
ListaCategorias::ListaCategorias() {
    this->cab = nullptr;
    this->largo = 0;
}

ListaCategorias::~ListaCategorias() {
}

Categoria *ListaCategorias::getCab() {
    return this->cab;
}

int ListaCategorias::getLargo() {
    return this->largo;
}

void ListaCategorias::setCab(Categoria *ptr) {
    this->cab = ptr;
}

void ListaCategorias::setLargo(int plargo) {
    this->largo = plargo;
}

bool ListaCategorias::esVacia() {
    return (cab == nullptr || largo == 0) ? true : false;
}

void ListaCategorias::agregarAntesDe(Categoria * pnueva, Categoria * ref) {
    pnueva->setSgte(ref);
    pnueva->setSgte(ref->getAnte());

    ref->getAnte()->setSgte(pnueva);
    ref->setAnte(pnueva);
    largo ++;
}

void ListaCategorias::agregarDespuesDe(Categoria *pnueva, Categoria *ref) {

    pnueva->setAnte(ref);
    pnueva->setSgte(ref->getSgte());
    if (ref->getSgte() != NULL){
        ref->getSgte()->setAnte(pnueva);
    }
    ref->setSgte(pnueva);
    largo ++;

}

void ListaCategorias::desligar(Categoria* paux)
{
    Categoria* quitar = paux;
    if (quitar == getCab()) { // Es la cabeza
        Categoria* aux = getCab();

        aux->getSgte()->setAnte(aux->getAnte());
        aux->getAnte()->setSgte(aux->getSgte());

        setCab(aux->getSgte());
    }
    else { // Es el ultimo
        quitar->getAnte()->setSgte(quitar->getSgte());
        quitar->getSgte()->setAnte(quitar->getAnte());
    }


}


bool ListaCategorias::agregarCategoria(Categoria *pnueva) {

    Categoria *nueva;
    if (getCab()!=NULL) {
        nueva = pnueva;
        setCab(nueva);
        nueva->setAnte(nueva);
        nueva->setSgte(nueva);
        largo++;
        return true;

    } else {
        Categoria *aux = getCab();
        int valueCmp = strcmp(aux->getDescripcion(),nueva->getDescripcion());
        if (valueCmp==0){
            agregarAntesDe(nueva,aux);
            return true;
        } else if (valueCmp > 0){
            agregarAntesDe(nueva, aux);
            if (valueCmp >0)
                setCab(nueva);
            return true;
        } else {
            while (aux!=NULL){
                valueCmp = strcmp(aux->getDescripcion(),nueva->getDescripcion());
                if (valueCmp>0){
                    agregarAntesDe(nueva, aux);
                    return true;
                }
                aux = aux->getSgte();
            }
        } if (valueCmp<0){
            aux=getCab();
            agregarDespuesDe(nueva,aux);
            return true;
        }
    }
    return false;
}

bool ListaCategorias::modificarCategoria(Categoria *modificado) {

    desligar(modificado);
    return agregarCategoria(modificado);
}

void ListaCategorias::eliminarCategoria(Categoria* peliminar) {

    desligar(peliminar);
    delete peliminar;

}

/*
void ListaCategorias::agregarArticuloACategoria(std::string particulo, std::string pcategoria) {

}

*/
void ListaCategorias::desplegarListaCategorias() {
    Categoria *aux = getCab();

    if (!esVacia()){
        cout << "** ================================== **" << endl;
        cout << "** =========Lista categorías========= **" << endl;

        while (aux!= NULL)
        {

            std::cout << aux->getDescripcion() << std::endl;
            aux = aux->getSgte();
        }
        cout << "** =======Fin lista categorías======= **" << endl;
        cout << "** ================================== **" << endl;
    }
}

/*
void ListaCategorias::desplegarArticulosCategoria(std::string pdescripcion) {

}
*/