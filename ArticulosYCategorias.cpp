#include "ArticulosYCategorias.h"
#include <iostream>
using namespace std;
bool ArticulosYCategorias::esVacia()
{
    return getCab() == nullptr;
}

ArticulosYCategorias::ArticulosYCategorias()
{
	setCab(nullptr);
	setLargo(0);
}

ArticulosYCategorias::~ArticulosYCategorias()
{
}

bool ArticulosYCategorias::agregarayc(ArticuloYCategoria* ayc)
{
	ArticuloYCategoria* nuevo = ayc; //Paso 1. Crear el nodo
	nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a la lista
	setCab(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
	largo++;
	return true;
}

void ArticulosYCategorias::setCab(ArticuloYCategoria* ayc)
{
	this->cab = ayc;
}

ArticuloYCategoria* ArticulosYCategorias::getCab()
{
	return this->cab;
}

int ArticulosYCategorias::getLargo()
{
	return this->largo;
}

void ArticulosYCategorias::setLargo(int plargo)
{
	this->largo = plargo;
}

void ArticulosYCategorias::desplegarArticulosCategoria(Categoria* categoria)
{
	ArticuloYCategoria* aux = getCab();
	cout << "ELEMENTOS EN LA LISTA:" << endl;
	while (aux != NULL) {
		if (categoria == aux->getCategoria()) {
			aux->getArticulo()->mostrar();
		}
		
		aux = aux->getSgte();
	}
}
