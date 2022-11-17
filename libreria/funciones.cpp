#include "datos.h"
#include <iostream>
using namespace std;

Paciente* LeerArchivo(string archivo)  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
{ 
	Paciente* Lista_pacientes = new Paciente[0];
	string header;
	Paciente aux;
	fstream pacientes;
	int tamact_p=0;
	pacientes.open(archivo, ios::in);

	if (!(pacientes.is_open()))
	{
		cout << "no se pudo abrir el archivo de pacientes" << endl;
		return nullptr;
	}

	char coma;
	pacientes >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;//simepre vamos a saber la cantidad de variables es decir N

	while (pacientes)
	{
		string fecha; //pruebo leer con un auxiliar la variable de tipo tm para que no tire error
		//------------------leemos el archivo--------------------
		pacientes >> aux.dni>>coma >> aux.nombre>>coma >> aux.apellido>>coma >> aux.sexo>>coma >> fecha >> coma >> aux.estado_paciente >> coma >> aux.id_os;

		//----------------Agregamos a la lista ----------------------
		Agregar(Lista_pacientes, aux, &tamact_p);
	}
	pacientes.close();
	
	/*fstream Arch_obras;
	Arch_obras.open("IRI_ObraSocial.csv", ios::in);
	if (!Arch_obras.is_open())
	{
		cout << "no se abrio el archivo de obra social" << endl;
		return;
	}
	
	Obra_social aux_o;
	Arch_obras >> header >> coma >> header;
	while (Arch_obras)
	{
		Arch_obras >> aux_o.id_obrasocial >> coma >> aux_o.obrasocial;
	
		Agregar_obras(lista_obras, aux_o, &tamactual_O);
	}
	Arch_obras.close();
	
	fstream Arch_Medicos;
	Arch_Medicos.open("IRI_Medicos.csv", ios::in);
	if (!Arch_Medicos.is_open())
	{
		cout << "no se abrio el archivo de Medicos" << endl;
		return;
	}
	
	Medico aux_m;
	Arch_Medicos >> header >> coma >> header>>coma>>header>>coma>>header>>coma>>header>>coma>>header;
	while (Arch_Medicos)
	{
		Arch_Medicos >> aux_m.matricula >> coma >> aux_m.nombre >> coma >> aux_m.apellido >> coma >> aux_m.telefono >> coma >> aux_m.especialidad >> coma >> aux_m.activo;
	
		Agregar_Medicos(lista_medicos, aux_m, &tamactual_Med);
	}
	Arch_Medicos.close();
	
	fstream Arch_Contactos;
	Arch_Contactos.open("IRI_Contactos.csv", ios::in);
	if (!Arch_Contactos.is_open())
	{
		cout << "no se abrio el archivo de contactos"<<endl;
		return;
	}
	
	Contacto aux_contacto;
	Arch_Contactos >> header >> coma >> header >> coma >> header >> coma >> header >> coma >> header;
	while (Arch_Contactos)
	{
		Arch_Contactos >> aux_contacto.dni >> coma >> aux_contacto.tel >> coma >> aux_contacto.cel >> coma >> aux_contacto.direccion >> coma >> aux_contacto.mail;
	
		Agregar_Contactos(lista_contactos, aux_contacto, &tamactual_contactos);
	}
	Arch_Contactos.close();
	
	fstream Arch_Consultas;
	Arch_Consultas.open("IRI_Constultas.csv", ios::in);
	if (!Arch_Consultas.is_open())
	{
		cout << "No se pudo abrir el archivo de consultas" << endl;
		return;
	}
	Consulta aux_consulta;
	
	Arch_Consultas >> header >> coma >> header >> coma >> header >> coma >> header >> header >> coma >> header;
	while (Arch_Consultas)
	{
		Arch_Consultas >> aux_consulta.dni >> coma >> aux_consulta.fecha_solicitado >> coma >> aux_consulta.fecha_turno >> coma >> aux_consulta.presento >> coma >> aux_consulta.matricula_med;
	
		Agregar_Consultas(lista_consultas, aux_consulta,& tamactual_consultas);
	}*/
}
void Agregar(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam)
{
	*tam=*tam+1;
	int i = 0;
	Paciente* Lista_aux = new Paciente[*tam];

	if (Lista_pacientes == NULL)
		return;

	while (i < *tam-1 && *tam-1 != 0)
	{
		Lista_aux[i] = Lista_pacientes[i];
		i++;
	}
	
	Lista_aux[i] = Datos_p;

	delete[] Lista_pacientes;
	Lista_pacientes = Lista_aux;
	

	return;
}
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
void Secretaria(Paciente*& lista, int opcion)//habria que mandarle unicamente la lista de los pacientes posibles de volver, habria que quitar de la lista original los fallecidos y los que hace mas de 10 años no van
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

