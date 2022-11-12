#include "datos.h"
#include <iostream>
using namespace std;

datos* LeerArchivo(string nombre)  //leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS
{ 
	int tamact = 0;
	datos* Lista_pacientes = new datos[tamact];
	string header[6];
	datos aux;

	fstream pacientes;
	pacientes.open("IRI_Pacientes.csv", ios::in);

	if (!(pacientes.is_open()));
	return nullptr;

	char coma;
	pacientes >> header[0] >> coma >> header[1] >> coma >> header[2] >> coma >> header[3] >> coma >> header[4] >> coma >> header[5] >> coma >> header[6];//simepre vamos a saber la cantidad de variables es decir N

	while (pacientes)
	{
		//------------------leemos el archivo--------------------
		pacientes >> aux.paciente.dni>>coma >> aux.paciente.nombre>>coma >> aux.paciente.apellido>>coma >> aux.paciente.sexo>>coma >> aux.paciente.natalicio->tm_mday>> aux.paciente.natalicio->tm_mon>> aux.paciente.natalicio-> tm_year>>coma >> aux.paciente.estado_paciente>>coma >> aux.paciente.id_os;


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

	while (i < *tam && *tam  != 0)
	{
		Lista_aux[i] = Lista_pacientes[i];
		i++;
	}

	Lista_aux[i] = Datos_p;
	delete[] Lista_pacientes;
	Lista_pacientes = Lista_aux;

	return;
}

int DevolverFecha(U_consulta var)
{

	int anios = 0;

	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	tm* fecha_actual = timeinfo;

	int dias = 0;
	int dia = fecha_actual->tm_mday;
	int mes = fecha_actual->tm_mon + 1;
	int anio = fecha_actual->tm_year + 1900;

	long int dias1 = (anio * 365) + (mes * 30) + dia;
	long int dias2 = ((var.fecha_uconsulta->tm_year) * 365) + ((var.fecha_uconsulta->tm_mon) * 30) + var.fecha_uconsulta->tm_mday;
	dias = dias2 - dias1;

	anios = dias / 364;

	return anios;
}

void archivado(datos*& dato)
{
	int diferencia=DevolverFecha(dato->ultima_consulta);
	int i = 0;
	do {

		diferencia = DevolverFecha(dato[i].ultima_consulta);
		if (diferencia > 10 && dato[i].ultima_consulta.concurrio == false) {
			dato[i].paciente.archivado == true;
			if (dato[i].ultima_consulta.dni_medico==dato[i].paciente.dni)
			Escribir_Archivados(dato[i])
		}
		else if (diferencia < 10 && dato[i].ultima_consulta.concurrio == false && dato[i].ultima_consulta.reprogramacion == false)
		{
			if( dato[i].paciente.estado_paciente != "n/c")
			dato[i].paciente.archivado == true;

		}
		i++;
	} while (i <= sizeof(dato));
}

void Escribir_Archivados(datos* datasos)
{
	char coma = ',';
	fstream archivado;
	archivado.open("Pacientes_Archivados.csv", ios::out);
	if (!archivado.is_open())
		return;
	else {
		archivado << ""
	}


	

}



//void Mostrar(datos*& Lista_pacientes)
//{
//	int i = 0;
//	while (i < 10)
//	{
//
//		cout << Lista_pacientes[i].contacto << endl<< Lista_pacientes[i].;
//		i++;
//	}
//
//}