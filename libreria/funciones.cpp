#include "datos.h"
#include <iostream>
using namespace std;

Paciente* LeerArchivo(string nombre) //leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS
{
	int tamact = 0;
	Paciente* Lista_pacientes = new Paciente[tamact];
	string header[6];
	Paciente aux;

	fstream pacientes;
	pacientes.open("IRI_Pacientes.csv", ios::in);

	if (!(pacientes.is_open()))
		return nullptr;

	char coma;
	pacientes >> header[0] >> coma >> header[1] >> coma >> header[2] >> coma >> header[3] >> coma >> header[4] >> coma >> header[5] >> coma >> header[6];//simepre vamos a saber la cantidad de variables es decir N

	while (pacientes)
	{
		//------------------leemos el archivo--------------------
		pacientes >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio->tm_mday >> coma >> aux.natalicio->tm_mon>> coma >> aux.natalicio->tm_year>>coma >> aux.estado_paciente;//>> coma >> aux.id_os;


		//----------------Agregamos a la lista ----------------------
		Agregar(Lista_pacientes, aux, &tamact);
	}

	//Mostrar(Lista_pacientes);

	pacientes.close();
	return Lista_pacientes;
}





void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam)
{
	*tam = *tam + 1;
	int i = 0;
	Paciente* Lista_aux = new Paciente[*tam];

	while (i < *tam && *tam != 0)
	{
		Lista_aux[i] = Lista_pacientes[i];
		i++;
	}

	Lista_aux[i] = Datos_p;
	delete[] Lista_pacientes;
	Lista_pacientes = Lista_aux;

	return;
}

int DevolverFecha(Paciente var)
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
	long int dias2 = ((var.datos_uconsul.fecha_uconsulta->tm_year) * 365) + ((var.datos_uconsul.fecha_uconsulta->tm_mon) * 30) + var.datos_uconsul.fecha_uconsulta->tm_mday;
	dias = dias2 - dias1;

	anios = dias / 364;

	return anios;
}


void Archivar(Paciente*& Lista_pacientes)
{
	int diferencia;
	int i = 0;
	do {

		diferencia = DevolverFecha(Lista_pacientes[i]);
		if (diferencia > 10 && Lista_pacientes[i].datos_uconsul.concurrio == false)
		{
			Lista_pacientes[i].archivado = true;
			if (Lista_pacientes[i].datos_uconsul.dni_medico == Lista_pacientes[i].dni)
				Escribir_Archivados(Lista_pacientes[i]);
		}
		else if (diferencia < 10 && Lista_pacientes[i].datos_uconsul.concurrio == false && Lista_pacientes[i].datos_uconsul.reprogramacion == false)
		{
			if (Lista_pacientes[i].estado_paciente != "n/c")
				Lista_pacientes[i].archivado = true;
			//faltaria agregar en este caso tmb al archivo archivados?
		}
		i++;
	} while (i <= sizeof(Lista_pacientes));
}

void Escribir_Archivados(Paciente paciente) //archivamos las historias clinicas de los pacientes 
{
	char coma = ',';
	fstream archivados;
	archivados.open("Pacientes_Archivados.csv", ios::out); //escribe en un nuevo archivo llamado archivados 

	if (!archivados.is_open())
		return;

	else
	{
		archivados << "n_historialclinico,Nombre, Apellido,DNI,Sexo,Natalicio,Fecha de ingreso,Cobertura,Fecha ultima consulta,Medico ultima consulta,Diagnostico" << endl;
		archivados << paciente.historial.n_historialclinico << coma << paciente.nombre << coma << paciente.apellido << paciente.dni << coma << paciente.sexo << coma << paciente.natalicio << coma << paciente.fechaingreso << coma << paciente.id_os << coma << paciente.datos_uconsul.fecha_uconsulta << coma << paciente.datos_uconsul.dni_medico << coma << paciente.historial.diagnostico << endl;
	}

}

void Imprimir_Lista(Paciente*& lista)
{
	int i = 0;
	while (i <= sizeof(lista))
	{
		cout << "Dni: " << lista[i].dni << "Nombre: " << lista[i].nombre << " Apellido: " << lista[i].apellido << "Sexo: " << lista[i].sexo << "Natalicio: " << lista[i].natalicio->tm_mday << "-" << lista[i].natalicio->tm_mon << "-" << lista[i].natalicio->tm_year << "Estado: " << lista[i].estado_paciente << "Cobertura: " << lista[i].id_os << endl;
		i++;
	}
}


void Cambio_Cobertura(Paciente paciente, int opcion)
{
	switch (opcion)
	{
	case 1:
		paciente.cobertura = OSDE;
		paciente.id_os = 1;
		break;
	case 2:
		paciente.cobertura = MEDICUS;
		paciente.id_os = 2;
		break;
	case 3:
		paciente.cobertura = IOSFA;
		paciente.id_os = 3;
		break;
	case 4:
		paciente.cobertura = ITALIANO;
		paciente.id_os = 4;
		break;
	case 5:
		paciente.cobertura = ALEMAN;
		paciente.id_os = 5;
		break;
	case 6:
		paciente.cobertura = ESPANYOL;
		paciente.id_os = 6;

	default:
		break;
	}
}


void Secretaria(Paciente*& lista, int opcion)
{
	for (int i = 0; i < sizeof(*lista); i++)
	{
		if (lista[i].datos_uconsul.reprogramacion == 1)
		{
			Reprogramar_consulta(lista[i]);
			Cambio_Cobertura(lista[i], opcion);
			lista[i].retorna == true;
		}
		else
		{
			Escribir_Archivados(lista[i]);
			lista[i].datos_uconsul.reprogramacion == false;
			lista[i].retorna == false;
		}
	}
}

void Reprogramar_consulta(Paciente& paciente)
{
	//Aca se llamaria imprimir
	//se debe colocar la fecha de la proxima consulta
	
}

void Fecha_random(Paciente*& paciente)
{

	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	tm* fecha_actual = timeinfo;

	paciente->datos_uconsul.next_consul->tm_mday = rand() % (30 - fecha_actual->tm_mday) + fecha_actual->tm_mday;
	paciente->datos_uconsul.next_consul->tm_mon = rand() % (12 - fecha_actual->tm_mon) + fecha_actual->tm_mon;
	paciente->datos_uconsul.next_consul->tm_year = rand() % (2033 - fecha_actual->tm_year) + fecha_actual->tm_year;

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