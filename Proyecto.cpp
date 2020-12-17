// Proyecto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Articulo.h"
#include "Articulos.h"
#include "Categoria.h"
#include "ListaCategorias.h"

Articulos* articulos = new Articulos();
ListaCategorias* ListaCat = new ListaCategorias();

using namespace std;


Articulo* verificarCod(int tipo) {
	int codigo;
	string tipoOperac = tipo == 1 ? "editar" : "eliminar";
	cout << "Ingrese el codigo del articulo que desea " << tipoOperac  <<": " << endl;
	cin >> codigo;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (codigo == 0) {
		cout << "El codigo del articulo deben ser solo numeros mayores a 0. " << endl;
		return nullptr;
	}

	Articulo* articulo = articulos->existeArticulo(codigo);

	if (articulo == nullptr) {
		cout << "El articulo no se encuentra registrado." << endl;
		return nullptr;
	}

	return articulo;
}

bool agregarArticulo() {
	int codigo;
	char descripcion[50];
	int precio;
	int cantidad;

	cout << "Ingrese el codigo del nuevo articulo: " << endl;
	cin >> codigo;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (codigo == 0) {
		cout << "El codigo del articulo deben ser solo numeros mayores a 0. " << endl;
		return false;
	}
		

	cout << "Ingrese la descripcion del nuevo articulo: "<< endl;
	cin.get(descripcion, sizeof(descripcion));

	cout << "Ingrese el precio del nuevo articulo: " << endl;
	cin >> precio;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	if (precio == 0) {
		cout << "El precio del articulo deben ser solo numeros mayores a 0. " << endl;
		return false;
	}

	cout << "Ingrese la cantidad en numeros de "<< descripcion << " en bodega: " << endl;
	cin >> cantidad;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Articulo* articulo = new Articulo(codigo, descripcion, precio, cantidad);

	articulos->AgregarArticulo(articulo);
	return true;
}

bool modificarArticulo() {
	char descripcion[50];
	int precio;

	Articulo* modificado = verificarCod(1);
	if (modificado == nullptr)
		return false;

	cout << "Ingrese la nueva descripcion del articulo: " << endl;
	cin.get(descripcion, sizeof(descripcion));

	cout << "Ingrese el nuevo precio del articulo: " << endl;
	cin >> precio;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	modificado->setDescripcion(descripcion);
	modificado->setPrecio(precio);


	articulos->modificar(modificado);

	modificado->mostrar();

	return true;
}

bool modificarExistencia() {
	int cantidad;

	Articulo* modificado = verificarCod(1);
	if (modificado == nullptr)
		return false;

	cout << "Ingrese la nueva cantidad (en numeros) de " << modificado->getDescripcion() << " en bodega: " << endl;
	cin >> cantidad;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	modificado->setCantidad(cantidad);

	modificado->mostrar();
	return true;
}

bool eliminarArticulo() {
	Articulo* modificado = verificarCod(2);
	if (modificado == nullptr)
		return false;

	articulos->eliminar(modificado);


	articulos->DesplegarArticulo();
	return true;
}

void actualizarPreciosPorcentual() {
	int porcentaje;
	int signo;

	
	cout << "Desea sumar o restar el porcentaje?" << endl;
	cout << "1. Sumar" << endl;
	cout << "2. Restar" << endl;
	cin >> signo;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (signo != 1 && signo != 2) {
		cout << "Opción incorrecta. Por favor ingrese (1) o (2)." << endl;
		return;
	}

	cout << "Ingrese el porcentaje a aplicar: " << endl;
	cin >> porcentaje;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (porcentaje == 0 || porcentaje < 0) {
		cout << "El codigo del articulo deben ser solo numeros mayores a 0. " << endl;
		return;
	}

	articulos->actualizarPrecios(signo, porcentaje);

	articulos->DesplegarArticulo();
}


//CATEGORIAS

void menuCategorias() {
	int opcion = -1;
	do {
		cout << "*********** " << endl;
		cout << "**Menu de categorias***** " << endl;
		cout << "1. Agregar una categoria. " << endl;
		cout << "2. Modificar una categoria. " << endl;
		cout << "3. Agregar un articulo a una categoria. " << endl;
		cout << "4. Eliminar una categoria. " << endl;
		cout << "5. Desplegar la lista de categorias. " << endl;
		cout << "6. Desplegar los articulos de una categoría en específica. " << endl;
		cout << "7. Salir. " << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: {
			char descripcion[50];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "*********** " << endl;
			cout << "**Agregar una categoría***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese la descripcion de la nueva categoria: " << endl;
			cin.get(descripcion, sizeof(descripcion));
			

			Categoria* categ = new Categoria(descripcion);

			ListaCat->agregarCategoria(categ);
			break;
		}

		case 2: { //DA ERROR, PENDIENTE DE SOLUCIONAR
			char ref[50];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char modificar[50];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "*********** " << endl;
			cout << "**Modificar una categoría***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese la descripcion que desea modificar: " << endl;
			cin.get(ref, sizeof(ref));
			cout << "Ingrese la descripcion correcta: " << endl;
			cin.get(modificar, sizeof(modificar));


			Categoria* categ = new Categoria(ref, modificar);

			ListaCat->modificarCategoria(categ);
			break;
		}

		case 3: { //PENDIENTE DE HACER

			cout << "*********** " << endl;
			cout << "**Agregar un articulo a una categoria***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese el codigo del articulo a ingresar: " << endl;
			cout << "PENDIENTE DE HACER " << endl;

			break;
		}
		case 4: { //DA ERROR, PENDIENTE DE SOLUCIONAR
			
			char eliminar[50];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');


			cout << "*********** " << endl;
			cout << "**Eliminar una categoria***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese la descripcion de la categoria a eliminar: " << endl;
			cin.get(eliminar, sizeof(eliminar));


			Categoria* categ = new Categoria(eliminar);

			ListaCat->eliminarCategoria(categ);
			break;

		}
		case 5: { 
			char descripcion[50];

			cout << "*********** " << endl;
			cout << "**Desplegar la lista de categorias***** " << endl;
			cout << "*********** " << endl;
			
			ListaCat->desplegarListaCategorias();
			
			break;
		}
		case 6: { //PENDIENTE DE HACER
	
			cout << "*********** " << endl;
			cout << "**Desplegar los articulos de una categoría en específica***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese la categoría que desea desplegar: " << endl;
			cout << "PENDIENTE DE HACER " << endl;
		
			
			break;
		}

		default:
			break;
		}

	} while (opcion != 7);
}


int main()
{

	menuCategorias();
	/*
	ListaCategorias* ListaCat = new ListaCategorias();
	


		char descripcion[50] = "Arboles de navidad";
		Categoria* categoria = new Categoria(descripcion);
		ListaCat->agregarCategoria(categoria);
		char descripcion1[50] = "Adornos de navidad";
		categoria = new Categoria(descripcion1);
		ListaCat->agregarCategoria(categoria);
		char descripcion2[50] = "Regalos de navidad";
		categoria = new Categoria(descripcion2);
		ListaCat->agregarCategoria(categoria);
		char descripcion3[50] = "Bufandas de navidad";
		categoria = new Categoria(descripcion3);
		ListaCat->agregarCategoria(categoria);
		char descripcion4[50] = "Ropa de navidad";
		categoria = new Categoria(descripcion4);
		ListaCat->agregarCategoria(categoria);
		
		ListaCat->desplegarListaCategorias();
	
	*/
}