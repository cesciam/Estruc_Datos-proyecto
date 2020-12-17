#include "ArticuloYCategoria.h"

ArticuloYCategoria::ArticuloYCategoria()
{
	this->articulo = nullptr;
	this->categoria = nullptr;
	this->sgte = nullptr;
}

ArticuloYCategoria::~ArticuloYCategoria()
{
}

ArticuloYCategoria::ArticuloYCategoria(Articulo* articulo, Categoria* categoria)
{
	setArticulo(articulo);
	setCategoria(categoria);
	setSgte(nullptr);
}

void ArticuloYCategoria::setArticulo(Articulo* particulo)
{
	this->articulo = particulo;
}

void ArticuloYCategoria::setCategoria(Categoria* pcategoria)
{
	this->categoria = pcategoria;
}

void ArticuloYCategoria::setSgte(ArticuloYCategoria* psgte)
{
	this->sgte = psgte;
}

Articulo* ArticuloYCategoria::getArticulo()
{
	return this->articulo;
}

Categoria* ArticuloYCategoria::getCategoria()
{
	return this->categoria;
}

ArticuloYCategoria* ArticuloYCategoria::getSgte()
{
	return this->sgte;
}
