#pragma once
#include <time.h>
#include "cPaciente.h"

class cDonante :
    public cPaciente
{
    friend class cINCUCAI;
    tm Fallecimiento;
    tm Ablacion;
    cListaOrganos* lista_organos;  //hacerla en el constructor

public:
    cDonante(tm fallecimiento, tm ablacion, string dni, string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac);
    ~cDonante();
    void AgregarOrgano(cOrgano* organo);

};

