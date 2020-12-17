
#include <iostream>
#include "Articulo.h"
#include "Articulos.h"
#include <string>
#include "Categoria.h"
#include "ListaCategorias.h"
#include "ArticulosYCategorias.h"
#include "ArticuloYCategoria.h"

using namespace std;


#pragma region Funciones Articulos
Articulos* articulos = new Articulos();
ListaCategorias* ListaCat = new ListaCategorias();
ArticulosYCategorias * listaayc = new ArticulosYCategorias();

using namespace std;


Articulo* verificarCod(int tipo) {
	int codigo;
	string tipoOperac = tipo == 1 ? "editar" : "eliminar";
	if (tipo == 3) {
		tipoOperac = "buscar";
	}
	cout << "Ingrese el codigo del articulo que desea " << tipoOperac << ": " << endl;
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


	cout << "Ingrese la descripcion del nuevo articulo: " << endl;
	cin.get(descripcion, sizeof(descripcion));

	cout << "Ingrese el precio del nuevo articulo: " << endl;
	cin >> precio;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	if (precio == 0) {
		cout << "El precio del articulo deben ser solo numeros mayores a 0. " << endl;
		return false;
	}

	cout << "Ingrese la cantidad en numeros de " << descripcion << " en bodega: " << endl;
	cin >> cantidad;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Articulo* articulo = new Articulo(codigo, descripcion, precio, cantidad);

	articulos->AgregarArticulo(articulo);
	return true;
}

bool modificarArticulo() {
	char descripcion[50];
	int precio;

	if (!articulos->esVacia()) {
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
	}
	else
	{
		cout << "No hay articulos registrados." << endl;
	}

	return true;
}

bool modificarExistencia() {
	int cantidad;

	if (!articulos->esVacia()) {
		Articulo* modificado = verificarCod(1);
		if (modificado == nullptr)
			return false;

		cout << "Ingrese la nueva cantidad (en numeros) de " << modificado->getDescripcion() << " en bodega: " << endl;
		cin >> cantidad;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		modificado->setCantidad(cantidad);

		modificado->mostrar();
	}
	else
	{
		cout << "No hay articulos registrados." << endl;
	}
	return true;
}

bool eliminarArticulo() {
	if (!articulos->esVacia()) {
		Articulo* modificado = verificarCod(2);
		if (modificado == nullptr)
			return false;

		articulos->eliminar(modificado);


		articulos->DesplegarArticulo();
	}
	else
	{
		cout << "No hay articulos registrados." << endl;
	}
	return true;
}

