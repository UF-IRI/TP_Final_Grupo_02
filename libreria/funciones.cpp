#include "datos.h"
#include <iostream>
using namespace std;

datos* LeerArchivo(string archivo_pacientes)  //leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS
{
	datos* Lista_pacientes = new datos[0];
	string header[6];
	datos aux;
	int tamact = 0;
	fstream pacientes;
	pacientes.open(archivo_pacientes, ios::in);

	if (!(pacientes.is_open()));
	return nullptr;

	char coma;
	pacientes >> header[0] >> coma >> header[1] >> coma >> header[2] >> coma >> header[3] >> coma >> header[4] >> coma >> header[5] >> coma >> header[6];//simepre vamos a saber la cantidad de variables es decir N

	while (pacientes)
	{
		//------------------leemos el archivo--------------------
		pacientes >> aux.paciente.dni_paciente >> aux.paciente.nombre >> aux.paciente.apellido >> aux.paciente.Sexo >> aux.paciente.natalicio >> aux.paciente.id_os;

		//----------------Agregamos a la lista ----------------------
		Agregar(Lista_pacientes, aux, &tamact);
	}

	//Mostrar(Lista_pacientes);

	pacientes.close();
	return Lista_pacientes;
}




void Agregar(datos*& Lista_pacientes, datos Datos_p, int* tam)
{
	*tam = *tam + 1;
	int i = 0;
	datos* Lista_aux = new datos[*tam];

	while (i < *tam - 1 && *tam - 1 != 0)
	{
		Lista_aux[i] = Lista_pacientes[i];
		i++;
	}

	Lista_aux[i] = Datos_p;
	delete[] Lista_pacientes;
	Lista_pacientes = Lista_aux;

	return;
}

int DevolverFecha(datos var)
{

	int anios = 0;
	
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	tm* fecha_actual = timeinfo;

	int dias=0;
	int dia = fecha_actual->tm_mday;
	int mes = fecha_actual->tm_mon + 1;
	int anio = fecha_actual->tm_year + 1900;

	long int dias1 = (anio * 365) + (mes * 30) + dia;
	long int dias2 = ((var.ultima_consulta.fecha_uconsulta->tm_year) * 365) + ((var.ultima_consulta.fecha_uconsulta->tm_mon) * 30) + var.ultima_consulta.fecha_uconsulta->tm_mday;
	dias = dias2 - dias1;

	anios = dias / 364;

	return anios;
}

//void Mostrar(datos*& Lista_pacientes)
//{
//	int i = 0;
//	while (i < 10)
//	{
//		std::cout << Lista_pacientes[i] << endl;
//		i++;
//	}
//
//}