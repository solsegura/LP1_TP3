#pragma once
#include <string>
#include <string.h>


using namespace std;
enum sangre { Cero, A, B, AB };

class cOrgano;
class cListaOrganos;

class cPaciente
{
	string DNI;
	string Nombre;
	string Fecha; //ver si usar tipo de dato time
	bool Sexo;
	string Telefono;
	bool RH;
	sangre GrupoSanguineo;

public:
	cPaciente(string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo);
	~cPaciente();
};


