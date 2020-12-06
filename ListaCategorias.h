#pragma once
#include "Categoria.h"
class ListaCategorias {

private:
    Categoria *cab;
    int largo;

public:
    ListaCategorias();
    ~ListaCategorias();

    Categoria *getCab();
    int getLargo();


    void setCab(Categoria *);
    void setLargo(int);

    void agregarCategoria(std::string);
    void modificarCategoria(std::string, std::string);
    void agregarArticuloACategoria(std::string, std::string);
    bool eliminarCategoria(std::string);
    void desplegarListaCategorias();
    void desplegarArticulosCategoria(std::string);
};



