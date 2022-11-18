#include "datos.h"
#include <iostream>
#include <sstream>

using namespace std;

Paciente* LeerPacientes(string archivo_Pac)  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
{ 
	Paciente* Lista_pacientes = new Paciente[0];
	string headers;
	char delimitador = ' ';
	char delimitador_fecha= '/';
	Paciente aux;
	fstream pacientes;
	string linea;
	
	int tamact_p=0;
	pacientes.open(archivo_Pac, ios::in);

	if (!(pacientes.is_open()))
	{
		cout << "no se pudo abrir el archivo de pacientes" << endl;
		return nullptr;
	}

	getline(pacientes, headers);
	//pacientes >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;//simepre vamos a saber la cantidad de variables es decir N
	string coma, dni, nombre, apellido, sexo, estado, id, dia, mes, anio;
	while (getline(pacientes, linea))
	{
		stringstream stream(linea);

		//------------------leemos el archivo--------------------
		//pacientes >> aux.dni>>coma >> aux.nombre>>coma >> aux.apellido>>coma >> aux.sexo>>coma >> fecha >> coma >> aux.estado_paciente >> coma >> aux.id_os;
		
		// Extraer todos los valores de esa fila		
		getline(stream,dni, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, nombre, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, apellido, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, sexo, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, mes, delimitador_fecha);
		getline(stream, coma, delimitador);
		getline(stream, dia, delimitador_fecha);
		getline(stream, coma, delimitador);
		getline(stream, anio, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, estado, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, id, delimitador);

		aux.dni = dni;
		aux.nombre = nombre;
		aux.apellido = apellido;
		aux.sexo = sexo;

		stringstream aux_fechas(dia);
		aux_fechas>>aux.fechaingreso.tm_mday;
		stringstream aux_fechas1(mes);
		aux_fechas1 >> aux.fechaingreso.tm_mon;
		stringstream aux_fechas2(anio);
		aux_fechas2 >> aux.fechaingreso.tm_year;

		aux.estado_paciente = estado;
		aux.id_os = id;

		//----------------Agregamos a la lista ----------------------
		Agregar(Lista_pacientes, aux, &tamact_p);

	}
	pacientes.close();
	//------------------Repetimos para los otros archivos-----------------
	return Lista_pacientes;
}
Medico* LeerMedicos(string archivo_Med)
{
	fstream Arch_Medicos;
	string headers;
	char delimitador = ' ';
	char delimitador_fecha = '/';
	Medico aux;
	string linea;
	int tamact_m = 0;
	Medico* lista_medicos = new Medico[tamact_m];

	Arch_Medicos.open(archivo_Med, ios::in);
		if (!(Arch_Medicos.is_open()))
		{
			cout << "No se pudo abrir el archivo de Medicos" << endl;
			return nullptr;
		}

		getline(Arch_Medicos, headers);
		string coma, matricula, nombre, apellido, telefono, especialidad, activo;

		while (getline(Arch_Medicos, linea))
		{
			stringstream stream(linea);
			//matricula , nombre , apellido , telefono , especialidad , activo
			getline(stream, matricula, delimitador);
			getline(stream, coma, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, coma, delimitador);
			getline(stream, apellido, delimitador);
			getline(stream, coma, delimitador);
			getline(stream, telefono, delimitador);
			getline(stream, coma, delimitador);
			getline(stream, especialidad, delimitador),
			getline(stream, coma, delimitador);
			getline(stream, activo, delimitador);


			aux.matricula = matricula;
			aux.nombre = nombre;
			aux.telefono = telefono;
			aux.especialidad = especialidad;
			if (activo == "1")
				aux.activo = true;
			else
				aux.activo = false;

			Agregar_Medicos(lista_medicos, aux, &tamact_m);
		}

		return lista_medicos;
}
Contacto* LeerContactos(string archivo_Cont)
{
	fstream Arch_Contactos;
	string headers;
	char delimitador = ' ';
	char delimitador_fecha = '/';
	Medico aux;
	string linea;
	int tamact_m = 0;
	Medico* lista_medicos = new Medico[tamact_m];

	Arch_Contactos.open(archivo_Cont, ios::in);
	if (!(Arch_Contactos.is_open()))
	{
		cout << "No se pudo abrir el archivo de Contacos" << endl;
		return nullptr;
	}
	getline(Arch_Contactos, headers);
	//dni_paciente , telefono , celular , direccion , mail
	string coma, dni_paciente, telefono, celular, direccion, mail;

	while (getline(Arch_Contactos, linea))
	{
		getline(stream, dni_paciente, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, telefono, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, celular, delimitador);
		getline(stream, coma, delimitador);
		getline(stream, direccion, delimitador);
		\
		getline(stream, mail, delimitador
		getline(stream, coma, delimitador);
	}
}
void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Paciente* Lista_aux = new Paciente[*tam];

	if (Lista_pacientes == NULL)
		return;

	while (i < *tam-1)
	{
		Lista_aux[i] = Lista_pacientes[i];
		i++;
	}
	
	Lista_aux[i] = Datos_p;

	delete[] Lista_pacientes;
	Lista_pacientes = Lista_aux;
	

	return;
}


