#pragma once
#include <string>
#include <string.h>
#include "Template.h"

// prioridad ddada por un enum (urgente, meh, muy urgente, puede esperar, tira pa rato)
using namespace std;
enum sangre { OP, AP, BP, ABP, ON, AN, BN, ABN};

class cOrgano;
class cCentroDeSalud;
class cFecha;
typedef cLista<cOrgano> cListaOrganos;

class cPaciente
{
	friend class cINCUCAI;
	string DNI;
	string Nombre;
	cFecha* Fecha; //ver si usar tipo de dato time
	bool Sexo;
	string Telefono;
	sangre GrupoSanguineo;
	cCentroDeSalud* Centro;

public:
	cPaciente(); //por defecto
	cPaciente(string dni, string nombre, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, cFecha* nacimiento);
	virtual ~cPaciente();
	virtual void AgregarOrgano(cOrgano* organo) = 0;
	cCentroDeSalud* getCentro();
	sangre getSangre();
	string getNombre();
	//string To_string();
	
};


