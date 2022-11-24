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

typedef struct  CONTACTO//tiene que haber un archivo con todos los contacto
{
	string nombre, apellido, mail, direccion, tel, cel, provincia, pais,dni;
	int ID, edad;

} Contacto;

typedef struct ULTIMA_CONSULTA 
{
	tm fecha_turno; //fecha ultima consulta
	tm fecha_solicitado;
	string dni_pac;
	string matriula_med;
	tm next_consul;
	bool reprogramacion;
	bool presento; //true si atendio el turno, false sino 
	Cobertura cobertura;
} U_consulta;

 typedef struct HISTORIAL_CLINICO
{
	string especialidad;
	int n_historialclinico; 

} historial_clinico;

typedef struct  PACIENTE
{
	string nombre;
	string apellido;
	string dni ;
	string sexo;
	tm natalicio;
	tm fechaingreso;
	string id_os;
	historial_clinico historial_clinico;
	string estado_paciente; //internado,paciente,vivo
	string cobertura;
	Diagnostico diagnostico_p;
	U_consulta datos_uconsul;
	bool archivado=false;
	bool retorna = false;

} Paciente;

typedef struct MEDICO
{
	string nombre, apellido;
	string matricula;
	string telefono;
	string especialidad;
	bool activo=false;

} Medico;


Paciente* LeerPacientes(fstream& pacientes);//leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam);
void Imprimir_Lista_pacientes(Paciente* lista);

U_consulta* LeerConsultas(fstream& archivo_Cons);
void Agregar_Consultas(U_consulta*& Lista_consultas, U_consulta agregado, int* tam);
void Imprimir_Lista_consultas(U_consulta* lista);


int DevolverFecha(U_consulta pacientes);////Devuelve la diferencia en anios desde la ultima consulta del paciente y la fecha actual


//Medico* LeerMedicos(string archivo_Med);
//Contacto* LeerContactos(string archivo_Cont);

//
////se crea un archivo llamado "archivados"con aquellos pacientes que cumplan con la condicion de archivados
//void Escribir_Archivados(Paciente paciente);
//
////cambia el estado archivado para los que corresponda
//void Archivar(Paciente*& Lista_pacientes);
//
////Agregamos a cada lista su correspondiente dato

//void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int* tam);
//void Agregar_Contactos(Contacto*& Lista_contactos, Contacto agregado, int* tam);


//
////Asigna a la prixima consulta del paciente una fecha random entre la (fecha actual) y unos anios mas adelante
//void Fecha_random(Paciente paciente);
//
////Imprimimos los datos de los pacientes
//void Imprimir_Lista(Paciente* lista);
//
////Se le pasa la lista de pacientes y si quieren repregramar se llama a reprogramar consulta, sino se archivan
//void Secretaria(Paciente*& lista,int opcion);
//
////Cambia la cobertura del paciente si este decidio camviarla.
//void Cambio_Cobertura(Paciente paciente, int opcion);
//
////Reprograma la consulta del paciente, asignandole una fecha para su prox consulta
//void Reprogramar_consulta(Paciente paciente);
//
//
