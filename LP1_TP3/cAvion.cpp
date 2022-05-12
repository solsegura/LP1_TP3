#include "cAvion.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"

using namespace std;

cAvion::cAvion(string id, string nombre):cVehiculo(nombre)
{
	this->ID = id;
}

cAvion::~cAvion()
{
}

void cAvion::RealizarTransporte(cReceptor* receptor, cOrgano* organo)
{
	cout << "Zhooooooom" << endl << "El avión llegó a destino." << endl;
	receptor->getCentro()->RealizarTransplante(organo);
}


