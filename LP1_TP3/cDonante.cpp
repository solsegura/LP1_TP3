#include "cDonante.h"

cDonante::cDonante(tm fallecimiento, tm ablacion, string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac):cPaciente(dni, nombre, sexo, telefono, rh, gruposanguineo, centro,dia_nacimiento,mes_nac,anio_nac)
{
	this->Fallecimiento = fallecimiento;
	this->Ablacion = ablacion;
	
}

cDonante::~cDonante()
{
}

void cDonante::AgregarOrgano(cOrgano* organo)
{
	this->lista_organos->Agregar(organo);
}
