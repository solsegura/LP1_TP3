#include "cAmbulancia.h"

cAmbulancia::cAmbulancia(string patente, string nombre) :cVehiculo(nombre)
{
	this->Patente = patente;
}

cAmbulancia::~cAmbulancia()
{
}

void cAmbulancia::RealizarTransporte()
{
	cout << "iuiuiuiuiu" << endl << "La ambulancia llegó a destino" << endl;
}
