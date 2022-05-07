#include "cReceptor.h"

cReceptor::cReceptor(tm espera, int prioridad, string patologia, estado state, cOrgano* organo) //falta hacer la parte de llamar al constructor de paciente
{
	this->EsperaDesde = espera;
	this->Prioridad = prioridad;
	this->Patologia = patologia;
	this->Estado = state;
	this->Organo_que_necesita = organo;
}

cReceptor::~cReceptor()
{
}
