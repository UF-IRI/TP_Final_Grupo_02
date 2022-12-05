#include "funciones.h"
#include <iri.cpp>
#pragma warning(disable : 4996)
using namespace std;

int main()
{	
	string ruta_pac =(BASE_PATH + ArchPacientes);
	fstream pacientes;
	pacientes.open(ruta_pac, ios::in);
	Paciente* Lista_paciente;
	int tamact_p = 0;
	
	
	Lista_paciente= LeerPacientes(pacientes, tamact_p); //funciona
	if (Lista_paciente == nullptr) 
	{
		cout << "hubo un error al leer los pacientes" << endl;
		return -1;
	}

	//cout << "-------------LISTA PACIENTES-----------" << endl;
	//Imprimir_Lista_pacientes(Lista_paciente, tamact_p);  //funciona




	string ruta_cons = (BASE_PATH + ArchConsultas);
	fstream Consultas;
	Consultas.open(ruta_cons, ios::in);
	Consulta* Lista_consultas;
	int tamact_cons = 0;

	Lista_consultas = LeerConsultas(Consultas, tamact_cons);
	if (Lista_consultas == nullptr) 
	{
		cout << "hubo un error al leer los consultas" << endl;
		return -1;
	}
	cout << endl<<endl;

	//cout << "----------LISTA CONSULTAS----------------"<<endl;
	//Imprimir_Lista_consultas(Lista_consultas, tamact_cons);

	
	
	string ruta_med = (BASE_PATH + ArchMedicos);
	fstream Medicos;
	Medicos.open(ruta_med, ios::in);
	Medico* lista_medicos;
	int tamact_med=0;

	lista_medicos = LeerMedicos(Medicos, tamact_med);
	if (lista_medicos == nullptr) 
	{
		cout << "hubo un error al leer los medicos" << endl;
		return -1;
	}

	//cout << "----------LISTA MEDICOS----------------" << endl;
	//Imprimir_Lista_Medicos(lista_medicos, tamact_med);


	string ruta_cont = (BASE_PATH + ArchContactos);
	fstream Contactos;
	Contactos.open(ruta_cont, ios::in);
	int tamact_cont=0;
	Contacto* lista_contactos;

	lista_contactos = LeerContactos(Contactos, tamact_cont);

	if (lista_contactos == nullptr)
	{
		cout << "hubo un error al leer los contactos" << endl;
		return -1;
	}
	cout << endl;
	//cout<<"----------LISTA CONTACTOS----------------" << endl;
	//
	//Imprimir_Lista_contactos(lista_contactos, tamact_cont); //si cambiamos el dni a int solo lee 7 contactos y si lo ponemos como string nos imprime con comas

	Buscar_Ultima_Consulta(Lista_paciente, Lista_consultas, tamact_p, tamact_cons);
	
	int tam_lista_retonrantes=0;
	Paciente* lista_actualizados = archivar(Lista_paciente, tamact_p, lista_medicos, tamact_med, tam_lista_retonrantes);

	//Buscar_contacto(lista_actualizados,tamact_p,lista_contactos,tamact_cont); //le asigna a los pacientes sus datos de contacto


	//cout << "Contactandose con el numero... " << lista_actualizados->contacto_p.cel << "..." << endl;
	//cout << "Si desea reprogramar un nuevo turno ingrese un 1: ";
	//int reprogramacion=rand()%1; //simulamos comunicacion con el usuario sin usar cin
	//Secretaria(lista_actualizados, reprogramacion, tam_lista_retonrantes);

		//push
	//cambio
	// system("pause");

	delete[]Lista_consultas;
	delete[]Lista_paciente;
	delete[]lista_contactos;
	delete[]lista_medicos;
	return 0;
}
