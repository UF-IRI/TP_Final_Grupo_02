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
	int dni;
	char sexo;
	int id_os;
	tm* natalicio;
	tm* fechaingreso;
	Cobertura cobertura;
	Diagnostico diagnostico_p;
	/*estado_historial historial;*/
	historial_clinico historial;
	string estado_paciente;
	bool archivado=false;

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

int DevolverFecha(U_consulta var); //Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual

void Escribir_Archivados(datos*& datasos);

void archivado(datos* dato);
