#pragma once
#include <string>

using namespace std;

class cOrgano;
class cListaVehiculo;
class cListaPacientes;

enum provincia{Buenos_Aires, CABA, Catamarca, Chaco, Chubut, Cordoba, Corrientes, Entre_Rios, Formosa, Jujuy, La_Pampa, La_Rioja, Mendoza, Misiones, Neuquen,Rio_Negro, Salta, San_Juan, San_Luis, Santa_Cruz, Santa_Fe, Santiago_Del_Estero, Tierra_Del_Fuego, Tucuman };

class cCentroDeSalud
{
	string Nombre;
	string Direccion;
	string Partido;
	string Telefono;
	provincia Provincia;
	cListaVehiculo* Lista_vehiculos;  // template ndea
	cListaPacientes* Lista_pacientes;  //idem, ver como es lo de template
public:
	cCentroDeSalud(string nombre, string direccion, string partido, string telefono, provincia provincia, cListaVehiculo* vehiculos, cListaPacientes* pacientes);
	~cCentroDeSalud();
	void AsignarVehiculo(cReceptor* receptor, cDonante* donante, cOrgano* organo);
	void RealizarAblacion();
	void RealizarTransplante();

};

