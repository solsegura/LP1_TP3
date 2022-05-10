#pragma once
#include <string>
#include <iostream>
using namespace std;

class cVehiculo
{
	string Vehiculo;
public:
	cVehiculo(string vehiculo);
	virtual ~cVehiculo();
	virtual void RealizarTransporte()=0;
};

