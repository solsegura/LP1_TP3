#include "cReceptor.h"
using namespace std;

cReceptor::cReceptor(tm espera, prioridad Prioridadd, string patologia, estado state, string dni, string nombre, string fecha, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac):cPaciente(dni, nombre, sexo, telefono, gruposanguineo, centro,dia_nacimiento,mes_nac,anio_nac)
{
	this->EsperaDesde = espera;
	this->Prioridad = Prioridadd;
	this->Patologia = patologia;
	this->Estado = state;
	this->Organo_que_necesita = NULL;
}

cReceptor::~cReceptor()
{
}

void cReceptor::setPrioridad(prioridad Prioridadd)
{
	this->Prioridad = Prioridadd;
}

void cReceptor::setEstado(estado Estadoo)
{
	this->Estado = Estadoo;
}

void cReceptor::AgregarOrgano(cOrgano* organo)
{
	this->Organo_que_necesita = organo;
}


