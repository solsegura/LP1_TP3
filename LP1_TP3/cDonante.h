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
    cDonante(tm fallecimiento, tm ablacion, string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo);
    ~cDonante();
};

