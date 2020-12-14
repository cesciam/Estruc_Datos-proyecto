#include "Categoria.h"
#include <cstring>
#include <iostream>

using namespace std;

Categoria::Categoria(){

    strcpy(descripcion, "");

    this->sgte = nullptr;
    this->ante = nullptr;
}

Categoria::~Categoria(){}

Categoria::Categoria(char pdescripcion[50]){

    strcpy(this->descripcion, pdescripcion);
    
}

char * Categoria::getDescripcion(){
    return this->descripcion;
}

Categoria *Categoria::getSgte(){
    return this->sgte;
}

Categoria *Categoria::getAnte(){
    return this->ante;
}

void Categoria::setDescripcion(char pdescripcion[50]){

    strcpy(this->descripcion, pdescripcion);
}

void Categoria::setSgte(Categoria *ptr){
    this->sgte = ptr;
}

void Categoria::setAnte(Categoria *ptr){
    this->ante = ptr;
}


