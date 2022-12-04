#include "iri.cpp"
#include <iostream>
#include <cstdlib>
#include <funciones.h>
using namespace std;

int main()
{
	
	string ruta_pac =(BASE_PATH + "../data_files/input/IRI_Pacientes.csv");
	Paciente* Lista_pacientes;
	Lista_pacientes=LeerPacientes(ruta_pac); //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
	
	string ruta_med = (BASE_PATH + "../data_files/input/IRI_Medicos.csv");
	Medico* lista_medicos;
	lista_medicos = LeerMedicos(ruta_med);

	string ruta_cons = (BASE_PATH + "../data_files/input/IRI_Consultas.csv");
	Consulta* lista_consultas;
	lista_consultas = LeerConsultas(ruta_cons);

	string ruta_cont = (BASE_PATH + "../data_files/input/IRI_Contactos.csv");
	Contacto* lista_contactos;
	lista_contactos = LeerContactos(ruta_cont);

	 Archivar(Lista_pacientes); //adentro esta la funcion de devolver fecha y escribir archivados(fijarse si se crea y se escribe el archivo), fijarse si funcionan

	 //pruebo si esta leyendo y agregando bien a la lista con la funcion imprimir lista de pacientes. Si funciona deberimaos hacer lo mismo pero para el resto de las listas
	 Imprimir_Lista(Lista_pacientes);

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