//void resize(Paciente*& lista_alu, int* tamactual, int cantidad_aumentar) 
//{
//	*tamactual = *tamactual + cantidad_aumentar;
//	int i = 0;
//	Paciente* aux = new Paciente[*tamactual];
//
//	while (i < *tamactual - cantidad_aumentar &&*tamactual-cantidad_aumentar!= 0)
//	{
//		aux[i] = lista_alu[i];
//		i++;
//	}
//	delete[] lista_alu;
//	lista_alu = aux;
//
//	return;
//}





void Agregar_obras(Obra_social*& lista_obra,Obra_social agregado, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Obra_social* Lista_aux = new Obra_social[*tam];

	if (lista_obra == NULL)
		return;

	while (i < *tam-1 && *tam-1 != 0)
	{
		Lista_aux[i] = lista_obra[i];
		i++;
	}
	
	Lista_aux[i] = agregado;
	delete[] lista_obra;
	lista_obra = Lista_aux;
	
	return;
}
void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Medico* Lista_aux = new Medico[*tam];

	if (lista_meds == NULL)
		return; 

	while (i < *tam-1 && *tam-1 != 0)
	{
		Lista_aux[i] = lista_meds[i];
		i++;
	}
	
	Lista_aux[i] = agregado;
	delete[] lista_meds;
	lista_meds = Lista_aux;
	
	return;
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
	i--;
	Lista_aux[i] = agregado;
	delete[] Lista_contactos;
	Lista_contactos = Lista_aux;
	
	return;
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
	i--;
	Lista_aux[i] = agregado;
	delete[] Lista_consultas;
	Lista_consultas = Lista_aux;
	
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
		archivados << "n_historialclinico,Nombre,Apellido,DNI,Sexo,Natalicio,Fecha de ingreso,Cobertura,Fecha ultima consulta,Medico ultima consulta,Diagnostico" << endl;
		archivados << paciente.historial_clinico.n_historialclinico << coma << paciente.nombre << coma << paciente.apellido << paciente.dni << coma << paciente.sexo << coma << paciente.natalicio.tm_mon << coma << paciente.natalicio.tm_wday << paciente.natalicio.tm_year << coma << paciente.fechaingreso.tm_mon <<"/"<< paciente.fechaingreso.tm_wday<<"/"<< paciente.fechaingreso.tm_year<< coma << paciente.id_os << coma << paciente.datos_uconsul.fecha_uconsulta << coma << paciente.datos_uconsul.dni_medico << coma << paciente.historial_clinico.especialidad << endl;
	}

}
void Imprimir_Lista(Paciente* lista)
{
	int i = 0;
	while (i <= sizeof(lista))
	{
		cout << "Dni: " << lista[i].dni << " Nombre: " << lista[i].nombre << " Apellido: " << lista[i].apellido << " Sexo: " << lista[i].sexo << " Natalicio: "<< lista[i].natalicio.tm_mon<<"/"<< lista[i].natalicio.tm_wday<<"/"<< lista[i].natalicio.tm_year << " Estado: " << lista[i].estado_paciente << " Cobertura: " << lista[i].id_os << endl;
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
		break;

	 default: 
		 cout << " invaind input" << endl;
		 break;
	}

}
void Secretaria(Paciente*& lista, int opcion)//habria que mandarle unicamente la lista de los pacientes posibles de volver, habria que quitar de la lista original los fallecidos y los que hace mas de 10 a�os no van
{
	for (int i = 0; i < sizeof(*lista); i++)
	{
		if (lista[i].datos_uconsul.reprogramacion == 1)
		{
			//Reprogramar_consulta(lista[i]);
			Cambio_Cobertura(lista[i], opcion);
			lista[i].retorna = true;
		}
		else
		{
			Escribir_Archivados(lista[i]);
			lista[i].datos_uconsul.reprogramacion = false;
			lista[i].retorna = false;
		}
	}
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
void Reprogramar_consulta(Paciente*& paciente)
{
	//Como el paciente quiere retornar, se le asigna una cunsulta.
	Fecha_random(paciente); //Funcion le coloca una fecha para la proxima cosulta random


	
}

