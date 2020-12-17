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
    

    pnueva->setSgte(ref); // PASO #2
    pnueva->setAnte(ref->getAnte()); // PASO #2

    ref->getAnte()->setSgte(pnueva); // PASO #3
    ref->setAnte(pnueva); // PASO #3
    largo++;
   
}

Categoria *ListaCategorias::dirUltimo() {
    Categoria* aux = getCab();

    while (aux->getSgte() != NULL) {
        aux = aux->getSgte();
    }
    return aux;
}

Categoria* ListaCategorias::dirAnterior(Categoria* x) {

    Categoria* aux = dirNodo(x);
    if (aux == NULL) {
        return NULL;
    }
    else {
        return aux->getAnte();
    }

}

Categoria* ListaCategorias::dirNodo(Categoria* dRef) {
    Categoria* aux = NULL;
    bool encontrado = false;

    if (!esVacia()) {
        aux = getCab();
        while (aux != NULL && !encontrado) {
            if (aux == dRef)
                encontrado = true;
            else
                aux = aux->getSgte();
        }
        return aux;
    }
}

Categoria* ListaCategorias::verificarCat(char descripcion[50])
{
    Categoria* aux = getCab();

    if (!esVacia()) {
        do {
            if (strcmp(aux->getDescripcion(), descripcion) == 0)
                return aux;

            aux = aux->getSgte();
        } while (aux != getCab());
    }


    return nullptr;
}


void ListaCategorias::agregarDespuesDe(Categoria *pnueva, Categoria *ref) {

    Categoria* aux = dirUltimo();
    pnueva->setAnte(aux);
    aux->setSgte(pnueva);

    largo++;

}

void ListaCategorias::desligar(Categoria* paux) {
    Categoria* quitar = paux;
    Categoria* ult = dirUltimo();
    if (getLargo() == 1) {
        setLargo(getLargo() - 1);
        return;
    }

    if (quitar == getCab()) { // Es la cabeza
        quitar->getSgte()->setAnte(NULL);
        setCab(quitar->getSgte());
        setLargo(getLargo() - 1);
    }
     else if (quitar != ult){
        quitar->getAnte()->setSgte(quitar->getSgte());
        quitar->getSgte()->setAnte(quitar->getAnte());
        setLargo(getLargo() - 1);

        } else {
        quitar->getAnte()->setAnte(nullptr);
        setLargo(getLargo() - 1);
        }
}


bool ListaCategorias::agregarCategoria(Categoria *pnueva) {

    Categoria *nueva = pnueva;
    if (esVacia()) {
        setCab(nueva);
        largo++;
        return true;

    } else {
        Categoria *aux = getCab();
        int valueCmp = strcmp(aux->getDescripcion(),nueva->getDescripcion());
        if (valueCmp==0){
        
            cab->setAnte(nueva); //A  la cabeza le pone como anterior al nuevo
            nueva->setSgte(cab); // al nuevo le pone como siguiente la cabeza
            setCab(nueva);   // set cab nuevo
            return true;

        } else if (valueCmp > 0){

            cab->setAnte(nueva); //A  la cabeza le pone como anterior al nuevo
            nueva->setSgte(cab);  // al nuevo le pone como siguiente la cabeza
            setCab(nueva); // set cabe nuevo

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

bool ListaCategorias::modificarCategoria(Categoria* modificado) {
    if (getLargo() == 1)
        return true;

    desligar(modificado);
    return agregarCategoria(modificado);
}

void ListaCategorias::eliminarCategoria(Categoria* preliminar) {

    desligar(preliminar);
    delete preliminar;

}

/*
void ListaCategorias::agregarArticuloACategoria(std::string particulo, std::string pcategoria) {

}

*/
void ListaCategorias::desplegarListaCategorias() {
    Categoria *aux = getCab();

    if (!esVacia()){
        cout << "** ================================== **" << endl;
        cout << "** =========Lista categorias========= **" << endl;

        while (aux!= NULL)
        {

            std::cout << "Nombre categoria: "<< aux->getDescripcion() << std::endl;
            aux = aux->getSgte();
        }
        cout << "** =======Fin lista categorias======= **" << endl;
        cout << "** ================================== **" << endl;
    }
    else
    {
        cout << "** No hay categorias registradas **" << endl;
    }
}

/*
void ListaCategorias::desplegarArticulosCategoria(std::string pdescripcion) {

}
*/