#include <ctime>
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

enum cobertura { OSDE = 1, MEDICUS, IOSFA, ITALIANO, ALEMAN, ESPANYOL }typedef Cobertura; //el hospital trabaja unicamnete con estas obras sociales 
enum estado_historial { vigente = 0, archivado } typedef Estado_historial;
enum estado_paciente { vivo = 0, internado, fallecido }typedef Estado_paciente;
enum Sexo { femenino, masculino }typedef sexo;
enum diagnostico { neurologia, kinesiologia, cardiologia, ginecologia, odontologia, dermatologia, pediatria, traumatologia, hemologia, fonoaudelogia, clinica }typedef Diagnostico;


//struct FEHCA {
//	tm tm_min, tm_max;
//}typedef Fecha;

struct CONTACTO //tiene que haber un archivo con todos los contacto
{
	string nombre, apellido, mail ,direccion, tel, cel, provincia, pais;
	int ID, edad, dni;

}typedef Contacto;

struct ULTIMA_CONSULTA  //tiene que haber un archivo con todos las ultimas consultas
{
	tm* fecha_uconsulta;
	int dni_medico, dni_paciente;
	int id_medico;
	tm* next_consul;
	bool reprogramacion;
	bool concurrio; //true si atendio el turno, false sino 
	Cobertura cobertura;

}typedef U_consulta;

struct PACIENTE //tiene que haber un archivo con todos los pacientes 
{
	string nombre;
	string apellido;
	int dni_paciente;
	sexo Sexo;
	int id_os;
	tm* natalicio;
	tm* fechaingreso;
	Cobertura cobertura;
	Estado_paciente estado_paciente;
	Diagnostico diagnostico_p;
	estado_historial historial;

}typedef Paciente;

struct MEDICO
{
	string nombre, apellido;
	int id;
	int dni_medico;
	Diagnostico especialidad;

}typedef Medico;

struct OBRA_SOCIAL
{
	int id_obrasocial;
	cobertura obrasocial;
};

struct HISTORIAL_CLINICO
{
	string especialidad;
	int n_historialclinico, numeropiso, numerocama; //numero piso y cama van a ser null salvo que internacion sea true
	Estado_historial estado_historial;
}typedef historial_clinico;

struct DATOS
{
	Paciente paciente;
	Contacto contacto;
	U_consulta ultima_consulta;
	Medico medico;
}typedef datos;



datos* LeerArchivo(string archivo_pacientes);//leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS

void Agregar(datos*& Lista_pacientes, datos Datos_p, int* tam);

int DevolverFecha(datos var); //Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual

//void Mostrar(datos*& Lista_pacientes);