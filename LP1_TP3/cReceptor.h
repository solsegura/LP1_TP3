#pragma once
#include <string>
#include <string.h>
#include <time.h>
#include "cPaciente.h"

using namespace std;


enum estado { estable, inestable };
enum prioridad{muy_leve, leve, grave, muy_grave};

class cReceptor :
    public cPaciente
{
    friend class cINCUCAI;
    tm EsperaDesde;
    prioridad Prioridad;
    string Patologia;
    estado Estado;
    cOrgano* Organo_que_necesita;

public:
    cReceptor(tm espera, prioridad Prioridadd, string patologia, estado state, string dni,
    string nombre, string fecha, bool sexo, string telefono, sangre gruposanguineo, cCentroDeSalud* centro, int dia_nacimiento, int mes_nac, int anio_nac);  //recordar hacer la parte de constructor de la clase base
    ~cReceptor();
    void setPrioridad(prioridad Prioridadd);
    void setEstado(estado Estadoo);
    void AgregarOrgano(cOrgano* organo);
    cOrgano* getOrgano();
};

