#include "cAmbulancia.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"
#include "cINCUCAI.h"

cAmbulancia::cAmbulancia(string patente, string nombre) :cVehiculo(nombre)
{
	this->Patente = patente;
}

cAmbulancia::~cAmbulancia()
{
}

void cAmbulancia::RealizarTransporte(cReceptor* receptor, cOrgano* organo, cINCUCAI* incu)
{
	cout << "iuiuiuiuiu" << endl << "La ambulancia llego a destino" << endl<<endl;
	try {
		receptor->getCentro()->RealizarTransplante(organo);
		cINCUCAI::TransplanteHecho(receptor, incu);
	}
	catch (exception* e) {
		receptor->setPrioridad(muy_grave); //cambiamos la prioridad porque el transplante no fue exitoso
		receptor->setEstado(inestable); //cambiamos el estado
		cout<< string(e->what())<<endl<<endl;
	}
}
