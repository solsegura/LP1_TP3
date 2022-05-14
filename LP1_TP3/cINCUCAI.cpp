#include "cINCUCAI.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cCentroDeSalud.h"
#define MAXDONANTES 40
#define MAXRECEPTORES 40

/* -------------EXPLICACION DE LO QUE HICE---------------
Sory, me re cebe con estas funciones porque entre a googlear y no queria olvidarme de las cosas que vi

Basicamente, fui siguiendo lo que pedia la consigna (ignorando los errores que saltan que no se resolver). 
	1: entra el paciente y es donante, facilongui: lo metemos a la lista de donantes y llamamos a Buscar receptores 
	que va a ver que personas necesitan los organos de este donante. ahi con el for vamos viendo los MATCH que se hace 
	entre los receptores y cada organo del donante y lo guardamos en aux_receptor.

	2: si es receptor nos queremos pegar un tiro porque hay que buscarle posibles donantes y para cada donante ver si 
	le dan o no el organo haciendo lo mismo que en 1.


*/
using namespace std;


cINCUCAI::cINCUCAI(string nombre)
{
	this->Nombre = nombre;
	this->Lista_donantes = new cListaDonantes(MAXDONANTES);
	this->Lista_receptores = new cListaReceptores(MAXRECEPTORES);

}

cINCUCAI::~cINCUCAI()
{
	delete this->Lista_donantes;
	delete this->Lista_receptores;
}

void cINCUCAI::RecibirPaciente(cPaciente* paciente_nuevo)
{
	cout << "Bienvenido a INCUCAI. En un instante lo ingresaremos al sistema." << endl;
	this->IngresarPaciente(paciente_nuevo);
}

void cINCUCAI::IngresarPaciente(cPaciente* paciente_nuevo)
{
	cReceptor* receptor_aux = dynamic_cast<cReceptor*>(paciente_nuevo);
	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente_nuevo);
	if (donante_aux != NULL) {
		//es donante
		this->Lista_donantes->Agregar(donante_aux);
		//Luego busca los posibles receptores y devuelve una lista de posibles receptores segun los organos del donante
		cListaReceptores* sublista = this->BuscarReceptores(donante_aux->lista_organos);  //devielve ista de los que necesitan el organo
		for (int i = 0; i < donante_aux->lista_organos->getCant(); i++) {
			cReceptor* aux_Receptor = this->ElegirReceptor(sublista, (*(donante_aux->lista_organos))[i]);  //para cada organo que puede donar, busca un receptor
			if (aux_Receptor != NULL) {
				//hubo un match
				cout << "el receptor (aux receptor) va a recibir el organo (paciente_nuevo->listaorganos[i]" << endl; //dejo esto aca para que se lea mas claro la onda del match
				this->IniciarProtocolo(aux_Receptor, donante_aux, (*(donante_aux->lista_organos))[i]); //inicio el protocolo para transportar cada organo del donante con su match
			}

			//recordar sacar al receptor este de la lista de receptores una vez que se haga el transplante  
			//si no es NULL iniciar el protocolo de no se que concha
		}
	}
	else if (receptor_aux != NULL) {
		this->Lista_receptores->Agregar(receptor_aux);  //es un receptor, lo agrego a la lista de receptores
		cListaDonantes* aux_donantes = this->BuscarDonantes(receptor_aux->Organo_que_necesita); //devuelve una lista con los donantes que pueden donar el organo que necesita este receptor

		for (int i = 0; i < aux_donantes->getCant(); i++) {
			cListaReceptores* sublista = this->BuscarReceptores((*aux_donantes)[i]->lista_organos);  // por cada donante veo si hay match
			cReceptor* aux = this->ElegirReceptor(sublista, receptor_aux->Organo_que_necesita);  //si para el organo que necesita, hay match, aux va a ser el receptor que ingreso
			if (aux == receptor_aux) {
				//el receptor encontro donante :)
				cDonante* Match_donante = (*aux_donantes)[i]; //me guardo al match  (match_donante le va a dar a paciente nuevo el organo que necesita
				this->IniciarProtocolo(receptor_aux, Match_donante, receptor_aux->Organo_que_necesita); //iniciar el protocolo ese 

				break;
			}
		}

	}
	else
		//throw
		;
}

cListaReceptores* cINCUCAI::BuscarReceptores(cListaOrganos* organos) //recibe lista de organos del donante y devuelve los que nec esos organos
{
	cListaReceptores* sublista = new cListaReceptores(MAXRECEPTORES);
	for (int j = 0; j < organos->getCant(); j++) {
		for (int i = 0; i < this->Lista_receptores->getCant(); i++) {
			if ((*(this->Lista_receptores))[i]->Organo_que_necesita == (*organos)[j]) //si es el mismo organo lo agrego a la lista
				sublista->Agregar((*(this->Lista_receptores))[i]);
		}
	}
	return sublista;
}

cReceptor* cINCUCAI::ElegirReceptor(cListaReceptores* sublista, cOrgano* organo_a_donar) //veo el orden de prioridad y elijo al receptor
{
	//deberia recorrer los receptores y de los que tengan el mismo organo fijarme cual es el que tiene mayor prioridad
	for (int i = 0; i < sublista->getCant(); i++)
	{
		if ((*sublista)[i]->Organo_que_necesita == organo_a_donar) //ver cual es el que tiene mas priodridad 
		{
			if ((*sublista)[i]->Prioridad == 3) //como la lista esta ordenada va a ser por oden de llegada y siempre va a agarrar al primero
			{
				return (*sublista)[i];
				break;
			}
			if ((*sublista)[i]->Prioridad == 2)
			{
				return (*sublista)[i];
				break;
			}
			if ((*sublista)[i]->Prioridad == 1)
			{
				return (*sublista)[i];
				break;
			}
			if ((*sublista)[i]->Prioridad == 0)
			{
				return (*sublista)[i];
				break;
			}
		}
	}
}

void cINCUCAI::IniciarProtocolo(cReceptor* receptor, cDonante* donante, cOrgano* organo)
{
	cCentroDeSalud* aux_centro = donante->getCentro();
	aux_centro->AsignarVehiculo(receptor, organo, donante);
}
