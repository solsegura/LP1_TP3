#pragma once
#include <time.h>
#include "cPaciente.h"
//#include "cReceptor.h"

class cReceptor;

class cDonante :
    public cPaciente
{
    friend class cINCUCAI;
    friend class cCentroDeSalud;
    cFecha* Fallecimiento;
    cListaOrganos* lista_organos;  

public:
    cDonante(cFecha* fallecimiento, string dni, string nombre, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, cFecha* nacimiento);
    ~cDonante();
    void AgregarOrgano(cOrgano* organo);
    string To_string();
    bool operator== (cReceptor& receptor);
};

