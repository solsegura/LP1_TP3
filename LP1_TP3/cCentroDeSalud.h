#pragma once
#include <string>
#include "Template.h"
#define MAXPACIENTES 20
#define MAXVEHICULOS 5


using namespace std;

class cOrgano;
class cVehiculo;
class cPaciente;
class cReceptor;
class cDonante;
class cINCUCAI;
typedef cLista<cVehiculo> cListaVehiculo;
typedef cLista<cPaciente> cListaPacientes;


enum provincia{Buenos_Aires, CABA, Catamarca, Chaco, Chubut, Cordoba, Corrientes, Entre_Rios, Formosa, Jujuy, La_Pampa, La_Rioja, Mendoza, Misiones, Neuquen,Rio_Negro, Salta, San_Juan, San_Luis, Santa_Cruz, Santa_Fe, Santiago_Del_Estero, Tierra_Del_Fuego, Tucuman };

class cCentroDeSalud
{
	string Nombre;
	string Direccion;
	string Partido;
	string Telefono;
	provincia Provincia;
	cListaVehiculo* Lista_vehiculos;  
	cListaPacientes* Lista_pacientes; 
public:
	cCentroDeSalud(string nombre, string direccion, string partido, string telefono, provincia provincia, cListaVehiculo* vehiculos);
	~cCentroDeSalud();
	void AgregarPaciente(cPaciente* paciente_nuevo);
	void AsignarVehiculo(cReceptor* receptor, cOrgano* organo, cDonante* donante, cINCUCAI* incu);
	void RealizarAblacion(cDonante* donante, cOrgano* organo);
	void RealizarTransplante(cOrgano* organo);


};

