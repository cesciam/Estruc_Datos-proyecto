#pragma once
#include "Articulo.h"
class Articulos
{
private:
	Articulo* cab;
	int largo;

public:
	Articulos();
	~Articulos();
	
	bool AgregarArticulo(Articulo* nuevo);
	bool EliminarArticulo();
	void DesplegarArticulo();

	bool esVacia();

	void setCab(Articulo* articulo);
	Articulo* getCab();

	int getLargo();


};

