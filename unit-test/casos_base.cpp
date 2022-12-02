#include "gmock/gmock.h"
#include<funciones.h>

namespace PacientTest::tests {
	
	TEST(Leer, prueba_agregar) {
		int tamanio = 0;
		Paciente* lista_aux = new Paciente[tamanio];
		Paciente aux;
		aux.apellido = "Monteros";
		aux.dni = 45524255;
		aux.sexo = 'm';
		aux.archivado = false;
		aux.nombre = "Thiago";

		Agregar(lista_aux, aux, &tamanio);

		EXPECT_EQ(lista_aux[0].dni, aux.dni);
		EXPECT_EQ(tamanio, 1);
	}

	TEST(Devolverfecha, prueba_Devolver_fecha)
	{
		int diferencia = 0;
		Consulta consulta;
		consulta.fecha_turno.tm_mday = 2;
		consulta.fecha_turno.tm_mon = 11;
		consulta.fecha_turno.tm_year = 2002;

		diferencia = DevolverFecha(consulta);

		EXPECT_EQ(diferencia, 20);
	}

	/*TEST(BuscarMedico, prueba_buscar_medico)
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

		EXPECT_EQ(auxiliar, Lista[1]);

	}*/
}