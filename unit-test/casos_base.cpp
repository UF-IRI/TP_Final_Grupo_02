#include "gmock/gmock.h"
#include"datos.h"

namespace PacientTest::tests {
	
	TEST(Leer, prueba_agregar) {
		int tamanio=0;
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
	TEST(Leer, Prueba_resize)
	{

	}
	//TEST(Casos_Base, Test_Caso1) {
	//	Paciente paciente;
	//	paciente.datos_uconsul.fecha_uconsulta->tm_mday = 16;
	//	paciente.datos_uconsul.fecha_uconsulta->tm_mon = 11;
	//	paciente.datos_uconsul.fecha_uconsulta->tm_year = 2018;
	//
	//	ASSERT_THAT(DevolverFecha(paciente), 4);
	//}
	//
	//TEST(Casos_Base, Test_Caso2) {
	//	ASSERT_THAT(1, 1);
	//}

	//TEST(Casos_Base, Test_Caso3) {
	//	ASSERT_THAT(1, 1);
	//}
}