#include "cDonante.h"
#include "cOrgano.h"
#include "cReceptor.h"
#define MAXORGANOS 9

//cDonante::cDonante()
//{
//
//}

cDonante::cDonante(cFecha* fallecimiento, string dni, string nombre, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro,cFecha* nacimiento):cPaciente(dni, nombre, sexo, telefono, gruposanguineo, centro,nacimiento)
{
	this->Fallecimiento = fallecimiento;
	this->lista_organos = new cListaOrganos(MAXORGANOS);
}

cDonante::~cDonante()
{
	delete lista_organos;
}

void cDonante::AgregarOrgano(cOrgano* organo)
{
	this->lista_organos->Agregar(organo);
}

string cDonante::To_string()
{
	stringstream ss;
	ss << "Nombre: "<<this->getNombre() << endl;
	ss << "Dona: ";
	for (int k = 0; k < this->lista_organos->getCant(); k++) {
		ss <<(*(this->lista_organos))[k]->getNombreOrgano() << ", ";
	}
	ss << endl;
	return ss.str();
}

bool cDonante::operator==(cReceptor& receptor)
{
	for (int i = 0; i < this->lista_organos->getCant(); i++) {
		if ((*(this->lista_organos))[i]->getNombreOrgano() == receptor.getOrgano()->getNombreOrgano()&& this->getSangre() == receptor.getSangre()) 
				return true;
	}
	return false;
}
