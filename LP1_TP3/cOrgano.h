#pragma once
#include <string>
#include <time.h>
using namespace std;

class cFecha;

class cOrgano
{
	string Organo;
	cFecha* FechaAblacion;
public:
	cOrgano(string organo);
	~cOrgano();
	cFecha* getFechaAblacion();
	void setFechaAblacion();
	string getNombreOrgano();
};

