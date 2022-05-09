#pragma once
#include <string>
#include <string.h>
#include <time.h>
#include "cPaciente.h"

using namespace std;

enum estado { estable, inestable };

class cReceptor :
    public cPaciente
{
    friend class cINCUCAI;
    tm EsperaDesde;
    int Prioridad;
    string Patologia;
    estado Estado;
    cOrgano* Organo_que_necesita;

public:
    cReceptor(tm espera, int prioridad, string patologia, estado state, cOrgano* organo, string dni,
    string nombre, string fecha, bool sexo, string telefono, bool rh, sangre gruposanguineo);  //recordar hacer la parte de constructor de la clase base
    ~cReceptor();
};