void actualizarPreciosPorcentual() {
	int porcentaje;
	int signo;


	if (!articulos->esVacia()) {
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
	else
	{
		cout << "No hay articulos registrados." << endl;
	}
}

Articulo* verificarNombre() {
	char nombre[50];
	cout << "Ingrese el codigo del articulo que desea buscar:"  << ": " << endl;
	cin >> nombre;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	Articulo* articulo = articulos->existeArticulo(nombre);

	if (articulo == nullptr) {
		cout << "El articulo no se encuentra registrado." << endl;
		return nullptr;
	}

	return articulo;
}

#pragma endregion

#pragma region Categorias

void articulosCategoria() {
	int codigo;
	cout << "Ingrese el codigo del articulo: " << endl;
	cin >> codigo;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Articulo* artic = articulos->existeArticulo(codigo);

	if (artic == nullptr) {
		cout << "No existe un articulo con el codigo digitado. " << endl;
		return;
	}

	char nombreCat[50];
	cout << "Ingrese el nombre de la categoria: " << endl;
	cin >> nombreCat;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Categoria* cat = ListaCat->verificarCat(nombreCat);

	if(cat == nullptr) {
		cout << "No existe una categoria con el nombre digitado. " << endl;
		return;
	}

	ArticuloYCategoria* ayc = new ArticuloYCategoria(artic, cat);

	listaayc->agregarayc(ayc);
}

void desplegarArticulosPorCat() {
	char nombreCat[50];
	cout << "Ingrese el nombre de la categotia: " << endl;
	cin >> nombreCat;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Categoria* cat = ListaCat->verificarCat(nombreCat);

	if (cat == nullptr) {
		cout << "No existe una categoria con el nombre digitado. " << endl;
		return;
	}

	listaayc->desplegarArticulosCategoria(cat);

}

#pragma endregion


#pragma region Menus

void menuUsuario() {
	int opcion;

	do {
		cout << "******************************* " << endl;
		cout << "***Menu usuario************** " << endl;
		cout << "1. Buscar articulo. " << endl;
		cout << "2. Ver articulos por categoria. " << endl;
		cout << "3. Salir " << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: {
			Articulo* articulo = verificarNombre();
			if (articulo != nullptr) {
				articulo->mostrarEstat();
			}
			break;
		}

		case 2: {
			cout << "Cooming soon... " << endl;
			//Ingrese nombre de la categoria
			// buscar categoria por nombre
			// luego buscar en multilista, creo lol
			break;
		}

		default:
			break;
		}

	} while (opcion != 3);

}
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
		cout << "6. Desplegar los articulos de una categoria en especifica. " << endl;
		cout << "7. Salir. " << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: {
			char descripcion[50];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "*********** " << endl;
			cout << "**Agregar una categoria***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese la descripcion de la nueva categoria: " << endl;
			cin.get(descripcion, sizeof(descripcion));


			Categoria* categ = new Categoria(descripcion);

			ListaCat->agregarCategoria(categ);
			break;
		}

		case 2: { 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char descripcion[50];
			char nuevaDescrip[50];

			cout << "Ingrese el nombre de la categoria que desea modificar: " << endl;
			cin.get(descripcion, sizeof(descripcion));
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			Categoria* cat = ListaCat->verificarCat(descripcion);

			if (cat == nullptr) {
				cout << "No existe una categoria registrada con ese nombre." << endl;
				break;;
			}
			cout << "Ingrese el nuevo nombre de la categoria: " << endl;
			cin.get(nuevaDescrip, sizeof(nuevaDescrip));
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cat->setDescripcion(nuevaDescrip);

			ListaCat->modificarCategoria(cat);

			break;
		}

		case 3: { 
			articulosCategoria();
			break;
		}
		case 4: {

			char eliminar[50];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');


			cout << "*********** " << endl;
			cout << "**Eliminar una categoria***** " << endl;
			cout << "*********** " << endl;
			cout << "Ingrese la descripcion de la categoria a eliminar: " << endl;
			cin.get(eliminar, sizeof(eliminar));


			Categoria* cat = ListaCat->verificarCat(eliminar);

			if (cat == nullptr) {
				cout << "No existe una categoria registrada con ese nombre." << endl;
				break;
			}

			ListaCat->eliminarCategoria(cat);
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
		case 6: { 
			desplegarArticulosPorCat();
			break;
		}

		default:
			break;
		}

	} while (opcion != 7);
}
void menuArticulos() {
	int opcion;
	do {
		cout << "******************************* " << endl;
		cout << "***Menu articulos************** " << endl;
		cout << "1. Agregar articulo. " << endl;
		cout << "2. Modificar articulo. " << endl;
		cout << "3. Modificar existencia. " << endl;
		cout << "4. Eliminar articulo. " << endl;
		cout << "5. Desplegar articulos. " << endl;
		cout << "6. Actualizacion automatica de precios. " << endl;

		cout << "7. Salir. " << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: {
			agregarArticulo();
			break;
		}
		case 2: {
			modificarArticulo();
			break;
		}
		case 3: {
			modificarExistencia();
			break;
		}
		case 4: {
			eliminarArticulo();
			break;
		}
		case 5: {
			int forma;
			cout << "Desea imprimir de forma descendente?" << endl;
			cout << "1. Si" << endl;
			cout << "2. No" << endl;
			cin >> forma;
			if (forma == 2)
				articulos->DesplegarArticulo();
			else
				articulos->imprimirDescendente();
			break;
		}
		case 6: {
			actualizarPreciosPorcentual();
			break;
		}

		default:
			break;
		}

	} while (opcion != 7);
}
void menuReportes() {
	int opcion;

	do {
		cout << "1. Precio total del inventario " << endl;
		cout << "2. Cantidad de articulos existencia 0. " << endl;
		cout << "3. Lista de articulos agotados. " << endl;
		cout << "4. Lista de articulos no agotados. " << endl;
		cout << "5. Lista de articulos detallado " << endl;
		cout << "6. Lista de categorias." << endl;
		cout << "7. Lista de articulos por categoria." << endl;
		cout << "8. Salir." << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: {
			cout << "El precio total del inventario es de " <<articulos->totalInventario() << endl;
			break;
		}

		case 2: {
			cout << "La cantidad de articulos agotados son: "<< articulos->productosAgotados(false) << endl;
			break;
		}
		case 3: {
			articulos->productosAgotados(true);
			break;
		}
		case 4: {
			articulos->inventarioDisponible();
		}
		case 5: {
			articulos->DesplegarArticulo();
		}
		case 6:
			ListaCat->desplegarListaCategorias();
		case 7: {
			desplegarArticulosPorCat();
		}
		default:
			break;
		}

	} while (opcion != 8);
}
void menuAdministrador() {
	int opcion;

	do {
		cout << "1. Articulos. " << endl;
		cout << "2. Categorias. " << endl;
		cout << "3. Reportes y estadisticas. " << endl;
		cout << "4. Salir. " << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: {
			menuArticulos();
			break;
		}

		case 2: {
			menuCategorias();
			break;
		}
		case 3: {
			menuReportes();
			break;
		}

		default:
			break;
		}

	} while (opcion != 4);
}


#pragma endregion


int main()
{
	int opcion;


	do {
		cout << "******************************* " << endl;
		cout << "***Menu principal************** " << endl;
		cout << "1. Ingresar como administrador. "<< endl;
		cout << "2. Ingresar como usuario. " << endl;
		cout << "3. Salir. " << endl;
		cout << "Ingrese su opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
			case 1: {
				menuAdministrador();
				break;
			}

			case 2: {
				menuUsuario();
				break;
			}

			default:
				break;
		}

	} while (opcion != 3);


}


