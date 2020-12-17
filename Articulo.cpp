#include "Articulo.h"
#include <iostream>
using namespace std;

Articulo::Articulo()
{
	this->codigo = NULL;
	strcpy_s(descripcion, "");
	this->precio = NULL;
	this->cantidad = NULL;

	this->sgte = nullptr;
	this->ante = nullptr;
}

Articulo::Articulo(int codigo, char descripcion[50], double precio,  int cantidad)
{
	this->codigo = codigo;
	strcpy_s(this->descripcion, descripcion);
	this->precio = precio;
	this->cantidad = cantidad;

	this->estatus = cantidad > 0 ? "Disponible." : "Agotado";
}

Articulo::~Articulo()
{
}

int Articulo::getCodigo()
{
	return this->codigo;
}

char * Articulo::getDescripcion()
{
	return this->descripcion;
}

double Articulo::getPrecio()
{
	return this->precio;
}

std::string Articulo::getEstatus()
{
	return this->estatus;
}

int Articulo::getCantidad()
{
	return this->cantidad;
}

Articulo* Articulo::getSgte()
{
	return this->sgte;
}

Articulo* Articulo::getAnte()
{
	return this->ante;
}

void Articulo::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void Articulo::setDescripcion(char descripcion[50])
{
	strcpy_s(this->descripcion, descripcion);
}

void Articulo::setPrecio(double precio)
{
	this->precio = precio;
}

void Articulo::setCantidad(int cantidad)
{
	this->cantidad = cantidad;

	this->estatus = (cantidad > 0) ? "Disponible" : "Agotado";
}

void Articulo::setSgte(Articulo* articulo)
{
	this->sgte = articulo;
}

void Articulo::setAnte(Articulo* articulo)
{
	this->ante = articulo;
}

void Articulo::mostrar()
{
	cout << "***************************************** " << endl;
	cout << "Codigo: " << getCodigo() <<endl;
	cout << "Descripcion: " << getDescripcion() <<endl;
	cout << "Precio: " << getPrecio() << endl;
	cout << "Cantidad: " <<getCantidad() << endl;
	cout << "Estatus: " << getEstatus() << endl;
	cout << "***************************************** " <<endl;
}

void Articulo::mostrarEstat()
{
	cout << "***************************************** " << endl;
	cout << "Codigo: " << getCodigo() << endl;
	cout << "Descripcion: " << getDescripcion() << endl;
	cout << "Precio: " << getPrecio() << endl;
	cout << "Cantidad: " << getCantidad() << endl;
	if(getCantidad() == 0)
		cout << "Estatus: " << getEstatus() << endl;
	cout << "***************************************** " << endl;
}
