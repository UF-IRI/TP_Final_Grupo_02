#include "datos.h"
#include <iostream>
using namespace std;

void LeerArchivo(Paciente*& Lista_pacientes, int &tamact_p, Obra_social*& lista_obras, int &tamactual_O, Medico*& lista_medicos, int& tamactual_Med, Contacto*& lista_contactos, int& tamactual_contactos, Consulta*& lista_consultas,int& tamactual_consultas)  //leemos todos los archivos y guardamos todos los datos en una lista de cada tipo
{ 
	string header;
	Paciente aux;
	fstream pacientes;
	pacientes.open("IRI_Pacientes.csv", ios::in);

	if (!(pacientes.is_open()));
	return nullptr;

	char coma;
	pacientes >> header[0] >> coma >> header[1] >> coma >> header[2] >> coma >> header[3] >> coma >> header[4] >> coma >> header[5] >> coma >> header[6];//simepre vamos a saber la cantidad de variables es decir N

	while (pacientes)
	{
		//------------------leemos el archivo--------------------
		pacientes >> aux.dni>>coma >> aux.nombre>>coma >> aux.apellido>>coma >> aux.sexo>>coma >> aux.natalicio->tm_mday>> aux.natalicio->tm_mon>> aux.natalicio-> tm_year>>coma >> aux.estado_paciente>>coma >> aux.id_os;

		//----------------Agregamos a la lista ----------------------
		Agregar_Pac(Lista_pacientes, aux, &tamact);
	}
	pacientes.close();

	fstream Arch_obras;
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
		Arch_obras >> aux_o.obrasocial >> coma >> aux_o.id_obrasocial;

		Agregar_obras(lista_obras, aux_o, tamactual_O);
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

		Agregar_Medicos(lista_medicos, aux_m, tamactual_Med);
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

		Agregar_Contactos(lista_contactos, aux_contacto, tamactual_contactos);
	}
	Arch_Contactos.close();

	fstream Arch_Consultas;
	Arch_Consultas.opne("IRI_Constultas.csv", ios::in);
	if (!Arch_Consultas.is_open)
	{
		cout << "No se pudo abrir el archivo de consultas" << endl;
		return;
	}
	Consulta aux_consulta;
	//dni_pac,fecha_solicitado,fecha_turno,presento,matricula_med
	while (Arch_Consultas)
	{
		Arch_Consultas >> aux_consulta.dni >> coma >> aux_consulta.fecha_solicitado >> coma >> aux_consulta.fecha_turno >> coma >> aux_consulta.presento >> coma >> aux_consulta.matricula_med;

		Agregar_Consultas(lista_consultas,aux_consulta, tamactual_consultas)
	}
}




void Agregar_Pac(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam)
{
	*tam = *tam + 1;
	int i = 0;
	Paciente* Lista_aux = new Paciente[*tam];

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

void Agregar_obras(Obra_social*& lista_obra,Obra_social agregado, int& tam)
{
	tam ++;
	int i = 0;
	Obra_social* Lista_aux = new Obra_social[tam];

	while (i < tam && tam != 0)
	{
		Lista_aux[i] = lista_obra[i];
		i++;
	}

	Lista_aux[i] = agregado;
	delete[] lista_obra;
	lista_obra = Lista_aux;

	return;
}

void Agregar_Medicos(Medico*& lista_meds, Medico agregado, int& tam)
{
	tam++;
	int i = 0;
	Medico* Lista_aux = new Medico[tam];

	while (i < tam && tam != 0)
	{
		Lista_aux[i] = lista_meds[i];
		i++;
	}

	Lista_aux[i] = agregado;
	delete[] lista_meds;
	lista_meds = Lista_aux;

	return;
}
void Agregar_Contactos(Contacto*& Lista_contactos, Contacto agregado, int& tam)
{
	tam++;
	int i = 0;
	Contacto* Lista_aux = new Contacto[tam];

	while (i < tam && tam != 0)
	{
		Lista_aux[i] = Lista_contactos[i];
		i++;
	}

	Lista_aux[i] = agregado;
	delete[] Lista_contactos;
	Lista_contactos = Lista_aux;

	return;
}
void Agregar_Consultas(Consulta*& Lista_consultas, Consulta agregado, int& tam)
{
	tam++;
	int i = 0;
	Consulta* Lista_aux = new Consulta[tam];

	while (i < tam && tam != 0)
	{
		Lista_aux[i] = Lista_consultas[i];
		i++;
	}

	Lista_aux[i] = agregado;
	delete[] Lista_consultas;
	Lista_consultas = Lista_aux;

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

void archivado(Paciente*& dato)
{
	int diferencia=DevolverFecha(dato->ultima_consulta);
	int i = 0;
	do {

		diferencia = DevolverFecha(dato[i].ultima_consulta);
		if (diferencia > 10 && dato[i].ultima_consulta.concurrio == false) {
			dato[i].archivado == true;
			if (dato[i].ultima_consulta.dni_medico==dato[i].dni)
			Escribir_Archivados(dato[i].paciente.historial.)//pq no toma historial??
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



void Mostrar(datos*& Lista_pacientes)
{
	int i = 0;
	while (i < 10)
	{

		cout << Lista_pacientes[i].contacto << endl<< Lista_pacientes[i].;
		i++;
	}
}

