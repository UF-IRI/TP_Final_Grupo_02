#include "datos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//PACIENTES

Paciente* LeerPacientes(fstream& pacientes)  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
{
	Paciente* Lista_pacientes = new Paciente[0];
	string headers;	
	Paciente aux;	
	char coma = ',';
	char barra = '/';
	int tamact_p = 0;	

	if (!(pacientes.is_open()))
	{
		cout << "no se pudo abrir el archivo de pacientes" << endl;
		return nullptr;
	}

	getline(pacientes, headers);

	while (pacientes)
	{
		pacientes >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio.tm_mday >> barra >> aux.natalicio.tm_mon >> barra >> aux.natalicio.tm_year >> coma >> aux.estado_paciente >> coma >> aux.id_os;
		Agregar(Lista_pacientes, aux, &tamact_p);
	}
	pacientes.close();
	return Lista_pacientes;
}

void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Paciente* aux = new Paciente[*tam];

	if (Lista_pacientes == NULL)
		return;

	//Copiamos y agregamos a la lista al paciente
	while (i < *tam - 1 && *tam - 1 != 0)
	{
		aux[i] = Lista_pacientes[i];
		i++;
	}
	
	aux[i] = Datos_p;

	delete[] Lista_pacientes;
	Lista_pacientes = aux;

	return;
}


void Imprimir_Lista_pacientes(Paciente* lista)
{
	int i = 0;
	while (i <= 99)
	{
		cout << "Dni: " << lista[i].dni << " Nombre: " << lista[i].nombre << " Apellido: " << lista[i].apellido << " Sexo: " << lista[i].sexo << " Natalicio: "<< lista[i].natalicio.tm_mon<<"/"<< lista[i].natalicio.tm_mday<<"/"<< lista[i].natalicio.tm_year << " Estado: " << lista[i].estado_paciente << " Cobertura: " << lista[i].id_os << endl;
		i++;
	}
}

int DevolverFecha(Paciente paciente)
{
	int diferencia;
	int i = 0;
	time_t curr_time = time(NULL);
	tm* tm_local = localtime(&curr_time);

	time_t fecha_actual = mktime(tm_local);  //lo pasa a segundos
	time_t fecha_uconsul = mktime(&(paciente.natalicio));

	diferencia = difftime(fecha_actual, fecha_uconsul);

	return diferencia;
}





//CONSULTAS

U_consulta* LeerConsultas(fstream& consultas)
{
	U_consulta* Lista_consultas = new U_consulta[0];
	string headers;
	U_consulta aux;
	char coma = ',';
	char barra = '/';
	int tamact_p = 0;

	if (!(consultas.is_open()))
	{
		cout << "no se pudo abrir el archivo de pacientes" << endl;
		return nullptr;
	}

	getline(consultas, headers);

	while (consultas)
	{
		consultas>> aux.dni_pac >> coma >> aux.fecha_solicitado.tm_mday >> barra >> aux.fecha_solicitado.tm_mon >> barra >> aux.fecha_solicitado.tm_year >>coma>> aux.fecha_turno.tm_mday >> barra >> aux.fecha_turno.tm_mon >> barra >> aux.fecha_solicitado.tm_year >> coma >> aux.matriula_med;
		Agregar_Consultas(Lista_consultas, aux, &tamact_p);
	}
	consultas.close();
	return Lista_consultas;	
}



void Agregar_Consultas(U_consulta*& Lista_consultas, U_consulta agregado, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	U_consulta* Lista_aux = new U_consulta[*tam];

	if (Lista_consultas == NULL)
		return;

	while (i < *tam-1 && *tam-1 != 0)
	{
		Lista_aux[i] = Lista_consultas[i];
		i++;
	}
	Lista_aux[i] = agregado;
	delete[] Lista_consultas;
	Lista_consultas = Lista_aux;
	
	return;
}



void Imprimir_Lista_consultas(U_consulta* lista)
{
	int i = 0;
	while (i <= 990)
	{
		cout << "Dni: " << lista[i].dni_pac << " Fecha_solicitada: " << lista[i].fecha_solicitado.tm_mday << "/" << lista[i].fecha_solicitado.tm_mon << "/" << lista[i].fecha_solicitado.tm_year << " Fecha_turno: " << lista[i].fecha_turno.tm_mday << "/" << lista[i].fecha_turno.tm_mon << "/" << lista[i].fecha_turno.tm_year << " Matricula_med:" << lista[i].matriula_med<<endl;
		i++;
	}	
}








