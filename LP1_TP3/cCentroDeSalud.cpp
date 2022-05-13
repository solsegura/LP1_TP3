#include "cCentroDeSalud.h"
#include"cOrgano.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cVehiculo.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cFecha.h"
#include "cHelicoptero.h"


cCentroDeSalud::cCentroDeSalud(string nombre, string direccion, string partido, string telefono, provincia provincia, cListaVehiculo* vehiculos, cListaPacientes* pacientes)
{
	this->Nombre = nombre;
	this->Direccion = direccion;
	this->Partido = partido;
	this->Telefono = telefono;
	this->Provincia = provincia;
	this->Lista_pacientes = new cListaPacientes(MAXPACIENTES);
	this->Lista_vehiculos = new cListaVehiculo(MAXVEHICULOS);


}

cCentroDeSalud::~cCentroDeSalud()
{
	delete this->Lista_pacientes;
	delete this->Lista_vehiculos;
}

void cCentroDeSalud::AsignarVehiculo(cReceptor* receptor, cOrgano* organo, cDonante* donante)
{
	if (receptor->getCentro()->Provincia == this->Provincia) {
		if (receptor->getCentro()->Partido == this->Partido) {
			this->RealizarAblacion(donante, organo);
			for (int i = 0; i < this->Lista_vehiculos->getCant(); i++) {
				cAmbulancia* ambulancia = dynamic_cast<cAmbulancia*>((*(this->Lista_vehiculos))[i]); //si nohay ambulancias exc
				if (ambulancia != NULL) {
					ambulancia->RealizarTransporte(receptor, organo); //se encontro una ambulancia para hacer el traslado en el mismo partido
					break; //cierro el bucle porque ya tengo una ambulancia
				}
			}
		}else {
			this->RealizarAblacion(donante, organo);
			for (int i = 0; i < this->Lista_vehiculos->getCant(); i++) {
				cHelicoptero* helicoptero = dynamic_cast<cHelicoptero*>((*(this->Lista_vehiculos))[i]); //si nohay ambulancias exc
				if (helicoptero != NULL) {
					helicoptero->RealizarTransporte(receptor, organo); //se encontro una ambulancia para hacer el traslado en el mismo partido
					break; //cierro el bucle porque ya tengo una ambulancia
				}
			}
		}
	}
	else {
		this->RealizarAblacion(donante, organo);
		for (int i = 0; i < this->Lista_vehiculos->getCant(); i++) {
			cAvion* avion = dynamic_cast<cAvion*>((*(this->Lista_vehiculos))[i]); //si nohay ambulancias exc
			if (avion != NULL) {
				avion->RealizarTransporte(receptor, organo); //se encontro una ambulancia para hacer el traslado en el mismo partido
				break; //cierro el bucle porque ya tengo una ambulancia
			}
		}

	}
}

void cCentroDeSalud::RealizarAblacion(cDonante* donante, cOrgano* organo)
//setea la fecha y horario de ablación del órgano y se quita el órgano removido de la lista de órganos del paciente donante
{
	organo->setFechaAblacion();
	donante->lista_organos->Eliminar(organo);

}

void cCentroDeSalud::RealizarTransplante(cOrgano* organo) 
{
	cFecha* fecha_transplante = new cFecha();
	fecha_transplante = organo->getFechaAblacion();
	fecha_transplante->getFecha().tm_hour + rand() % (24) + 1; //sumamos un numero de horas entre 1 y 24 a la fecha de ablacion para definir la fecha de transplante
	int CantHoras= cFecha::HorasEntreFechas(organo->getFechaAblacion(), fecha_transplante);

	if (CantHoras < 20) {
		cout << "Se pudo realizar el transplante porque el organo llego a destino en menos de 20 hs" << endl;
		bool exito = rand() % (2); //da 0 o 1  
		if (exito)
			cout << "Transplante EXITOSOOOOOO wena capo, disfruta tu " << organo->getNombreOrgano() << endl;
		else
			cout << "El transplante no fue exitoso :( se murio tu amigo " << endl;
	}
	else
		throw new exception("PASARON_MAS_DE_20_HORAS"); //catch cada vez que lo llamamos
}
