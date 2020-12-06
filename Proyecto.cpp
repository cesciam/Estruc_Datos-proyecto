// Proyecto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Articulo.h"
#include "Articulos.h"
#include "Categoria.h"
#include "ListaCategorias.h"

using namespace std;


Articulos* articulos = new Articulos();

bool agregarArticulo() {
	int codigo;
	std::string descripcion;
	int precio;
	int cantidad;

	std::cout << "Ingrese el codigo del nuevo producto: " << std::endl;
	std::cin >> codigo;

	if (codigo == 0) {
		std::cout << "El codigo del producto deben ser solo numeros mayores a 0. " << std::endl;
		return false;
	}
		

	std::cout << "Ingrese la descripcion del nuevo producto: "<< std::endl;
	// No logro hacer que se lea la descripcion
	std::getline(std::cin, descripcion);

	std::cout << "Ingrese el precio del nuevo producto: " << std::endl;
	std::cin >> precio;

	if (precio == 0) {
		std::cout << "El precio del producto deben ser solo numeros mayores a 0. " << std::endl;
		return false;
	}

	std::cout << "Ingrese la cantidad en numeros de "<< descripcion << " en bodega: " << std::endl;
	std::cin >> cantidad;

	Articulo* articulo = new Articulo(codigo, descripcion, precio, cantidad);

	articulos->AgregarArticulo(articulo);
	return true;
}


std::string descripcion;

int main()
{
	
	agregarArticulo();
	agregarArticulo();
	agregarArticulo();
	agregarArticulo();
	agregarArticulo();
	agregarArticulo();

	articulos->DesplegarArticulo();

	

	// CATEGORIAS
	ListaCategorias *ListaCat = new ListaCategorias;

	std::cout << "Digite la descripcion de la categoria" << std::endl;
    std::cin >> descripcion;
	ListaCat->agregarCategoria(descripcion);
	ListaCat->desplegarListaCategorias();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
