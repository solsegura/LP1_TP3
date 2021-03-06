#pragma once
#include "cVehiculo.h"
#include "cOrgano.h"
#include "cReceptor.h"

class cINCUCAI;

class cAmbulancia :
    public cVehiculo
{
    string Patente;
public:
    cAmbulancia(string patente, string nombre);
    ~cAmbulancia();
    void RealizarTransporte(cReceptor* receptor, cOrgano* organo, cINCUCAI* incu);
};

