#include "cPaciente.h"

cPaciente::cPaciente(string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo)
{
	this->DNI = dni;
	this->Nombre = nombre;
	this->Fecha = fecha;
	this->Sexo = sexo;
	this->Telefono = telefono;
	this->RH = rh;
	this->GrupoSanguineo = gruposanguineo;
}

cPaciente::~cPaciente()
{
}
