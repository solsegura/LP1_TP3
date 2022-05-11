#include "cOrgano.h"

cOrgano::cOrgano(string organo)
{
	this->Organo = organo;
	time_t t = 0;
	this->FechaAblacion.tm_year = 0;
	this->FechaAblacion.tm_mday = 0;
	this->FechaAblacion.tm_hour = 0;
	this->FechaAblacion.tm_mon = 0;
	this->FechaAblacion.tm_min = 0;
	this->FechaAblacion.tm_sec = 0;
	this->FechaAblacion.tm_isdst = 0;
	this->FechaAblacion.tm_wday = 0;




}

cOrgano::~cOrgano()
{
}
