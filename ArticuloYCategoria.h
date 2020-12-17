#pragma once
#include "Articulo.h"
#include "Categoria.h"
class ArticuloYCategoria
{
private: 
	Articulo* articulo;
	Categoria* categoria;

	ArticuloYCategoria* sgte;
public:
	ArticuloYCategoria();
	~ArticuloYCategoria();
	ArticuloYCategoria(Articulo* articulo, Categoria* categoria);

	void setArticulo(Articulo* articulo);
	void setCategoria(Categoria* categoria);
	void setSgte(ArticuloYCategoria*);

	Articulo* getArticulo();
	Categoria* getCategoria();
	ArticuloYCategoria* getSgte();
};

