#pragma once
#include "cVehiculo.h"

class cHelicoptero :
    public cVehiculo
{
    string ID;
public:
    cHelicoptero(string id, string nombre);
    ~cHelicoptero();
    void RealizarTransporte();
};

