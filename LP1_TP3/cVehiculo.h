#pragma once
#include <string>
#include <iostream>
using namespace std;

class cOrgano;
class cReceptor;
class cINCUCAI;

class cVehiculo
{
	string Vehiculo;
public:
	cVehiculo(string vehiculo);
	virtual ~cVehiculo();
	virtual void RealizarTransporte(cReceptor* receptor, cOrgano* organo, cINCUCAI* incu) =0;
};

