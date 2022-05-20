#include "cReceptor.h"
#include "cOrgano.h"
using namespace std;

cReceptor::cReceptor(prioridad Prioridadd, string patologia, estado state, string dni, string nombre, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, cFecha* nacimiento):cPaciente(dni, nombre, sexo, telefono, gruposanguineo, centro,nacimiento)
{
	this->EsperaDesde = NULL;
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

cOrgano* cReceptor::getOrgano()
{
	return this->Organo_que_necesita;
}

void cReceptor::setFechaEspera(cFecha* fecha)
{
	this->EsperaDesde = fecha;
}

string cReceptor::To_string()
{
	stringstream ss;
	ss << "Nombre: " << this->getNombre() << endl;
	ss << "Recibe: " << this->Organo_que_necesita->getNombreOrgano()<<endl;
	return ss.str();
}


