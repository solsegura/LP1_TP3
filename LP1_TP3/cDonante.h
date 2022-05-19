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
    tm Fallecimiento;
    tm Ablacion;
    cListaOrganos* lista_organos;  //hacerla en el constructor

public:
    //cDonante(); //defecto
    cDonante(tm fallecimiento, tm ablacion, string dni, string nombre, string fecha, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac);
    ~cDonante();
    void AgregarOrgano(cOrgano* organo);

    bool operator== (cReceptor& receptor);
};

