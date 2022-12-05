#include "funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


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
		//double dif = DevolverFecha(lista[i]);
		//cout << "DIFERENCIA:" << dif<<endl;
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

Paciente* archivar(Paciente*& Lista_pacientes,int tam_p, Medico* Lista_medicos, int tam_m,int& tam_lista_retornables)
{
	Paciente* Lista_retornantes = new Paciente[tam_lista_retornables];
	Medico* medico;
	double diferencia;
	string matricula_medico;
	for (int i = 0; i < tam_p; i++) //recorro lista consultas 
	{

		diferencia= DevolverFecha(Lista_pacientes[i].U_consulta); //obtengo la diferencia de las fechas para ver si pasaron 10 años
		matricula_medico = Lista_pacientes[i].U_consulta.matriula_med;//me guardo la matriula del medico y la busco en el archivo del medico
			
		if (diferencia > 10 && Lista_pacientes[i].U_consulta.presento == false)//si pasaron mas de 10 años y no se presento lo archivamos
		{
			Lista_pacientes[i].archivado = true; //archivo a ESE paciente
			medico=Buscar_Medico(Lista_medicos,matricula_medico,tam_m); //busco los datos del medico que atendio a ese paciente en su ultima consulta
			Escribir_Archivados(medico, Lista_pacientes[i]);
		}
		else if (diferencia < 10 && Lista_pacientes[i].U_consulta.presento == false)//si pasaron menos de 10 años, y no se presento ni reprogramo, archivo los fallecidos 
		{
			if (Lista_pacientes[i].estado_paciente == "fallecido") //escribir en el archivo archivados los fallecidos
			{
				Lista_pacientes[i].archivado = true;
				medico = Buscar_Medico(Lista_medicos, matricula_medico, tam_m);
				Escribir_Archivados(medico,Lista_pacientes[i]);
			}				
			else  //los internados o n/c podrian volver
			{
				Lista_pacientes[i].archivado = false;
				Agregar_alistaretornantes(Lista_retornantes, Lista_pacientes[i], &tam_lista_retornables); //lo agrego a una lista de posibles retornantes y esa es la que le vamos a pasar a secretaria 
			}						
		}
		else if (diferencia < 10 && Lista_pacientes[i].U_consulta.presento == true)
		{
			Lista_pacientes[i].archivado = false;					
			Agregar_alistaretornantes(Lista_retornantes, Lista_pacientes[i], &tam_lista_retornables);
		}				
	}
	return Lista_pacientes; //lista unicamente de posibles retornantes, esta es la que le vamos a pasar a la secretaria para que los contacte
}

 
void Agregar_alistaretornantes(Paciente*& Lista_pacientes, Paciente Datos_p, int* tam)
{
	*tam = *tam + 1;
	int i = 0;
	Paciente* Lista_posibles_retornantes = new Paciente[*tam];

	if (Lista_pacientes == NULL)
		return;

	//Copiamos y agregamos a la lista al paciente
	while (i < *tam - 1 && *tam - 1 != 0)
	{
		Lista_posibles_retornantes[i] = Lista_pacientes[i];
		i++;
	}

	Lista_posibles_retornantes[i] = Datos_p;

	delete[] Lista_pacientes;
	Lista_pacientes = Lista_posibles_retornantes;

	return;
}
 
Medico* Buscar_Medico(Medico* Lista_medicos, string matricula_medico, int tam_m)
{
	for (int i = 0; i < tam_m;i++)
	{
		if (Lista_medicos[i].matricula == matricula_medico)
			return &Lista_medicos[i];
	}
	return nullptr;
}

