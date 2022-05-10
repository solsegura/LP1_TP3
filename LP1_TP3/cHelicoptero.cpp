#include "cHelicoptero.h"
using namespace std;

cHelicoptero::cHelicoptero(string id, string nombre):cVehiculo(nombre)
{
	this->ID = id;
}

cHelicoptero::~cHelicoptero()
{
}

void cHelicoptero::RealizarTransporte()
{
	cout << "taca-taca-taca" << endl << "El helicóptero llegó a destino" << endl;
}
