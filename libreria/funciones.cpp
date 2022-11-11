#include "datos.h"

using namespace std;

datos* LeerArchivo(string archivo_pacientes)  //leemos todos los archivos y guardamos todos los datos en una lista de tipo DATOS
{
	datos* Lista_pacientes = new datos[0];
	string header[6];
	Paciente aux;

	fstream pacientes;
	pacientes.open(archivo_pacientes, ios::in);

	if (!(pacientes.is_open()));
	return nullptr;

	char coma;
	pacientes >> header[0] >> coma >> header[1] >> coma >> header[2] >> coma >> header[3] >> coma >> header[4] >> coma >> header[5] >> coma >> header[6];//simepre vamos a saber la cantidad de variables es decir N

	while (archivo_pacientes)
	{
		//------------------leemos el archivo--------------------
		pacientes >> aux.dni >> aux.nombre >> aux.apellido >> aux.sexo >> aux.natalicio >> aux.estado_paciente >> aux.id_os;

		//----------------Agregamos a la lista ----------------------
		Agregar(Lista_pacientes, aux, &tamact);
	}

	Mostrar(Lista_pacientes);

	pacientes.close();
	return Lista_pacientes;
}




void Agregar(datos*& Lista_pacientes, datos datos_p, int* tam)
{
	*tam = *tam + 1;
	int = 0;
	datos* Lista_aux = datos[*tam];

	while (i < *tam - 1 && *tam - 1 != 0)
	{
		Lista_aux[i] = Lista_pacientes[i];
		i++;
	}

	Lista_aux[i] = datos_p;
	delete[] Lista_pacientes;
	Lista_pacientes = datos_p;

	return;
}

Fecha DevolverFecha(Fecha variable)
{
	istringstream fecha_minima("26/10/2002"), fecha_maxima("11/11/2022");
	fecha_minima >> get_time(&variable.tm_min, "mm/dd/yyyy");
	fecha_maxima >> get_time(&variable.tm_max, "mm/dd/yyyy");
	time_t time_min = mktime(&variable.tm_min),
		time_max = mktime(&variable.tm_max);
	return (rand() % (time_max - time_min) + time_min);
}



void Mostrar(datos*& Lista_pacientes)
{
	while (i < 10)
	{
		cout << Lista_pacientes[i] << endl;
	}

}