#include "cAvion.h"

using namespace std;

cAvion::cAvion(string id, string nombre):cVehiculo(nombre)
{
	this->ID = id;
}

cAvion::~cAvion()
{
}

void cAvion::RealizarTransporte()
{
	cout << "zhooooooom" << endl << "El avi�n lleg� a destino" << endl;
}


