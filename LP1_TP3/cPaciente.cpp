#include "cPaciente.h"
#include "cFecha.h"

cPaciente::cPaciente()
{
	this->DNI = "0";
	this->Nombre = "0";
	this->Fecha = new cFecha();
	this->Sexo = false;
	this->Telefono = "0";
	this->GrupoSanguineo = ABN;
	this->Centro = NULL;

}

cPaciente::cPaciente(string dni, string nombre, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro,cFecha* nacimiento)
{
	this->DNI = dni;
	this->Nombre = nombre;
	this->Sexo = sexo;
	this->Telefono = telefono;
	this->GrupoSanguineo = gruposanguineo;
	this->Centro = centro;
	this->Fecha = nacimiento;
}


cPaciente::~cPaciente()
{
}

cCentroDeSalud* cPaciente::getCentro()
{
	return this->Centro;
}

sangre cPaciente::getSangre()
{
	return this->GrupoSanguineo;
}

string cPaciente::getNombre()
{
	return this->Nombre;
}
