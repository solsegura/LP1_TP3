#pragma once
#include <time.h>
#include "cPaciente.h"

class cDonante :
    public cPaciente
{
    tm Fallecimiento;
    tm Ablacion;
    cListaOrganos* lista_organos;

public:
    cDonante(tm fallecimiento, tm ablacion);
    ~cDonante();
};

