
#include <iostream>
#include "Articulo.h"
#include "Articulos.h"
#include <string>
#include "Categoria.h"
#include "ListaCategorias.h"

using namespace std;


Articulos* articulos = new Articulos();

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
		cout << "Opci�n incorrecta. Por favor ingrese (1) o (2)." << endl;
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

std::string descripcion;

int main()
{

}


