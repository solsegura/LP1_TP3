#include "cINCUCAI.h"
#include "cDonante.h"
#define MAXDONANTES 40
#define MAXRECEPTORES 40

/* -------------EXPLICACION DE LO QUE HICE---------------
Sory, me re cebe con estas funciones porque entre a googlear y no queria olvidarme de las cosas que vi
Basicamente, fui siguiendo lo que pedia la consigna (ignorando los errores que saltan que no se resolver). 
1: entra el paciente y es donante, facilongui: lo metemos a la lista de donantes y llamamos a Buscar receptores 
que va a ver que personas necesitan los organos de este donante. ahi con el for vamos viendo los MATCH que se hace 
entre los receptores y cada organo del donante y lo guardamos en aux_receptor.

*/
using namespace std;


cINCUCAI::cINCUCAI(string nombre)
{
	this->Nombre = nombre;
	this->Lista_donantes = new cListaDonantes(MAXDONANTES);
	this->Lista_receptores = new cListaReceptores(MAXRECEPTORES);

}

void cINCUCAI::IngresarPaciente(cPaciente* paciente_nuevo)
{
	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente_nuevo);
	if (donante_aux != NULL) {
		//es donante
		this->Lista_donantes->Agregar(paciente_nuevo); //como hago?

		//Luego busca los posibles receptores y devuelve una lista de posibles receptores segun los organos del donante
		cListaReceptores* sublista = this->BuscarReceptores(paciente_nuevo->lista_organos);  //mismo problema de como aclararle que es donante
		for (int i = 0; i < paciente_nuevo->lista_organos->getCant(); i++) {
			cPaciente* aux_Receptor = this->ElegirReceptor(sublista, (*(paciente_nuevo->lista_organos))[i]);  //para cada organo que puede donar, busca un receptor
			cout << "el receptor (aux receptor) va a recibir el organo (paciente_nuevo->listaorganos[i]" << endl; //dejo esto aca para que se lea mas claro la onda del match
			//recordar sacar al receptor este de la lista de receptores una vez que se haga el transplante  
			//si no es NULL iniciar el protocolo de no se que concha
		}
	}

	else {
		this->Lista_receptores->Agregar(paciente_nuevo);  //es un receptor, lo agrego a la lista de receptores
		cListaDonantes* aux_donantes = this->BuscarDonantes(paciente_nuevo->Organo_que_necesita); //devuelve una lista con los donantes que pueden donar el organo que necesita este receptor

		for (int i = 0; i < aux_donantes->getCant(); i++) {
			cListaReceptores* sublista = this->BuscarReceptores((*aux_donantes)[i]->lista_organos);  // por cada donante veo si hay match
			cPaciente* aux = this->ElegirReceptor(sublista, paciente_nuevo->Organo_que_necesita);  //si para el organo que necesita, hay match, aux va a ser el receptor que ingreso
			if (aux == paciente_nuevo) {
				//el receptor encontro donante :)
				cPaciente* Match_donante = (*aux_donantes)[i]; //me guardo al match  (match_donante le va a dar a paciente nuevo el organo que necesita
				break;
			}
		}
	
	}
}
