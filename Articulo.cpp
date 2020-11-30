#include "Articulo.h"

Articulo::Articulo()
{
	this->codigo = NULL;
	this->descripcion = "";
	this->precio = NULL;
	this->cantidad = NULL;

	this->sgte = nullptr;
	this->ante = nullptr;
}

Articulo::Articulo(int codigo, std::string descripcion, int precio,  int cantidad)
{
	this->codigo = codigo;
	this->descripcion = descripcion;
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

std::string Articulo::getDescripcion()
{
	return this->descripcion;
}

int Articulo::getPrecio()
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

void Articulo::setDescripcion(std::string descripcion)
{
	this->descripcion = descripcion;
}

void Articulo::setPrecio(int precio)
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
