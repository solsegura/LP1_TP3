#pragma once
#include <string>
#include <string.h>
#include "Template.h"


using namespace std;
enum sangre { Cero, A, B, AB };

class cOrgano;
class cCentroDeSalud;
class cFecha;
typedef cLista<cOrgano> cListaOrganos;

class cPaciente
{
	string DNI;
	string Nombre;
	cFecha* Fecha; //ver si usar tipo de dato time
	bool Sexo;
	string Telefono;
	bool RH;
	sangre GrupoSanguineo;
	cCentroDeSalud* Centro;

public:
	cPaciente(string dni, string nombre, bool sexo, string telefono, bool rh, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac);
	virtual ~cPaciente();
	virtual void AgregarOrgano(cOrgano* organo) = 0;
	cCentroDeSalud* getCentro();
	//necesitamos un metodo virtual PURO para que esta clase sea abstracta
};


