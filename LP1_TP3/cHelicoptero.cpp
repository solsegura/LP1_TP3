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
	cout << "taca-taca-taca" << endl << "El helic�ptero lleg� a destino" << endl;
	try {
		receptor->getCentro()->RealizarTransplante(organo);
	}
	catch (exception* e) {
		receptor->setPrioridad(muy_grave); //cambiamos la prioridad porque el transplante no fue 
		receptor->setEstado(inestable); //cambiamos el estado
		cout<<string(e->what())<<endl;
	}
}
