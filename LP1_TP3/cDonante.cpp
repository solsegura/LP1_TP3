#include "cDonante.h"

cDonante::cDonante(tm fallecimiento, tm ablacion, string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo):cPaciente(dni, nombre, fecha, sexo, telefono, rh, gruposanguineo)
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
