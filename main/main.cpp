#include "funciones.cpp"
#include <iri.cpp>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	//int opcion;
	//int tamact_p;
	//int tamactual_O;
	//int tamactual_Med;
	//int tamactual_contactos;
	//int tamactual_consultas;

	//tamact_p = 0;
	//tamactual_O = 0;
	//tamactual_Med = 0;
	//tamactual_contactos = 0;
	//tamactual_consultas = 0;

	//Paciente* Lista_pacientes = new Paciente[tamact_p];
	//Obra_social* Lista_obras = new Obra_social[tamactual_O];
	//Medico* Lista_medicos = new Medico[tamactual_Med];
	//Contacto* Lista_contactos = new Contacto[tamactual_contactos];
	//Consulta* Lista_consultas = new Consulta[tamactual_consultas];

	Paciente* Lista;
	Lista=LeerArchivo(BASE_PATH+"../data_files/input/IRI_Pacientes.csv"); //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
	
	// //adentro esta la funcion agregar, fijarse si funciona

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
