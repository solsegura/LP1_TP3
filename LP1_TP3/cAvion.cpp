#include "cAvion.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"
#include "cFecha.h"


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
	try {
		receptor->getCentro()->RealizarTransplante(organo);
	}
	catch (exception* e) {
		e->what();
	}
}


