#include "cHelicoptero.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"
#include "cINCUCAI.h"

using namespace std;

cHelicoptero::cHelicoptero(string id, string nombre):cVehiculo(nombre)
{
	this->ID = id;
}

cHelicoptero::~cHelicoptero()
{
}

void cHelicoptero::RealizarTransporte(cReceptor* receptor, cOrgano* organo, cINCUCAI* incu)
{
	cout << "taca-taca-taca" << endl << "El helicoptero llego a destino" << endl<<endl;
	try {
		receptor->getCentro()->RealizarTransplante(organo);
		cINCUCAI::TransplanteHecho(receptor, incu);
	}
	catch (exception* e) {
		receptor->setPrioridad(muy_grave); //cambiamos la prioridad porque el transplante no fue 
		receptor->setEstado(inestable); //cambiamos el estado
		cout<<string(e->what())<<endl<<endl;
	}
}
