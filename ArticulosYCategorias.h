#pragma once
#include "ArticuloYCategoria.h"
class ArticulosYCategorias
{
private:
	ArticuloYCategoria* cab;
	int largo;

public:	
	bool esVacia();
	ArticulosYCategorias();
	~ArticulosYCategorias();

	bool agregarayc(ArticuloYCategoria* ayc);
	void setCab(ArticuloYCategoria* ayc);

	ArticuloYCategoria* getCab();

	int getLargo();
	void setLargo(int largo);

	void desplegarArticulosCategoria(Categoria* categoria);
	
};

