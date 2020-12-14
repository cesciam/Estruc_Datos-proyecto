#include "Categoria.h"

Categoria::Categoria(){

    this->descripcion = " ";

    this->sgte = nullptr;
    this->ante = nullptr;
}

Categoria::~Categoria(){}

Categoria::Categoria(std::string pdescripcion){
    this->descripcion = pdescripcion;
    
}

std::string Categoria::getDescripcion(){
    return this->descripcion;
}

Categoria *Categoria::getSgte(){
    return this->sgte;
}

Categoria *Categoria::getAnte(){
    return this->ante;
}

void Categoria::setDescripcion(std::string pdescripcion){
    this->descripcion = pdescripcion;
}

void Categoria::setSgte(Categoria *ptr){
    this->sgte = ptr;
}

void Categoria::setAnte(Categoria *ptr){
    this->ante = ptr;
}