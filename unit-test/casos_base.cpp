#include "gmock/gmock.h"
#include<funciones.h>

namespace PacientTest::tests {

	TEST(Leer, prueba_agregar) {
		int tamanio = 0;
		Paciente* lista_aux = new Paciente[tamanio];
		Paciente aux;
		aux.apellido = "Monteros";
		aux.dni = "45524255";
		aux.sexo = 'm';
		aux.archivado = false;
		aux.nombre = "Thiago";

		Agregar(lista_aux, aux, &tamanio);

		EXPECT_EQ(lista_aux[0].dni, aux.dni);
		EXPECT_EQ(tamanio, 1);
	}

	TEST(Devolverfecha, prueba_Devolver_fecha)
	{
		double diferencia = 0;
		Consulta consulta;
		consulta.fecha_turno.tm_mday = 2;
		consulta.fecha_turno.tm_mon = 11;
		consulta.fecha_turno.tm_year = 2002;

		diferencia = DevolverFecha(consulta);

		EXPECT_EQ(diferencia, 20);
	}

	TEST(Busquedas, Buscar_medico)
	{

		Medico* Lista = new Medico[3];
		Lista[0].nombre = "Jacinta";
		Lista[0].apellido = "Ralston";
		Lista[0].activo = false;
		Lista[0].matricula = "03-957-5455";
		Lista[0].especialidad = "geriatria";
		Lista[0].telefono = " +54(929)89112253";
		Lista[1].nombre = "Victor";
		Lista[1].apellido = "Drew";
		Lista[1].activo = true;
		Lista[1].matricula = "04-726-6430";
		Lista[1].especialidad = "toxicologia";
		Lista[1].telefono = " +54(014)44587898";
		Lista[2].nombre = "Ivory";
		Lista[2].apellido = "Gonzales";
		Lista[2].activo = true;
		Lista[2].matricula = "06-445-0805";
		Lista[2].especialidad = "cardiologia";
		Lista[2].telefono = "+54(047)30321236";

		Medico* auxiliar = Buscar_Medico(Lista, "04-726-6430", 3);

		EXPECT_EQ(auxiliar->matricula, Lista[1].matricula);

	}
	TEST(Busquedas, Buscar_u_consulta)
	{
		int tamp = 3;
		int tamc = 6;

		Paciente* lista_p = new Paciente[tamp];
		Consulta* lista_c = new Consulta[tamc];

		lista_p[0].dni = "45524255";
		lista_p[1].dni = "45524258";
		lista_p[2].dni = "45524259";

		lista_c[0].fecha_turno.tm_mday = 23;
		lista_c[0].fecha_turno.tm_mon = 5;
		lista_c[0].fecha_turno.tm_year = 2009;
		lista_c[0].dni_pac = "45524255";
		lista_c[5].fecha_turno.tm_mday = 29;
		lista_c[5].fecha_turno.tm_mon = 5;
		lista_c[5].fecha_turno.tm_year = 2009;
		lista_c[5].dni_pac = "45524255";
		lista_c[1].fecha_turno.tm_mday = 23;
		lista_c[1].fecha_turno.tm_mon = 5;
		lista_c[1].fecha_turno.tm_year = 2017;
		lista_c[1].dni_pac = "45524258";
		lista_c[2].fecha_turno.tm_mday = 23;
		lista_c[2].fecha_turno.tm_mon = 5;
		lista_c[2].fecha_turno.tm_year = 2009;
		lista_c[2].dni_pac = "45524258";
		lista_c[3].fecha_turno.tm_mday = 23;
		lista_c[3].fecha_turno.tm_mon = 5;
		lista_c[3].fecha_turno.tm_year = 2009;
		lista_c[3].dni_pac = "45524259";
		lista_c[4].fecha_turno.tm_mday = 23;
		lista_c[4].fecha_turno.tm_mon = 6;
		lista_c[4].fecha_turno.tm_year = 2009;
		lista_c[4].dni_pac = "45524259";


		Buscar_Ultima_Consulta(lista_p, lista_c, tamp, tamc);

		//primer paciente, reconocible por el dia
		EXPECT_EQ(lista_p[0].U_consulta.fecha_turno.tm_mday, 29);
		EXPECT_EQ(lista_p[0].U_consulta.fecha_turno.tm_year, 2009);
		EXPECT_EQ(lista_p[0].U_consulta.fecha_turno.tm_mon, 5);
		//segundo paciente, reconocible por el anio
		EXPECT_EQ(lista_p[1].U_consulta.fecha_turno.tm_mday, 23);
		EXPECT_EQ(lista_p[1].U_consulta.fecha_turno.tm_year, 2017);
		EXPECT_EQ(lista_p[1].U_consulta.fecha_turno.tm_mon, 5);
		//tercer paciente, reconocible por el mes
		EXPECT_EQ(lista_p[2].U_consulta.fecha_turno.tm_mday, 23);
		EXPECT_EQ(lista_p[2].U_consulta.fecha_turno.tm_year, 2009);
		EXPECT_EQ(lista_p[2].U_consulta.fecha_turno.tm_mon, 6);
	}
}