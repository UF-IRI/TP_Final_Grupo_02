#include "funciones.h"
#include <iri.cpp>
#include <iostream>
#include <cstdlib>
#pragma warning(disable : 4996)
using namespace std;
#define archpacientes "../data_files/input/IRI_Pacientes.csv" 

int main()
{	
//	string ruta_pac =(BASE_PATH + archpacientes);
//	fstream pacientes;
//	pacientes.open(ruta_pac, ios::in);
//	Paciente* Lista_paciente;
//	int tamact_p = 0;
//	
//	Lista_paciente= LeerPacientes(pacientes, tamact_p); //funciona
//	if (Lista_paciente == nullptr) {
//		cout << "hubo un error al leer los pacientes" << endl;
//		return -1;
//	}
//
//	cout << "-------------LISTA PACIENTES-----------" << endl;
//	Imprimir_Lista_pacientes(Lista_paciente, tamact_p);  //funciona
//
//	
//	string ruta_cons = (BASE_PATH + "../data_files/input/IRI_Consultas.csv");
//	fstream Consultas;
//	Consultas.open(ruta_cons, ios::in);
//	U_consulta* Lista_consultas;
//	int tamact_cons = 0;
//	
//	Lista_consultas = LeerConsultas(Consultas, tamact_cons);
//	if (Lista_consultas == nullptr) {
//		cout << "hubo un error al leer los consultas" << endl;
//		return -1;
//	}
//	cout << endl<<endl;
//
//	cout << "----------LISTA CONSULTAS----------------"<<endl;
//	Imprimir_Lista_consultas(Lista_consultas, tamact_cons);
//
//	
//	
//	string ruta_med = (BASE_PATH + "../data_files/input/IRI_Medicos.csv");
//	fstream Medicos;
//	Medicos.open(ruta_med, ios::in);
//	Medico* lista_medicos;
//	int tamact_med=0;
//
//	lista_medicos = LeerMedicos(Medicos, tamact_med);
//	if (lista_medicos == nullptr) {
//		cout << "hubo un error al leer los medicos" << endl;
//		return -1;
//	}
//
//	cout << "----------LISTA MEDICOS----------------" << endl;
//	Imprimir_Lista_Medicos(lista_medicos, tamact_med);
//
//
	string ruta_cont = (BASE_PATH + "../data_files/input/IRI_Contactos.csv");
	fstream Contactos;
	Contactos.open(ruta_cont, ios::in);
	int tamact_cont=0;
	Contacto* lista_contactos;

	lista_contactos = LeerContactos(Contactos, tamact_cont);

	if (lista_contactos == nullptr) {
		cout << "hubo un error al leer los contactos" << endl;
		return -1;
	}
	cout<<"----------LISTA CONTACTOS----------------" << endl;

	Imprimir_Lista_contactos(lista_contactos, tamact_cont);
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

//	delete[]Lista_consultas;
//	delete[]Lista_paciente;
	delete[]lista_contactos;
//	delete[]lista_medicos;
	return 0;
}
