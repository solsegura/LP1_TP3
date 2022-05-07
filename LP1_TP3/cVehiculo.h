#pragma once

using namespace std;

enum tipo{ambulancia, helicoptero, avion};

class cVehiculo
{
	tipo Vehiculo;
public:
	cVehiculo(tipo vehiculo);
	~cVehiculo();
	void RealizarTransporte();
};

