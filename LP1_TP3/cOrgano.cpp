#include "cOrgano.h"
#include "cFecha.h"

cOrgano::cOrgano(string organo)
{
	this->Organo = organo;
	time_t t = 0;
	this->FechaAblacion = new cFecha();
}

cOrgano::~cOrgano()
{
	delete FechaAblacion;
}

void cOrgano::setFechaAblacion()
{
	this->FechaAblacion->SetHoy();
}
