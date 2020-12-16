#pragma once
#include "Articulo.h"
class Articulos
{
private:
	Articulo* cab;
	int largo;

public:
	Articulos();
	~Articulos();
	
	bool AgregarArticulo(Articulo* nuevo);
	bool EliminarArticulo();
	void DesplegarArticulo();

	bool esVacia();

	void setCab(Articulo* articulo);
	Articulo* getCab();

	int getLargo();


	void agregarDespues(Articulo * nuevo, Articulo * aux);
	void agregarAntes(Articulo* nuevo, Articulo* aux);

	Articulo* existeArticulo(int codigo);
	Articulo* existeArticulo(char nombre[50]);

	bool modificar(Articulo* modificado);

	void desligar(Articulo* aux);

	void eliminar(Articulo* artic);

	void actualizarPrecios(int signo, int porcentaje);

	double totalInventario();

	int productosAgotados(bool imprimir);

	void inventarioDisponible();

	void imprimirDescendente();
};

