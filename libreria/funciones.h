#include <ctime>
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <array>

#define ArchPacientes "../data_files/input/IRI_Pacientes.csv" 
#define ArchConsultas "../data_files/input/IRI_Consultas.csv"
#define ArchMedicos "../data_files/input/IRI_Medicos.csv"
#define ArchContactos "../data_files/input/IRI_Contactos.csv"
#define Pacientes_Archivados "../data_files/output/IRI_Pacientes_archivados.txt"

using namespace std;


typedef struct  CONTACTO//tiene que haber un archivo con todos los contacto
{
	string nombre, apellido, mail, direccion, tel, cel,provincia, pais, dni;
	int ID, edad;	

} Contacto;

typedef struct CONSULTA 
{
	tm fecha_turno; //fecha ultima consulta
	tm fecha_solicitado;  //next consult
	string dni_pac;
	string matriula_med;
	bool reprogramacion;
	bool presento; //true si atendio el turno, false sino 
	string cobertura;
} Consulta;


typedef struct  PACIENTE
{
	string nombre;
	string apellido;
	string dni ;
	string sexo;
	tm natalicio;
	tm fechaingreso;
	string id_os;
	string estado_paciente; //internado,fallecido,vivo
	string cobertura;
	Consulta U_consulta;
	bool archivado;
	string retorna;
	Contacto contacto_p;
} Paciente;

typedef struct MEDICO
{
	string nombre, apellido;
	string matricula;
	string telefono;
	string especialidad;
	bool activo=false;

} Medico;


Paciente* LeerPacientes(fstream& pacientes, int &tamact_p);//leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam);
void Imprimir_Lista_pacientes(Paciente* lista, int tam);

Consulta* LeerConsultas(fstream& archivo_Cons, int& tamact_cons);
void Agregar_Consultas(Consulta*& Lista_consultas, Consulta agregado, int* tam);
void Imprimir_Lista_consultas(Consulta* lista, int tam);

Medico* LeerMedicos(fstream& Archivo_Med, int& tamact_med);
void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int* tam);
void Imprimir_Lista_Medicos(Medico* lista, int tam);

Contacto* LeerContactos(fstream& archivo_Cont, int& tamact_cont);
void Agregar_Contactos(Contacto*& Lista_contactos, Contacto agregado, int* tam);
void Imprimir_Lista_contactos(Contacto* lista, int tam);

int DevolverFecha(Consulta pacientes);//Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual

//se crea un archivo llamado "archivados" con aquellos pacientes que cumplan con la condicion de archivados
void Escribir_Archivados(Paciente* paciente, int tam_p, Medico* lista_medicos, int tam_m);

void Agregar_alistaretornantes(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam);

//cambia el estado archivado para los que corresponda
Paciente* archivar(Paciente*& Lista_pacientes, int tam_p, Medico* Lista_medicos, int tam_m, int& tam_lista_retornables);

Medico* Buscar_Medico(Medico* Lista_medicos, string matricula_medico, int tam_m);

//Se le pasa la lista de pacientes y si quieren repregramar se llama a reprogramar consulta, sino se archivan
void Secretaria(Paciente* lista_actualizada,int tam_Lista_retornantes);

//Cambia la cobertura del paciente si este decidio camviarla.
void Cambio_Cobertura(Paciente paciente);

//Reprograma la consulta del paciente, asignandole una fecha random para su prox consulta
void Reprogramar_consulta(Paciente& paciente);

//Busca dentro de la lista de consultas la ultima consulta de cada paciente y los guarda dentro de la variable "U_consulta
void Buscar_Ultima_Consulta(Paciente*& lista_p, Consulta* lista_c, int tam_p, int tam_c);
void Buscar_contacto(Paciente* lista_actualizados, int tamact_p, Contacto* lista_contactos, int tamact_cont);