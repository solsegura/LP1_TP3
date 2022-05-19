#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "Template.h"

using namespace std;

class cReceptor;
class cDonante;
class cOrgano;
class cPaciente;
class cCentroDeSalud;

typedef cLista<cPaciente> cListaPacientes;
typedef cLista<cDonante> cListaDonantes;
typedef cLista<cReceptor> cListaReceptores;
typedef cLista<cOrgano> cListaOrganos;



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
	cListaReceptores* BuscarReceptores(cDonante* donante);
	cListaDonantes* BuscarDonantes(cReceptor* receptor);
	cReceptor* ElegirReceptor(cListaReceptores* sublista, cOrgano* organo_a_donar); //elige de la sublista de receptores, uno para un organo en particular del donante
	void IniciarProtocolo(cReceptor* receptor, cDonante* donante, cOrgano* organo);
	//sint CantDonaciones();

	cListaReceptores* FiltroReceptoresPorOrgano(cOrgano* organo);
	cListaReceptores* FiltroPorCentro(cCentroDeSalud* centro);
	void InformarPrioridad(cReceptor* receptor);

	string to_String();
	friend ostream& operator<<(ostream& out, cINCUCAI& incu);
};

