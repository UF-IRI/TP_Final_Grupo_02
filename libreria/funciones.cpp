#include "funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//PACIENTES

Paciente* LeerPacientes(fstream& pacientes, int &tamact_p)  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
{
	Paciente* Lista_pacientes = new Paciente[0];
	string headers;	
	Paciente aux;	
	char coma = ',';
	char barra = '/';
		

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


void Imprimir_Lista_pacientes(Paciente* lista, int tam)
{

	int i = 0;
	while (i< tam)
	{
		cout << "Dni: " << lista[i].dni << " Nombre: " << lista[i].nombre << " Apellido: " << lista[i].apellido << " Sexo: " << lista[i].sexo << " Natalicio: "<< lista[i].natalicio.tm_mon<<"/"<< lista[i].natalicio.tm_mday<<"/"<< lista[i].natalicio.tm_year << " Estado: " << lista[i].estado_paciente << " Cobertura: " << lista[i].id_os << endl;
		i++;
	}
}

//CONSULTAS

Consulta* LeerConsultas(fstream& consultas, int& tamact_cons)
{
	Consulta* Lista_consultas = new Consulta[0];
	string headers;
	Consulta aux;
	char coma = ',';
	char barra= '/';

	if (!(consultas.is_open()))
	{
		cout << "no se pudo abrir el archivo de pacientes" << endl;
		return nullptr;
	}

	getline(consultas, headers);

	while (consultas)
	{
		consultas >> aux.dni_pac >> coma >> aux.fecha_solicitado.tm_mday >> barra >> aux.fecha_solicitado.tm_mon >> barra >> aux.fecha_solicitado.tm_year >>coma>> aux.fecha_turno.tm_mday >> barra >> aux.fecha_turno.tm_mon >> barra >> aux.fecha_turno.tm_year >> coma >> aux.presento>>coma>>aux.matriula_med;
		Agregar_Consultas(Lista_consultas, aux, &tamact_cons);
	}
	consultas.close();
	return Lista_consultas;	
}


void Agregar_Consultas(Consulta*& Lista_consultas, Consulta agregado, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Consulta* Lista_aux = new Consulta[*tam];

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

void Imprimir_Lista_consultas(Consulta* lista, int tam)
{
	int i = 0;
	while (i < tam-1)
	{
		cout << "Dni: " << lista[i].dni_pac << " Fecha_solicitada: " << lista[i].fecha_solicitado.tm_mday << "/" << lista[i].fecha_solicitado.tm_mon << "/" << lista[i].fecha_solicitado.tm_year << " Fecha_turno: " << lista[i].fecha_turno.tm_mday << "/" << lista[i].fecha_turno.tm_mon << "/" << lista[i].fecha_turno.tm_year << " Matricula_med:" << lista[i].matriula_med<<endl;
		double dif = DevolverFecha(lista[i]);
		cout << "DIFERENCIA:" << dif<<endl;  //imprime 0 porque puede ser?
		i++; 
	}	
}

Medico* LeerMedicos(fstream& Archivo_Med, int& tamact_med)
{
	string headers;
	char coma;
	char delimitador = ' ';
	char delimitador_fecha = '/';
	Medico aux;
	Medico* lista_medicos = new Medico[tamact_med];

		if (!(Archivo_Med.is_open()))
		{
			cout << "No se pudo abrir el archivo de Medicos" << endl;
			return nullptr;
		}

		getline(Archivo_Med, headers);

		string activo;
		while (Archivo_Med)
		{
			Archivo_Med >> aux.matricula >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.telefono >> coma >> aux.especialidad >> coma >> activo;
			if (activo == "1")
				aux.activo = true;
			else
				aux.activo = false;

			Agregar_Medicos(lista_medicos, aux, &tamact_med);
		}
		Archivo_Med.close();

		return lista_medicos;
}
void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int* tam)
{
	*tam = *tam + 1;
	int i = 0;
	Medico* Lista_aux = new Medico[*tam];

	if (lista_meds == NULL)
		return;

	while (i < *tam - 1 && *tam - 1 != 0)
	{
		Lista_aux[i] = lista_meds[i];
		i++;
	}

	Lista_aux[i] = agregado;
	delete[] lista_meds;
	lista_meds = Lista_aux;

	return;
}
void Imprimir_Lista_Medicos(Medico* lista, int tam)
{
	int i = 0;
	while (i < tam-1)
	{
		cout << lista[i].matricula << " , " << lista[i].nombre << " , " << lista[i].apellido << " , " << lista[i].telefono << " , " << lista[i].especialidad << " , " << lista[i].activo << endl;
		i++;
	}
}



Contacto* LeerContactos(fstream& Archivo_Cont, int& tamact_cont)
{
	string headers;
	char coma;
	Contacto aux;
	Contacto* lista_contactos = new Contacto[tamact_cont];

	if (!(Archivo_Cont.is_open()))
	{
		cout << "No se pudo abrir el archivo de Contactos" << endl;
		return nullptr;
	}
	//dni_paciente , telefono , celular , direccion , mail

	getline(Archivo_Cont, headers);

	while (Archivo_Cont)
	{
		Archivo_Cont >> aux.dni>>coma>>aux.tel>>coma>>aux.cel>>coma>>aux.direccion>>coma>>aux.mail;
		
		Agregar_Contactos(lista_contactos, aux, &tamact_cont);
	}
	Archivo_Cont.close();
	return lista_contactos;
}



void Agregar_Contactos(Contacto*& Lista_contactos, Contacto agregado, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Contacto* Lista_aux = new Contacto[*tam];

	if (Lista_contactos == NULL)
		return;

	while (i < *tam-1 && *tam-1 != 0)
	{
		Lista_aux[i] = Lista_contactos[i];
		i++;
	}

	Lista_aux[i] = agregado;
	delete[] Lista_contactos;
	Lista_contactos = Lista_aux;
	
	return;
}
void Imprimir_Lista_contactos(Contacto* lista, int tam)
{
	int i = 0;

	while (i < tam-1)
	{
		cout << lista[i].dni << " , " << lista[i].tel << " , " << lista[i].cel << " , " << lista[i].direccion << " , " << lista[i].mail << endl;
		i++;
	}
}


int DevolverFecha(Paciente* Lista_pacientes)
{
	double diferencia;
	int i = 0;
	time_t curr_time = time(NULL);
	tm* tm_local = localtime(&curr_time);

	time_t fecha_actual = mktime(tm_local);  //lo pasa a segundos
	time_t fecha_uconsul = mktime(&(Lista_pacientes[i].U_consulta.fecha_turno));

	diferencia = difftime(fecha_actual, fecha_uconsul);

	return diferencia;
}


//void Archivar(Paciente*& Lista_pacientes)
//{
//	int diferencia;
//	int i = 0;
//	//Si el tiempo que paso desde la ultima consulta del paciente y la fecha actvual es mayor a 10 y no concurrio se le archiva,
//	// Si es menor a 10 y no concurrio pero quiere reprogramar,se llama  a reprogramar paciente y se cambia la reprogramacion como true y tambin el retorna
//	//Si La diferencia de los anios es menor a 10 y no quiere retornar se archivan
//	do {
//		diferencia = DevolverFecha(Lista_pacientes[i]);
//		if (diferencia > 10 && Lista_pacientes[i].datos_uconsul.concurrio == false)
//		{
//			Lista_pacientes[i].archivado = true;
//			if (Lista_pacientes[i].datos_uconsul.dni_medico == Lista_pacientes[i].dni)
//				Escribir_Archivados(Lista_pacientes[i]);
//		}
//		else if (diferencia < 10 && Lista_pacientes[i].datos_uconsul.concurrio == false && Lista_pacientes[i].datos_uconsul.reprogramacion == false)
//		{
//			if (Lista_pacientes[i].estado_paciente != "n/c")
//				Lista_pacientes[i].archivado = true;
//			Escribir_Archivados(Lista_pacientes[i]);
//		}
//		else if (diferencia < 10 && Lista_pacientes[i].datos_uconsul.concurrio == false && Lista_pacientes[i].datos_uconsul.reprogramacion == true)
//		{
//			Lista_pacientes[i].archivado = false;
//			Lista_pacientes[i].retorna = true;
//		/*	Reprogramar_consulta(Lista_pacientes[i]);*/
//		}
//		i++;
//	} while (i <= sizeof(Lista_pacientes));
//}

 
 
 
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
 
 
 
//void Secretaria(Paciente* lista_actualizada, int opcion)    en el main hacer paciente Lista= Actualizar_listap y esa lista se la pasamos a la funcion secretaria
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

Paciente* Actualizar_listap(Paciente* lista_pacientes, int tam) //la llamamos luego de llamar a la funcion archivar
{	
	Paciente* Lista_actualizada = new Paciente[tam];

	for (int i = 0;i < tam; i++)
	{
		Lista_actualizada[i] = lista_pacientes[i];	
	}
	return Lista_actualizada; //esta lista se la pasmaos a la secretaria, para pasarle aquellos pacientes que puedan llegar a volver 
}



void Reprogramar_consulta(Paciente paciente) //fijarse si funciona
{
	//Como el paciente quiere retornar, se le asigna una cunsulta.
	int diferencia = 0;
	int i = 0;
	time_t hoy = time(0);
	tm* aux = localtime(&hoy);

	paciente.U_consulta.fecha_turno.tm_mon = 1 + rand() % 11;//rand del 1 al 12 por los meses 
	paciente.U_consulta.fecha_turno.tm_mday = 1 + rand() % 29; //rand del 1 al 30 por los dias
	paciente.U_consulta.fecha_solicitado.tm_year = aux->tm_year + rand() % (aux->tm_year + 2);

	if (paciente.U_consulta.fecha_turno.tm_mon == 2 && paciente.U_consulta.fecha_turno.tm_mday > 28)//si justo mes == 02 volver a hacer un random del dia entre 1 y 28
		paciente.U_consulta.fecha_turno.tm_mday = 1 + rand() % 28;
	if (paciente.U_consulta.fecha_turno.tm_mon < aux->tm_mon && paciente.U_consulta.fecha_solicitado.tm_year == aux->tm_year)//si el mes generado aleatoriamente es menor al mes actual y al a�o que se genero es el mismo, como el turno ya habria pasado tengo que sumarle uno al a�o
		paciente.U_consulta.fecha_solicitado.tm_year = paciente.U_consulta.fecha_solicitado.tm_year + 1;

}

double DevolverFecha(Consulta paciente)
{
	double diferencia = 0;
	int i = 0;
	time_t hoy = time(0);
	tm* aux = localtime(&hoy);

	time_t fecha_actual = mktime(aux);  //lo pasa a segundos
	time_t fecha_uconsul = mktime(&(paciente.fecha_turno));

	diferencia = difftime(fecha_actual, fecha_uconsul);

	return diferencia;
}

void Buscar_Ultima_Consulta(Paciente*& lista_p, Consulta* lista_c, int tam_p, int tam_c)
{
	int i=0;
	int j=0;

	lista_p[0].U_consulta = lista_c[0];
	while (i < tam_p)
	{
		while (j < tam_c)
		{
			if (lista_p[i].dni == lista_c[j].dni_pac)
			{
				if (lista_p[i].U_consulta.fecha_turno.tm_year < lista_c[j].fecha_turno.tm_year)
				{
					lista_p[i].U_consulta = lista_c[j];
					break;
				}
				else if (lista_p[i].U_consulta.fecha_turno.tm_mon < lista_c[j].fecha_turno.tm_mon && lista_p[i].U_consulta.fecha_turno.tm_year == lista_c[j].fecha_turno.tm_year)
				{
					lista_p[i].U_consulta = lista_c[j];
					break;
				}
				else if (lista_p[i].U_consulta.fecha_turno.tm_mday < lista_c[j].fecha_turno.tm_mday && lista_p[i].U_consulta.fecha_turno.tm_mon < lista_c[j].fecha_turno.tm_mon && lista_p[i].U_consulta.fecha_turno.tm_year == lista_c[j].fecha_turno.tm_year)
				{
					lista_p[i].U_consulta = lista_c[j];
					break;
				}

			}
			j++;
		}
		i++;
	}
}