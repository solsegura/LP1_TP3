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
	cout << "taca-taca-taca" << endl << "El helic�ptero lleg� a destino" << endl;
}
