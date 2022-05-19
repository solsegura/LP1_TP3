#pragma once
#include "cVehiculo.h"
#include "cOrgano.h"
#include "cReceptor.h"

class cHelicoptero :
    public cVehiculo
{
    string ID;
public:
    cHelicoptero(string id, string nombre);
    ~cHelicoptero();
    void RealizarTransporte(cReceptor* receptor, cOrgano* organo);
};

