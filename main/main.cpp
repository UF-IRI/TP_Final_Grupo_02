#include "funciones.cpp"
#include <iri.cpp>
#include <iostream>
#include <cstdlib>
#pragma warning(disable : 4996)
using namespace std;
#define archpacientes ".../data_files/input/IRI_Pacientes.csv" 
int main()
{	
	string ruta_pac =(BASE_PATH + "../data_files/input/IRI_Pacientes.csv");
	fstream pacientes;
	pacientes.open(ruta_pac, ios::in);
	Paciente* Lista_paciente;
	Lista_paciente= LeerPacientes(pacientes); //funciona
	cout << "-------------LISTA PACIENTES-----------" << endl;
	Imprimir_Lista_pacientes(Lista_paciente);  //funciona

	
	string ruta_cons = (BASE_PATH + "../data_files/input/IRI_Consultas.csv");
	fstream Consultas;
	Consultas.open(ruta_cons, ios::in);
	U_consulta* Lista_consultas;
	Lista_consultas = LeerConsultas(Consultas);
	cout << endl;
	cout << endl;
	cout << "----------LISTA CONSULTAS----------------"<<endl;

	Imprimir_Lista_consultas(Lista_consultas);


	
	
	//string ruta_med = (BASE_PATH + "../data_files/input/IRI_Medicos.csv");
	//Medico* lista_medicos;
	//lista_medicos = LeerMedicos(ruta_med);

	

	//string ruta_cont = (BASE_PATH + "../data_files/input/IRI_Contactos.csv");
	//Contacto* lista_contactos;
	//lista_contactos = LeerContactos(ruta_cont);

	/*int dif;
	dif = DevolverFecha(Lista_pacientes);
	cout << dif;*/


	/* Archivar(Lista_pacientes);*/ //adentro esta la funcion de devolver fecha y escrbir archivados(fijarse si se crea y se escribe el archivo), fijarse si funcionan

	 //pruebo si esta leyendo y agregando bien a la lista con la funcion imprimir lista de pacientes. Si funciona deberimaos hacer lo mismo pero para el resto de las listas
	/* Imprimir_Lista(Lista_pacientes);*/

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
