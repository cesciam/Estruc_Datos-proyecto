#pragma once
#include <string>
class Categoria {

private:
    char descripcion[50];

    Categoria *sgte;
    Categoria *ante;

public:
    Categoria();
    Categoria(char descripcion[50]);
    ~Categoria();

    #pragma region Gets and sets
    char * getDescripcion();
    Categoria* getAnte();
    Categoria* getSgte();

    void setDescripcion(char descripcion[50]);
    void setAnte(Categoria * categoria);
    void setSgte(Categoria * categoria);

    

#pragma endregion
};