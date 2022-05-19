#pragma once
#include "cVehiculo.h"
#include "cOrgano.h"
#include "cReceptor.h"

using namespace std;


class cAvion :
    public cVehiculo
{
    string ID;
public: 
    cAvion(string id, string nombre);
    ~cAvion();
    void RealizarTransporte(cReceptor* receptor, cOrgano* organo);
};