////Medico* LeerMedicos(string archivo_Med)
////{
////	fstream Arch_Medicos;
////	string headers;
////	char delimitador = ' ';
////	char delimitador_fecha = '/';
////	Medico aux;
////	string linea;
////	int tamact_m = 0;
////	Medico* lista_medicos = new Medico[tamact_m];
////
////	Arch_Medicos.open(archivo_Med, ios::in);
////		if (!(Arch_Medicos.is_open()))
////		{
////			cout << "No se pudo abrir el archivo de Medicos" << endl;
////			return nullptr;
////		}
////
////		getline(Arch_Medicos, headers);
////		string coma, matricula, nombre, apellido, telefono, especialidad, activo;
////
////		while (getline(Arch_Medicos, linea))
////		{
////			stringstream stream(linea);
////			//matricula , nombre , apellido , telefono , especialidad , activo
////			getline(stream, matricula, delimitador);
////			getline(stream, coma, delimitador);
////			getline(stream, nombre, delimitador);
////			getline(stream, coma, delimitador);
////			getline(stream, apellido, delimitador);
////			getline(stream, coma, delimitador);
////			getline(stream, telefono, delimitador);
////			getline(stream, coma, delimitador);
////			getline(stream, especialidad, delimitador),
////			getline(stream, coma, delimitador);
////			getline(stream, activo, delimitador);
////
////
////			aux.matricula = matricula;
////			aux.nombre = nombre;
////			aux.apellido = apellido;
////			aux.telefono = telefono;
////			aux.especialidad = especialidad;
////			if (activo == "1")
////				aux.activo = true;
////			else
////				aux.activo = false;
////
////			Agregar_Medicos(lista_medicos, aux, &tamact_m);
////		}
////
////		return lista_medicos;
//////}
////Contacto* LeerContactos(string archivo_Cont)
////{
////	fstream Arch_Contactos;
////	string headers;
////	char delimitador = ' ';
////	char delimitador_fecha = '/';
////	Contacto aux;
////	string linea;
////	int tamact_c = 0;
////	Contacto* lista_contactos = new Contacto[tamact_c];
////
////	Arch_Contactos.open(archivo_Cont, ios::in);
////	if (!(Arch_Contactos.is_open()))
////	{
////		cout << "No se pudo abrir el archivo de Contactos" << endl;
////		return nullptr;
////	}
////	getline(Arch_Contactos, headers);
////	//dni_paciente , telefono , celular , direccion , mail
////	string coma, dni_paciente, telefono, celular, direccion, mail;
////
////	while (getline(Arch_Contactos, linea))
////	{
////		stringstream stream(linea);
////
////		getline(stream, dni_paciente, delimitador);
////		getline(stream, coma, delimitador);
////		getline(stream, telefono, delimitador);
////		getline(stream, coma, delimitador);
////		getline(stream, celular, delimitador);
////		getline(stream, coma, delimitador);
////		getline(stream, direccion, delimitador);
////		getline(stream, coma, delimitador);
////		getline(stream, mail, delimitador);
////
////		aux.dni = dni_paciente;
////		aux.tel = telefono;
////		aux.cel = celular;
////		aux.direccion = direccion;
////		aux.mail = mail;
////		Agregar_Contactos(lista_contactos, aux, &tamact_c);
////	}
////}
//

//void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int* tam)
//{
//	*tam=*tam+1;
//	int i = 0;
//	Medico* Lista_aux = new Medico[*tam];
//
//	if (lista_meds == NULL)
//		return; 
//
//	while (i < *tam-1 && *tam-1 != 0)
//	{
//		Lista_aux[i] = lista_meds[i];
//		i++;
//	}
//	
//	Lista_aux[i] = agregado;
//	delete[] lista_meds;
//	lista_meds = Lista_aux;
//	
//	return;
//}
//void Agregar_Contactos(Contacto*& Lista_contactos, Contacto agregado, int* tam)
//{
//	*tam=*tam+1;
//	int i = 0;
//	Contacto* Lista_aux = new Contacto[*tam];
//
//	if (Lista_contactos == NULL)
//		return;
//
//	while (i < *tam-1 && *tam-1 != 0)
//	{
//		Lista_aux[i] = Lista_contactos[i];
//		i++;
//	}
//
//	Lista_aux[i] = agregado;
//	delete[] Lista_contactos;
//	Lista_contactos = Lista_aux;
//	
//	return;
//}

