#include "cCentroDeSalud.h"
#include"cOrgano.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cVehiculo.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cHelicoptero.h"


cCentroDeSalud::cCentroDeSalud(string nombre, string direccion, string partido, string telefono, provincia provincia, cListaVehiculo* vehiculos, cListaPacientes* pacientes)
{
	this->Nombre = nombre;
	this->Direccion = direccion;
	this->Partido = partido;
	this->Telefono = telefono;
	this->Provincia = provincia;

}

void cCentroDeSalud::AsignarVehiculo(cReceptor* receptor, cOrgano* organo)
{
	if (receptor->getCentro()->Provincia == this->Provincia) {
		if (receptor->getCentro()->Partido == this->Partido) {
			for (int i = 0; i < this->Lista_vehiculos->getCant(); i++) {
				cAmbulancia* ambulancia = dynamic_cast<cAmbulancia*>((*(this->Lista_vehiculos))[i]);
				if (ambulancia != NULL) {
					//se encontro una ambulancia para hacer el traslado en el mismo partido
					break; //cierro el bucle porque ya tengo una ambulancia
				}
			}
		}
	}
}
