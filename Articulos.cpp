#include "Articulos.h"
#include <iostream>

using namespace std;
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
	if (esVacia()) {
		nuevo = pnuevo;
		setCab(nuevo);
		nuevo->setAnte(nuevo);
		nuevo->setSgte(nuevo);
		largo += 1;
		return true;
	}
	else
	{
		nuevo = existeArticulo(pnuevo->getCodigo());
		if (nuevo != nullptr)
			return false;

		Articulo* aux = getCab();
		nuevo = pnuevo;
		int valueCmp = strcmp(aux->getDescripcion(), nuevo->getDescripcion());
		if (valueCmp == 0) { // En caso de que sean iguales, se agrega despues del primer valor
			agregarDespues(nuevo, aux);
			return true;
		}
		else if (valueCmp > 0) {
			agregarAntes(nuevo, aux);
			if (valueCmp > 0)
				setCab(nuevo);

			return true;
		}
		else {
			do {
				valueCmp = strcmp(aux->getDescripcion(), nuevo->getDescripcion());
				if (valueCmp > 0) {
					agregarAntes(nuevo, aux);
					return true;
				}
				aux = aux->getSgte();
			} while (aux != getCab());
		}

		if (valueCmp < 0) {
			aux = getCab();
			agregarDespues(nuevo, aux);
			return true;
		}

		
	}
	return false;
}

bool Articulos::EliminarArticulo()
{
	return false;
}

void Articulos::DesplegarArticulo()
{
	Articulo* aux = getCab();
	if (!esVacia()) {
		cout << "** ================================== **" << endl;
		cout << "** =====Lista articulos============== **" << endl;
		do {
			aux->mostrar();

			aux = aux->getSgte();
		} while (aux != getCab());
		cout << "** =====Fin lista articulos========== **" << endl;
		cout << "** ================================== **" << endl;
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

void Articulos::agregarDespues(Articulo* nuevo, Articulo* aux)
{
	nuevo->setSgte(aux);
	nuevo->setAnte(aux->getAnte());

	aux->getAnte()->setSgte(nuevo);
	aux->setAnte(nuevo);

	largo += 1;
}

void Articulos::agregarAntes(Articulo* nuevo, Articulo* aux)
{
	nuevo->setSgte(aux);
	nuevo->setAnte(aux->getAnte());

	aux->getAnte()->setSgte(nuevo);
	aux->setAnte(nuevo);
	largo += 1;
}

Articulo* Articulos::existeArticulo(int codigo)
{
	Articulo * aux = getCab();

	do {
		if (aux->getCodigo() == codigo)
			return aux;
		
		aux = aux->getSgte();
	} while (aux != getCab());

	return nullptr;
}

Articulo* Articulos::existeArticulo(char nombre[50])
{
	Articulo* aux = getCab();

	if (!esVacia()) {
		do {
			if (strcmp(aux->getDescripcion(), nombre) == 0)
				return aux;

			aux = aux->getSgte();
		} while (aux != getCab());
	}
	

	return nullptr;
}

bool Articulos::modificar(Articulo* modificado)
{
	desligar(modificado);

	return AgregarArticulo(modificado);

}

void Articulos::desligar(Articulo* paux)
{
	Articulo* quitar = paux;
	if (quitar == getCab()) { // Es la cabeza
		Articulo* aux = getCab();

		aux->getSgte()->setAnte(aux->getAnte());
		aux->getAnte()->setSgte(aux->getSgte());

		setCab(aux->getSgte());
	}
	else { // Es el ultimo
		quitar->getAnte()->setSgte(quitar->getSgte());
		quitar->getSgte()->setAnte(quitar->getAnte());
	}

	
}

void Articulos::eliminar(Articulo* artic)
{
	desligar(artic);

	delete artic;
}

void Articulos::actualizarPrecios(int signo, int porcentaje)
{
	double porc = (int)porcentaje;
	if (signo == 1) { //Suma porcentaje
		Articulo* aux = getCab();
	
		do {
			double precio = aux->getPrecio();
			double nuevoPrecio = precio + precio * (porc / 100);
			aux->setPrecio(nuevoPrecio);

			aux = aux->getSgte();
		} while (aux != getCab());
	}
	else //Resta porcentaje
	{
		Articulo* aux = getCab();

		do {
			double precio = (int)aux->getPrecio();
			double nuevoPrecio = precio - precio * (porc / 100);
			aux->setPrecio(nuevoPrecio);
		} while (aux != getCab());

	}
	
}

double Articulos::totalInventario()
{
	double precio = 0.0;

	Articulo* aux = getCab();
	if (!esVacia()) {
		do {
			precio += aux->getPrecio() * aux->getCantidad();

			aux = aux->getSgte();
		} while (aux != getCab());
		
	}

	return precio;
}

int Articulos::productosAgotados(bool imprimir)
{
	int cantidad = 0;
	Articulo* aux = getCab();
	if (imprimir)
		cout << "******Articulos agotados***************" << endl;

	if (!esVacia()) {
		do {
			if (aux->getCantidad() == 0) {
				cantidad += 1;
				if (imprimir)
					aux->mostrar();
			}
			aux = aux->getSgte();
		} while (aux != getCab());

	}
	return cantidad;
}

void Articulos::inventarioDisponible()
{
	Articulo* aux = getCab();
	cout << "******Articulos en disponibles***************" << endl;
	if (!esVacia()) {
		do {
			if (aux->getCantidad() > 0) {
				aux->mostrar();
			}
			aux = aux->getSgte();
		} while (aux != getCab());

	}
}

void Articulos::imprimirDescendente()
{

	Articulo* aux = getCab()->getAnte();;
	if (!esVacia()) {
		cout << "** ================================== **" << endl;
		cout << "** =====Lista articulos============== **" << endl;
		do {
			aux->mostrar();

			aux = aux->getAnte();
		} while (aux != getCab()->getAnte());
		cout << "** =====Fin lista articulos========== **" << endl;
		cout << "** ================================== **" << endl;
	}
}