void Escribir_Archivados(Medico* medico, Paciente paciente) //escribimos el archivo de output de pacientes que fueron archivados(no funciona) 
{
	char coma = ',';
	fstream archivados;
	archivados.open("Hola_Que_Tal", ios::out); //escribe en un nuevo archivo llamado archivados 

	if (!archivados.is_open())
		return;

	else
	{
		archivados << "Nombre paciente, Apellido paciente, Dni paciente, ID_os, Nombre medico, Apellido medico, Teléfono de contacto medico, Matricula medico, especialidad" << endl;
		archivados << paciente.nombre<<coma<<paciente.apellido<<coma<<paciente.dni<<paciente.id_os<<coma<<medico->nombre << coma << medico->apellido << coma << medico->telefono << coma << medico->matricula << coma << medico->especialidad << endl;
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
//hola
  
 
void Secretaria(Paciente* lista_actualizada, int opcion,int tam_Lista_retornantes) //   en el main hacer paciente Lista= Actualizar_listap y esa lista se la pasamos a la funcion secretaria
{	
	int obra_social = 1 + rand() % 5; //simulamos un cambio de cobertura
	int i;
	for (i = 0; i < tam_Lista_retornantes; i++)
	{
		if (opcion == 1)
		{

			Cambio_Cobertura(lista_actualizada[i], obra_social);
			lista_actualizada[i].retorna = true;
			//return string=retorna
		}
		else
		{
			lista_actualizada[i].retorna = false;
			//return string=no retorna y en el mian hacemos cout<<secretaria() hacerla string 
		}
	}
}

void Reprogramar_consulta(Paciente& paciente) //fijarse de arreglar porque los años nos dan unicamnete tres digitos
{
	srand(time(NULL));

	double diferencia = 0;
	int i = 0;
	time_t hoy = time(0);
	struct std::tm fecha;

	std::istringstream ss(to_string(paciente.U_consulta.fecha_turno.tm_mday) + "/" + to_string(paciente.U_consulta.fecha_turno.tm_mon) + "/" + to_string(paciente.U_consulta.fecha_turno.tm_year) + " 00:00:00");

	ss >> std::get_time(&fecha, "%d/%m/%Y %H:%M:%S");

	paciente.U_consulta.fecha_turno.tm_mon = 1 + rand() % 11;//rand del 1 al 12 por los meses 
	paciente.U_consulta.fecha_turno.tm_mday = 1 + rand() % 29; //rand del 1 al 30 por los dias
	paciente.U_consulta.fecha_turno.tm_year = fecha.tm_year + rand() % (fecha.tm_year + 2);

	if (paciente.U_consulta.fecha_turno.tm_mon == 2 && paciente.U_consulta.fecha_turno.tm_mday > 28)//si justo mes == 02 volver a hacer un random del dia entre 1 y 28
		paciente.U_consulta.fecha_turno.tm_mday = 1 + rand() % 28;
	if (paciente.U_consulta.fecha_turno.tm_mon < fecha.tm_mon && paciente.U_consulta.fecha_solicitado.tm_year == fecha.tm_year)//si el mes generado aleatoriamente es menor al mes actual y al año que se genero es el mismo, como el turno ya habria pasado tengo que sumarle uno al año
		paciente.U_consulta.fecha_turno.tm_year = paciente.U_consulta.fecha_solicitado.tm_year + 1;
}

//creo que funciona bien 
double DevolverFecha(Consulta paciente)
{
	double diferencia = 0;
	int i = 0;
	time_t hoy = time(0);
	struct std::tm fecha;
	
	std::istringstream ss(to_string(paciente.fecha_turno.tm_mday) + "/" + to_string(paciente.fecha_turno.tm_mon) + "/" + to_string(paciente.fecha_turno.tm_year) + " 00:00:00");
	
	ss >> std::get_time(&fecha, "%d/%m/%Y %H:%M:%S");

	time_t fecha_uconsul = mktime(&fecha);

	diferencia = difftime(hoy, fecha_uconsul) / 31530000; //lo pasamos de seg a anios
	return diferencia;
	
}

void Buscar_Ultima_Consulta(Paciente*& lista_p, Consulta* lista_c, int tam_p, int tam_c)
{
	int i;
	int j=0;

	for (i = 0; i < tam_p; i++)
	{
		lista_p[i].U_consulta.fecha_turno.tm_year = 0;
		lista_p[i].U_consulta.fecha_turno.tm_mon = 0;   // inicializamos las fechas para saber que valor tienen si no son encontradas y para que funcione la busqueda por maxima fecha
		lista_p[i].U_consulta.fecha_turno.tm_mday = 0;
	}
	i = 0;
	while (i < tam_p)
	{

		while (j < tam_c)
		{
			if (lista_p[i].dni == lista_c[j].dni_pac)
			{
				if (lista_p[i].U_consulta.fecha_turno.tm_year < lista_c[j].fecha_turno.tm_year)
				{
					lista_p[i].U_consulta = lista_c[j];
				}
				else if (lista_p[i].U_consulta.fecha_turno.tm_mon < lista_c[j].fecha_turno.tm_mon && lista_p[i].U_consulta.fecha_turno.tm_year == lista_c[j].fecha_turno.tm_year)
				{
					lista_p[i].U_consulta = lista_c[j];
				}
				else if (lista_p[i].U_consulta.fecha_turno.tm_mday < lista_c[j].fecha_turno.tm_mday && lista_p[i].U_consulta.fecha_turno.tm_mon ==lista_c[j].fecha_turno.tm_mon && lista_p[i].U_consulta.fecha_turno.tm_year == lista_c[j].fecha_turno.tm_year)
				{
					lista_p[i].U_consulta = lista_c[j];
				}

			}
			j++;
		}
		j = 0;
		i++;
	}
}

void Buscar_contacto(Paciente* lista_actualizados, int tamact_p, Contacto* lista_contactos, int tamact_cont)
{
	for (int i = 0; i < tamact_p; i++)
	{
		lista_actualizados[i].contacto_p.cel = -1; //inicializamos todos los celulares de los contactos en -1 para saber cuando un contacto no es encontrado
	}

	for (int i = 0; i < tamact_p; i++)
	{
		for (int j = 0; j < tamact_cont; j++)
		{
			if (lista_actualizados[i].dni == lista_contactos[j].dni)
				lista_actualizados[i].contacto_p = lista_contactos[j];							
		}
	}

}