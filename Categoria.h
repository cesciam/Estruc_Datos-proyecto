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
    std::string getCategoria();
    Categoria *getAnte;
    Categoria *getSgte;

    void setCategoria(std::string);
    void setAnte(Categoria *);
    void setSgte(Categoria *);

};