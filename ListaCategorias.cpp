#include "ListaCategorias.h"
#include <iostream>

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

void ListaCategorias::agregarCategoria(std::string pdescripcion) {
    
    Categoria *nueva = new Categoria(pdescripcion);
    nueva->setSgte(getCab());
    if (getCab()!= NULL)
    {
        getCab()->setAnte(nueva);
    }
    setCab(nueva);
    largo++;
}
/*
void ListaCategorias::modificarCategoria(std::string ref, std::string pdescripcion) {

}

void ListaCategorias::agregarArticuloACategoria(std::string particulo, std::string pcategoria) {

}

bool ListaCategorias::eliminarCategoria(std::string pdescripcion) {

}
*/
void ListaCategorias::desplegarListaCategorias() {
    Categoria *aux = getCab();
    while (aux!= NULL)
    {
        std::cout << aux->getDescripcion() << std::endl;
        aux = aux->getSgte();
    }
}
/*
void ListaCategorias::desplegarArticulosCategoria(std::string pdescripcion) {

}
*/