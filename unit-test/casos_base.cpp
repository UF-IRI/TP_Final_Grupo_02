#include "gmock/gmock.h"
#include"datos.h"

namespace PacientTest::tests {
	
	TEST(Casos_Base, Test_Caso1) {
		Paciente paciente;
		paciente.datos_uconsul.fecha_uconsulta->tm_mday = 16;
		paciente.datos_uconsul.fecha_uconsulta->tm_mon = 11;
		paciente.datos_uconsul.fecha_uconsulta->tm_year = 2018;

		ASSERT_THAT(DevolverFecha(paciente), 4);
	}

	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}
}