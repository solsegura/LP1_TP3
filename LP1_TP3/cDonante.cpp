#include "cDonante.h"
#include "cOrgano.h"
#include "cReceptor.h"

cDonante::cDonante(tm fallecimiento, tm ablacion, string dni, string nombre, string fecha, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac):cPaciente(dni, nombre, sexo, telefono, gruposanguineo, centro,dia_nacimiento,mes_nac,anio_nac)
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

bool cDonante::operator==(cReceptor& receptor)
{
	for (int i = 0; i < this->lista_organos->getCant(); i++) {
		if ((*(this->lista_organos))[i]->getNombreOrgano() == receptor.getOrgano()->getNombreOrgano()&& this->getSangre() == receptor.getSangre()) 
				return true;
	}
	return false;
}
