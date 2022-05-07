#pragma once
#include <string>
#include <string.h>

using namespace std;

class cPaciente;
class cListaReceptores;
class cListaDonantes;
class cINCUCAI
{
	string Nombre;
	cListaDonantes* Lista_donantes;
	cListaReceptores* Lista_receptores;

public:
	cINCUCAI(string nombre);  //ver el optimo del 2 a ver que hacen con las listas
	~cINCUCAI();
	void RecibirPaciente(cPaciente* paciente_nuevo);
	void IngresarPaciente(cPaciente* paciente_nuevo);
	cListaReceptores* BuscarReceptores();
	cPaciente* ElegirReceptor();
	void IniciarProtocolo();
	int CantDonaciones();
};

