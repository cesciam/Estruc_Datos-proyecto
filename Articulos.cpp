#include "Articulos.h"
#include <iostream>

Articulos::Articulos()
{
	this->cab = nullptr;
	this->largo = 0;
}

Articulos::~Articulos()
{
}

bool Articulos::AgregarArticulo(Articulo* pnuevo)
{
	Articulo* nuevo;
	if (!esVacia()) {
		nuevo = pnuevo;
		Articulo* aux = getCab();
		aux->getAnte()->setSgte(nuevo);
		nuevo->setAnte(aux->getAnte());
		
		aux->setAnte(nuevo);
		nuevo->setSgte(aux);
		largo += 1;

		return true;
	}
	else
	{
		nuevo = pnuevo;
		largo = 1;
		cab = nuevo;
		cab->setAnte(nuevo);
		nuevo->setSgte(cab);
		return true;
	}
}

bool Articulos::EliminarArticulo()
{
	return false;
}

void Articulos::DesplegarArticulo()
{
	Articulo* aux = getCab();
	if (!esVacia()) {
		do {
			std::cout << "Codigo: "<< aux->getCodigo()<< std::endl;
			std::cout << "Descripcion: " << aux->getDescripcion() << std::endl;
			std::cout << "Precio: " << aux->getPrecio() << std::endl;
			std::cout << "Cantidad: " << aux->getCantidad() << std::endl;
			std::cout << "Estatus: " << aux->getEstatus() << std::endl;
		
			aux = aux->getSgte();
		} while (aux != getCab());
	}
}

bool Articulos::esVacia()
{
	return (cab == nullptr || largo == 0) ? true : false;
}

void Articulos::setCab(Articulo* articulo)
{
	this->cab = articulo;
}

Articulo* Articulos::getCab()
{
	return this->cab;
}

int Articulos::getLargo()
{
	return this->largo;
}

