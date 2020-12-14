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


    void setCab(Categoria* categoria);
    void setLargo(int);

    bool esVacia();
    void agregarAntesDe(Categoria* pdescripcion, Categoria* ref);
    void agregarDespuesDe(Categoria* pdescripcion, Categoria* ref);
    void desligar(Categoria *paux);


    bool agregarCategoria(Categoria *pnuevo);
    bool modificarCategoria(Categoria* modificado);
    void eliminarCategoria(Categoria* peliminar);
    void desplegarListaCategorias();

    void agregarArticuloACategoria(std::string, std::string);
    void desplegarArticulosCategoria(std::string);


};