//int DevolverFecha(Paciente* Lista_pacientes)
//{
//	int diferencia;
//	int i = 0;
//	time_t curr_time = time(NULL);
//	tm* tm_local = localtime(&curr_time);
//
//	time_t fecha_actual = mktime(tm_local);  //lo pasa a segundos
//	time_t fecha_uconsul = mktime(&(Lista_pacientes[i].datos_uconsul.fecha_uconsulta));
//
//	diferencia = difftime(fecha_actual, fecha_uconsul);
//
//	return diferencia;
//}
//
////
////void Archivar(Paciente*& Lista_pacientes)
////{
////	int diferencia;
////	int i = 0;
////	//Si el tiempo que paso desde la ultima consulta del paciente y la fecha actvual es mayor a 10 y no concurrio se le archiva,
////	// Si es menor a 10 y no concurrio pero quiere reprogramar,se llama  a reprogramar paciente y se cambia la reprogramacion como true y tambin el retorna
////	//Si La diferencia de los anios es menor a 10 y no quiere retornar se archivan
////	do {
////		diferencia = DevolverFecha(Lista_pacientes[i]);
////		if (diferencia > 10 && Lista_pacientes[i].datos_uconsul.concurrio == false)
////		{
////			Lista_pacientes[i].archivado = true;
////			if (Lista_pacientes[i].datos_uconsul.dni_medico == Lista_pacientes[i].dni)
////				Escribir_Archivados(Lista_pacientes[i]);
////		}
////		else if (diferencia < 10 && Lista_pacientes[i].datos_uconsul.concurrio == false && Lista_pacientes[i].datos_uconsul.reprogramacion == false)
////		{
////			if (Lista_pacientes[i].estado_paciente != "n/c")
////				Lista_pacientes[i].archivado = true;
////			Escribir_Archivados(Lista_pacientes[i]);
////		}
////		else if (diferencia < 10 && Lista_pacientes[i].datos_uconsul.concurrio == false && Lista_pacientes[i].datos_uconsul.reprogramacion == true)
////		{
////			Lista_pacientes[i].archivado = false;
////			Lista_pacientes[i].retorna = true;
////		/*	Reprogramar_consulta(Lista_pacientes[i]);*/
////		}
////		i++;
////	} while (i <= sizeof(Lista_pacientes));
////}
//
//void Escribir_Archivados(Paciente paciente) //escribimos el archivo de output de pacientes que fueron archivados(no funciona) 
//{
//	char coma = ',';
//	fstream archivados;
//	archivados.open("Pacientes_Archivados.csv", ios::out); //escribe en un nuevo archivo llamado archivados 
//
//	if (!archivados.is_open())
//		return;
//
//	else
//	{		
//		archivados << "n_historialclinico,Nombre,Apellido,DNI,Sexo,Natalicio,Fecha de ingreso,Cobertura,Fecha ultima consulta,Medico ultima consulta,Diagnostico" << endl;
//		archivados << paciente.historial_clinico.n_historialclinico << coma << paciente.nombre << coma << paciente.apellido << paciente.dni << coma << paciente.sexo << coma << paciente.natalicio.tm_mon << coma << paciente.natalicio.tm_wday << paciente.natalicio.tm_year << coma << paciente.fechaingreso.tm_mon <<"/"<< paciente.fechaingreso.tm_wday<<"/"<< paciente.fechaingreso.tm_year<< coma << paciente.id_os << coma << paciente.datos_uconsul.fecha_uconsulta.tm_mday<<"/"<< paciente.datos_uconsul.fecha_uconsulta.tm_mon<<"/"<< paciente.datos_uconsul.fecha_uconsulta.tm_year << coma << paciente.datos_uconsul.dni_medico << coma << paciente.historial_clinico.especialidad << endl;
//	}
//
//}
////averiguar como hacer los archivos de output

//void Cambio_Cobertura(Paciente paciente, int opcion)
//{
//	switch (opcion)
//	{
//	 case 1:
//		paciente.cobertura = OSDE;
//		paciente.id_os = 1;
//		break;
//	 case 2:
//		paciente.cobertura = MEDICUS;
//		paciente.id_os = 2;
//		break;
//	 case 3:
//		paciente.cobertura = IOSFA;
//		paciente.id_os = 3;
//		break;
//	 case 4:
//		paciente.cobertura = ITALIANO;
//		paciente.id_os = 4;
//		break;
//	 case 5:
//		paciente.cobertura = ALEMAN;
//		paciente.id_os = 5;
//		break;
//	 case 6:
//		paciente.cobertura = ESPANYOL;
//		paciente.id_os = 6;
//		break;
//
//	 default: 
//		 cout << " invaind input" << endl;
//		 break;
//	}
//
//}
//void Secretaria(Paciente*& lista, int opcion)//habria que mandarle unicamente la lista de los pacientes posibles de volver, habria que quitar de la lista original los fallecidos y los que hace mas de 10 años no van
//{
//	for (int i = 0; i < sizeof(*lista); i++)
//	{
//		if (lista[i].datos_uconsul.reprogramacion == 1)
//		{
//			//Reprogramar_consulta(lista[i]);
//			Cambio_Cobertura(lista[i], opcion);
//			lista[i].retorna = true;
//		}
//		else
//		{
//			Escribir_Archivados(lista[i]);
//			lista[i].datos_uconsul.reprogramacion = false;
//			lista[i].retorna = false;
//		}
//	}
//}
//void Fecha_random(Paciente paciente)
//{
//	time_t rawtime;
//	struct tm* timeinfo;
//	time(&rawtime);
//	timeinfo = localtime(&rawtime);
//	tm* fecha_actual = timeinfo;
//
//	paciente.datos_uconsul.next_consul.tm_mday = rand() % (30 - fecha_actual->tm_mday) + fecha_actual->tm_mday;
//	paciente.datos_uconsul.next_consul.tm_mon = rand() % (12 - fecha_actual->tm_mon) + fecha_actual->tm_mon;
//	paciente.datos_uconsul.next_consul.tm_year = rand() % (2033 - fecha_actual->tm_year) + fecha_actual->tm_year;
//
//}
//void Reprogramar_consulta(Paciente paciente)
//{
//	//Como el paciente quiere retornar, se le asigna una cunsulta.
//	Fecha_random(paciente); //Funcion le coloca una fecha para la proxima cosulta random
//
//
//	
//}
//
