#include <ctime>
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

enum cobertura { OSDE = 1, MEDICUS, IOSFA, ITALIANO, ALEMAN, ESPANYOL }typedef Cobertura; //el hospital trabaja unicamnete con estas obras sociales 
//enum estado_historial { vigente = 0, archivado } typedef Estado_historial;
enum diagnostico { neurologia, kinesiologia, cardiologia, ginecologia, odontologia, dermatologia, pediatria, traumatologia, hemologia, fonoaudelogia, clinica }typedef Diagnostico;


struct CONTACTO //tiene que haber un archivo con todos los contacto
{
	string nombre, apellido, mail, direccion, tel, cel, provincia, pais;
	int ID, edad, dni;

}typedef Contacto;

struct ULTIMA_CONSULTA  //tiene que haber un archivo con todos las ultimas consultas
{
	tm* fecha_uconsulta;
	int dni_medico, dni_paciente;
	tm* next_consul;
	bool reprogramacion;
	bool concurrio; //true si atendio el turno, false sino 
	Cobertura cobertura;

}typedef U_consulta;

struct HISTORIAL_CLINICO
{
	string diagnostico;
	int n_historialclinico;
	//int numeropiso, numerocama; //extra para ver al final, si esta internado asignarles valores a numero piso y cama van a ser null salvo que internacion sea true
	
}typedef historial_clinico;

typedef struct CONSULTA {
	
	int dni;
	time_t fecha_solicitado;
	time_t fecha_turno;
	bool presento;
	string matricula_med;

}Consulta;

struct PACIENTE //tiene que haber un archivo con todos los pacientes 
{
	string nombre;
	string apellido;
	int dni;
	char sexo;
	time_t natalicio;
	time_t fechaingreso;
	int id_os;
	historial_clinico historial_clinico;
	string estado_paciente; //internado,paciente,vivo
	int id_os;
	tm* natalicio;
	tm* fechaingreso;
	Cobertura cobertura;
	Diagnostico diagnostico_p;
	historial_clinico historial;
	U_consulta datos_uconsul;
	string estado_paciente;
	bool archivado=false;
	bool retorna = false;

}typedef Paciente;

struct MEDICO
{
	string nombre, apellido;
	string matricula;
	string telefono;
	Diagnostico especialidad;
	bool activo;

}typedef Medico;

typedef struct OBRA_SOCIAL
{
	int id_obrasocial;
	cobertura obrasocial;
}Obra_social;

struct DATOS
{
	Paciente paciente;
	Contacto contacto;
	U_consulta ultima_consulta;
	Medico medico;
}typedef datos;

struct HISTORIAL_CLINICO
{
	string especialidad;
	int n_historialclinico, numeropiso, numerocama; //numero piso y cama van a ser null salvo que internacion sea true
	Estado_historial estado_historial;
}typedef historial_clinico;


void LeerArchivo(Paciente*& Lista_pacientes, int& tamact_p, Obra_social*& lista_obras, int& tamactual_O, Medico*& lista_medicos, int& tamactual_Med, Contacto*& lista_contactos, int& tamactual_contactos, Consulta*& lista_consultas, int& tamactual_consultas);  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo

void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam);

void Agregar_obras(Obra_social*& lista_obras,Obra_social agregado, int& tam);

void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int& tam);


int DevolverFecha(Paciente var); //Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual
void Escribir_Archivados(Paciente paciente);//se crea un archivo llamado "archivados"con aquellos pacientes que cumplan con la condicion de archivados
void Archivar(Paciente*& Lista_pacientes);//cambia el estado archivado para los que corresponda
void Imprimir_Lista(Paciente*& lista);
void Secretaria(Paciente*& lista,int opcion);
void Cambio_Cobertura(Paciente paciente, int opcion);
void Reprogramar_consulta(Paciente& paciente);
void Fecha_random(Paciente*& paciente);