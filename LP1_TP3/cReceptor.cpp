#include "cReceptor.h"

cReceptor::cReceptor(tm espera, int prioridad, string patologia, estado state, string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac):cPaciente(dni, nombre, sexo, telefono, rh, gruposanguineo, centro,dia_nacimiento,mes_nac,anio_nac)
{
	this->EsperaDesde = espera;
	this->Prioridad = prioridad;
	this->Patologia = patologia;
	this->Estado = state;
	this->Organo_que_necesita = NULL;
}

cReceptor::~cReceptor()
{
}

void cReceptor::AgregarOrgano(cOrgano* organo)
{
	this->Organo_que_necesita = organo;
}
