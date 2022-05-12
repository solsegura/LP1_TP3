#include "cHelicoptero.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"
using namespace std;

cHelicoptero::cHelicoptero(string id, string nombre):cVehiculo(nombre)
{
	this->ID = id;
}

cHelicoptero::~cHelicoptero()
{
}

void cHelicoptero::RealizarTransporte(cReceptor* receptor, cOrgano* organo)
{
	cout << "taca-taca-taca" << endl << "El helicóptero llegó a destino" << endl;
	receptor->getCentro()->RealizarTransplante(organo);
}
