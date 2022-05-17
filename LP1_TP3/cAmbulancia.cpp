#include "cAmbulancia.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"

cAmbulancia::cAmbulancia(string patente, string nombre) :cVehiculo(nombre)
{
	this->Patente = patente;
}

cAmbulancia::~cAmbulancia()
{
}

void cAmbulancia::RealizarTransporte(cReceptor* receptor, cOrgano* organo)
{
	cout << "iuiuiuiuiu" << endl << "La ambulancia llegó a destino" << endl;
	try {
		receptor->getCentro()->RealizarTransplante(organo);
	}
	catch (exception* e) {
		receptor->setPrioridad(muy_grave); //cambiamos la prioridad porque el transplante no fue 
		receptor->setEstado(inestable); //cambiamos el estado
		cout<< string(e->what())<<endl;
	}
}
