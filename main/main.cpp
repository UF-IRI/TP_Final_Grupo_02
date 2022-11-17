#include "funciones.cpp"
#include <iri.cpp>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	
	string ruta =(BASE_PATH + "../data_files/input/IRI_Pacientes.csv");
	Paciente* Lista;
	Lista=LeerArchivo(ruta); //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
	
	
	// //pruebo si esta leyendo y agregando bien a la lista con la funcion imprimir lista de pacientes. Si funciona deberimaos hacer lo mismo pero para el resto de las listas
	Imprimir_Lista(Lista);

	// Archivar(Lista_pacientes); //adentro esta la funcion de devolver fecha y escrbir archivados(fijarse si se crea y se escribe el archivo), fijarse si funcionan


	//
	//
	// cout << "Contactando..." << endl; //podriamos meterlo en un bucle y que vaya contactando paciente por paciente 
	// cout << "Si desea reprogramar un turno ingrese un 1, de otra forma ingrese cualquier numero: ";
	// cin >> opcion;
	// Secretaria(Lista_pacientes, opcion); //tiene adentro cambio_cobertura y reprogramar consulta(tiene adentro fecha random)
	//
	// system("pause");

	return 0;
}
