#pragma once
#include <string>
class Articulo
{
private:
	int codigo;
	std::string descripcion;
	int precio;
	std::string estatus;
	int cantidad;

	Articulo* sgte;
	Articulo* ante;

	/// Faltan las categorias a las que pertenece

public:
	Articulo();
	Articulo(int codigo, std::string descripcion, int precio, int cantidad);
	~Articulo();

	#pragma region Gets and sets
	int getCodigo();
	std::string getDescripcion();
	int getPrecio();
	std::string getEstatus();
	int getCantidad();
	Articulo* getSgte();
	Articulo* getAnte();

	void setCodigo(int codigo);
	void setDescripcion(std::string descripcion);
	void setPrecio(int precio);
	void setCantidad(int cantidad);
	void setSgte(Articulo* articulo);
	void setAnte(Articulo* articulo);

#pragma endregion
	


};





 

