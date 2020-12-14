#pragma once
#include <string>
class Categoria {

private:
    std::string descripcion;

    Categoria *ante;
    Categoria *sgte;

public:
    Categoria();
    Categoria(std::string);
    ~Categoria();

    #pragma region Gets and sets
    std::string getDescripcion();
    Categoria* getAnte();
    Categoria* getSgte();

    void setDescripcion(std::string descripcion);
    void setAnte(Categoria * categoria);
    void setSgte(Categoria * categoria);

#pragma endregion
};