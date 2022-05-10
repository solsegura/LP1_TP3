#include "cReceptor.h"

cReceptor::cReceptor(tm espera, int prioridad, string patologia, estado state, string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo):cPaciente(dni, nombre, fecha, sexo, telefono, rh, gruposanguineo)//falta hacer la parte de llamar al constructor de paciente
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
