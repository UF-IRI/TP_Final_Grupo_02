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
	tm* fecha_solicitado;
	tm* fecha_turno;
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
	Cobertura id_os;
	historial_clinico historial_clinico;
	string estado_paciente; //internado,paciente,vivo
	int id_os;
	tm* natalicio;
	tm* fechaingreso;
	Cobertura cobertura;
	Diagnostico diagnostico_p;
	historial_clinico historial;
	string estado_paciente;
	bool archivado=false;
	U_consulta datos_uconsul;

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


datos* LeerArchivo(string archivo_pacientes);//leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS

int DevolverFecha(U_consulta var); //Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual

void Escribir_Archivados(Paciente*& datasos);

void archivado(Paciente* dato);

void Agregar_Pac(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam);

void Agregar_obras(Obra_social*& lista_obras,Obra_social agregado, int& tam);

void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int& tam);

void Agregar_Contactos(Contacto*& Lista_contactos, Contacto agregado, int& tam);

Paciente* LeerArchivo(string nombre);//leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS
void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam);
int DevolverFecha(Paciente var); //Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual
void Escribir_Archivados(Paciente paciente);//se crea un archivo llamado "archivados"con aquellos pacientes que cumplan con la condicion de archivados
void archivado(Paciente*& Lista_pacientes);//cambia el estado archivado para los que corresponda
void Agregar_Consultas(Consulta*& Lista_consultas, Consulta agregado, int& tam);