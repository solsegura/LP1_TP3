#pragma once
#include <string>
#include <string.h>


using namespace std;
enum sangre { Cero, A, B, AB };

class cOrgano;
typedef cLista<cOrgano> cListaOrganos;

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
	virtual void popo(); //asi anda lo de ingresar paciente, se ve que necesita un virtual
	//necesitamos un metodo virtual PURO para que esta clase sea abstracta
};


