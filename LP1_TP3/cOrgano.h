#pragma once
#include <string>
#include <time.h>
using namespace std;

class cOrgano
{
	string Organo;
	tm FechaAblacion;
public:
	cOrgano(string organo, tm fechaablacion);
	~cOrgano();

};

