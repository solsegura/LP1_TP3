#include "cCentroDeSalud.h"
#include"cOrgano.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cVehiculo.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cFecha.h"
#include "cHelicoptero.h"


cCentroDeSalud::cCentroDeSalud(string nombre, string direccion, string partido, string telefono, provincia provincia, cListaVehiculo* vehiculos)
{
	this->Nombre = nombre;
	this->Direccion = direccion;
	this->Partido = partido;
	this->Telefono = telefono;
	this->Provincia = provincia;
	this->Lista_pacientes = new cListaPacientes(MAXPACIENTES);
	this->Lista_vehiculos = vehiculos;


}

cCentroDeSalud::~cCentroDeSalud()
{
	delete this->Lista_pacientes;
	delete this->Lista_vehiculos;
}

void cCentroDeSalud::AgregarPaciente(cPaciente* paciente_nuevo)
{
	this->Lista_pacientes->Agregar(paciente_nuevo);
}

void cCentroDeSalud::AsignarVehiculo(cReceptor* receptor, cOrgano* organo, cDonante* donante)
{
	int i = 0;
	if (receptor->getCentro()->Provincia == this->Provincia) {
		if (receptor->getCentro()->Partido == this->Partido) {
			this->RealizarAblacion(donante, organo);
			for (i; i < this->Lista_vehiculos->getCant(); i++) {
				cAmbulancia* ambulancia = dynamic_cast<cAmbulancia*>((*(this->Lista_vehiculos))[i]); //si nohay ambulancias exc
				if (ambulancia != NULL) {
					ambulancia->RealizarTransporte(receptor, organo); //se encontro una ambulancia para hacer el traslado en el mismo partido
					break; //cierro el bucle porque ya tengo una ambulancia
				}
			}
			if(i==Lista_vehiculos->getCant())
				throw new exception("No hay ambulancias disponibles");
		}
		else
		{
			int k = 0;
			this->RealizarAblacion(donante, organo);
			for (k; k < this->Lista_vehiculos->getCant(); k++) {
				cHelicoptero* helicoptero = dynamic_cast<cHelicoptero*>((*(this->Lista_vehiculos))[k]); //si nohay ambulancias exc
				if (helicoptero != NULL) {
					helicoptero->RealizarTransporte(receptor, organo); //se encontro una ambulancia para hacer el traslado en el mismo partido
					break; //cierro el bucle porque ya tengo una ambulancia
				}
			}
			if(k==Lista_vehiculos->getCant())
				throw new exception("No hay helicopteros disponibles");

		}
	}
	else {
		int j = 0;
		this->RealizarAblacion(donante, organo);
		for (j; j < this->Lista_vehiculos->getCant(); j++) {
			cAvion* avion = dynamic_cast<cAvion*>((*(this->Lista_vehiculos))[j]); //si nohay ambulancias exc
			if (avion != NULL) {
				avion->RealizarTransporte(receptor, organo); //se encontro una ambulancia para hacer el traslado en el mismo partido
				break; //cierro el bucle porque ya tengo una ambulancia
			}
		}
		if(j==Lista_vehiculos->getCant())
			throw new exception("No hay aviones disponibles");

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
	tm aux = fecha_transplante->getFecha();
	aux.tm_hour = rand() % 23; //sumamos un numero de horas entre 1 y 24 a la fecha de ablacion para definir la fecha de transplante
	int CantHoras = cFecha::HorasEntreFechas(organo->getFechaAblacion(), fecha_transplante);

	if (CantHoras < 20) {
		cout << "Se pudo realizar el transplante porque el organo llego a destino en menos de 20 hs" << endl;
		bool exito = rand() % (2); //da 0 o 1  
		if (exito)
			cout << "Transplante EXITOSO! Disfruta tu " << organo->getNombreOrgano() << "." << endl<<endl;
		else
			throw new exception("Transplante no exitoso :(");
	}
	else
		throw new exception("PASARON_MAS_DE_20_HORAS");
}
