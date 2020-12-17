#pragma once
#include <string>
class Articulo
{
private:
	int codigo;
	/*std::string descripcion;*/
	char descripcion[50];
	double precio;
	std::string estatus;
	int cantidad;

	Articulo* sgte;
	Articulo* ante;

	/// Faltan las categorias a las que pertenece

public:
	Articulo();
	Articulo(int codigo, char descripcion[50], double precio, int cantidad);
	~Articulo();

	#pragma region Gets and sets
	int getCodigo();
	char * getDescripcion();
	double getPrecio();
	std::string getEstatus();
	int getCantidad();
	Articulo* getSgte();
	Articulo* getAnte();

	void setCodigo(int codigo);
	void setDescripcion(char descripcion[50]);
	void setPrecio(double precio);
	void setCantidad(int cantidad);
	void setSgte(Articulo* articulo);
	void setAnte(Articulo* articulo);

	void mostrar();
	void mostrarEstat();

#pragma endregion
	


};

