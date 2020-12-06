#include "Categoria.h"

Categoria::Categoria(){
    this->descripcion = " ";
    this->sgte = NULL;
    this->ante = NULL;
}

Categoria::~Categoria(){}

Categoria::Categoria(std::string pdescripcion){
    this->descripcion = pdescripcion;
    this->sgte = NULL;
    this->ante = NULL;
}

std::string Categoria::getCategoria(){
    return this->descripcion;
}

Categoria *Categoria::getSgte(){
    return this->sgte;
}

Categoria *Categoria::getAnte(){
    return this->ante;
}

void Categoria::setCategoria(std::string pdescripcion){
    this->descripcion = pdescripcion;
}

void Categoria::setSgte(Categoria *ptr){
    this->sgte = ptr;
}

void Categoria::setAnte(Categoria *ptr){
    this->ante = ptr;
}