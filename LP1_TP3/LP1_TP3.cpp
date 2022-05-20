#include"Template.h"
#include"cPaciente.h"
#include "cINCUCAI.h"
#include "cOrgano.h"
#include "cVehiculo.h"
#include "cFecha.h"
#include "cReceptor.h"
#include "cDonante.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cHelicoptero.h"
#include "cCentroDeSalud.h"

using namespace std;

typedef cLista<cVehiculo> cListaVehiculo;
typedef cLista<cPaciente> cListaPacientes;

string lista_organos[9] = {"Corazon", "Higado", "Pancreas", "Huesos", "Rinion", "Pulmones", "Intestino", "Piel", "Corneas"};
int main()
{
	srand(time(NULL));

	cout << "          --------------BIENVENIDO---------------" << endl<<endl<<endl;
	printf("                     |  \\ \\ | |/ /\n");
	printf("                     |  |\\ `' ' /             \n");
	printf("                     |  ;'      \\     / ,    \n");
	printf("                     | ;    _,   |    / / ,   \n");
	printf("                     | |   (  `-.;_,-' '-' ,  \n");
	printf("                     | `,   `-._       _,-'_  \n");
	printf("                     |,-`.    `.)    ,<_,-'_, \n");
	printf("                    ,'    `.   /   ,'  `;-' _,\n");
	printf("                   ;        `./   /`,    \\-'  \n");
	printf("                   |         /   |  ;\\   |\\   \n");
	printf("                   |        ;_,._|_,  `, ' \\  \n");
	printf("                   |        \\    \\ `       `, \n");
	printf("                   `      __ `    \\         ;,\n");
	printf("                    \\   ,'  `      \\,        ;\n");
	printf("                     \\_(            ;,      ;;\n");
	printf("                     |  \\           `;,     ;;\n");
	printf("                     |  |`.          `;;,   ;'\n");
	printf("                     |  |  `-.        ;;;;,;' \n");
	printf("                     |  |    |`-.._  ,;;;;;'  \n");
	printf("                     |  |    |   | ``';;;'    \n");
	printf("                                              \n");
	system("pause");
	system("cls");
	//fechas
	cFecha* Nacimiento1 = new cFecha(1, 5, 1971);
	cFecha* Nacimiento2 = new cFecha(12, 3, 1998);
	cFecha* Nacimiento3 = new cFecha(9, 4, 1960);
	cFecha* Nacimiento4 = new cFecha(3, 4, 2001);
	cFecha* Nacimiento5 = new cFecha(12, 11, 2002);
	cFecha* Nacimiento6 = new cFecha(2, 12, 2004);
	cFecha* Nacimiento7 = new cFecha(24, 1, 2001);

	cFecha* Fallecimiento1 = new cFecha(1, 5, 2022);
	cFecha* Fallecimiento2 = new cFecha(12, 3, 2022);
	cFecha* Fallecimiento3 = new cFecha(9, 4, 2022);
	cFecha* Fallecimiento4 = new cFecha(3, 4, 2022);
	cFecha* Fallecimiento5 = new cFecha(12, 1, 2022);
	cFecha* Fallecimiento6 = new cFecha(2, 1, 2022);
	cFecha* Fallecimiento7 = new cFecha(24, 1, 2022);


	cOrgano* corazao1 = new cOrgano(lista_organos[0]);
	cOrgano* higaduli1 = new cOrgano(lista_organos[1]);
	cOrgano* PANcreas1 = new cOrgano(lista_organos[2]);
	cOrgano* Huesos1 = new cOrgano(lista_organos[3]);
	cOrgano* rinionn1 = new cOrgano(lista_organos[4]);
	cOrgano* pulmonn1 = new cOrgano(lista_organos[5]);
	cOrgano* Intestino1 = new cOrgano(lista_organos[6]);
	cOrgano* Piel1 = new cOrgano(lista_organos[7]);
	cOrgano* Corneas1 = new cOrgano(lista_organos[8]);

	cOrgano* corazao2 = new cOrgano(lista_organos[0]);  //estos usemos para los receptores
	cOrgano* higaduli2 = new cOrgano(lista_organos[1]);
	cOrgano* PANcreas2 = new cOrgano(lista_organos[2]);
	cOrgano* Huesos2 = new cOrgano(lista_organos[3]);
	cOrgano* rinionn2 = new cOrgano(lista_organos[4]);
	cOrgano* pulmonn2 = new cOrgano(lista_organos[5]);
	cOrgano* Intestino2 = new cOrgano(lista_organos[6]);
	cOrgano* Piel2 = new cOrgano(lista_organos[7]);
	cOrgano* Corneas2 = new cOrgano(lista_organos[8]);

	cOrgano* corazao3 = new cOrgano(lista_organos[0]);  //estos usemos para los receptores
	cOrgano* higaduli3 = new cOrgano(lista_organos[1]);
	cOrgano* PANcreas3 = new cOrgano(lista_organos[2]);
	cOrgano* Huesos3 = new cOrgano(lista_organos[3]);
	cOrgano* rinionn3 = new cOrgano(lista_organos[4]);
	cOrgano* pulmonn3 = new cOrgano(lista_organos[5]);
	cOrgano* Intestino3 = new cOrgano(lista_organos[6]);
	cOrgano* Piel3 = new cOrgano(lista_organos[7]);
	cOrgano* Corneas3 = new cOrgano(lista_organos[8]);


	//vehiculos
	cVehiculo* avion1 = new cAvion("avion3", "pepe");
	cVehiculo* avion2 = new cAvion("avion3", "pepe");
	cVehiculo* avion3 = new cAvion("avion3", "pepe");
	cVehiculo* avion4 = new cAvion("avion4", "pepe");


	cVehiculo* helicoptero1 = new cHelicoptero("heli1", "pepe");
	cVehiculo* helicoptero2 = new cHelicoptero("heli2", "pepe");
	cVehiculo* helicoptero3 = new cHelicoptero("heli3", "pepe");
	cVehiculo* helicoptero4 = new cHelicoptero("heli4", "pepe");


	cVehiculo* ambulancia1 = new cAmbulancia("ambu1", "pepe");
	cVehiculo* ambulancia2 = new cAmbulancia("ambu2", "pepe");
	cVehiculo* ambulancia3 = new cAmbulancia("ambu3", "pepe");
	cVehiculo* ambulancia4 = new cAmbulancia("ambu4", "pepe");



	cListaVehiculo* listaVehiculos1 = new cListaVehiculo(MAXVEHICULOS);
	cListaVehiculo* listaVehiculos2 = new cListaVehiculo(MAXVEHICULOS);
	cListaVehiculo* listaVehiculos3 = new cListaVehiculo(MAXVEHICULOS);
	cListaVehiculo* listaVehiculos4 = new cListaVehiculo(MAXVEHICULOS);


	listaVehiculos1->Agregar(ambulancia1);
	listaVehiculos1->Agregar(avion1);
	listaVehiculos1->Agregar(helicoptero1);
	listaVehiculos2->Agregar(ambulancia2);
	listaVehiculos2->Agregar(avion2);
	listaVehiculos2->Agregar(helicoptero2);
	listaVehiculos3->Agregar(ambulancia3);
	listaVehiculos3->Agregar(avion3);
	listaVehiculos3->Agregar(helicoptero3);
	listaVehiculos4->Agregar(ambulancia4);
	listaVehiculos4->Agregar(avion4);
	listaVehiculos4->Agregar(helicoptero4);

	//centros 
	cCentroDeSalud* centro1 = new cCentroDeSalud("Centro 1", "Sarmiento 1800", "Monserrat", "4469883652", Buenos_Aires,listaVehiculos1 );
	cCentroDeSalud* centro2 = new cCentroDeSalud("Centro 2", "Callao 500", "Barracas", "446989652", Catamarca,listaVehiculos2);
	cCentroDeSalud* centro3 = new cCentroDeSalud("Centro 3", "Rivadavia 900", "Caballito", "445395254", San_Juan,listaVehiculos3);
	cCentroDeSalud* centro4 = new cCentroDeSalud("Centro 4", "Olavarria 300", "Barracas", "4449852367", Buenos_Aires,listaVehiculos4 );

	//donantes 
	cDonante* donante1 = new cDonante(Fallecimiento1, "22458933", "Fiorella", true, "1125253636", OP, centro1, Nacimiento1);
	cDonante* donante2 = new cDonante(Fallecimiento2, "33168025", "Sol", true, "1145874536", ON, centro2, Nacimiento2);
	cDonante* donante3 = new cDonante(Fallecimiento3, "12459863", "Valentina", true, "1112345678", ABN, centro3, Nacimiento3);
	cDonante* donante4 = new cDonante(Fallecimiento4, "13650428", "Bruno", false, "1198745632", AP, centro4, Nacimiento4);
	cDonante* donante5 = new cDonante(Fallecimiento5, "21014258", "Juan", false, "1125896314", BP, centro1, Nacimiento5);
	cDonante* donante6 = new cDonante(Fallecimiento6, "12543698", "Pepe", false, "1174125896", BN, centro3, Nacimiento6);
	cDonante* donante7 = new cDonante(Fallecimiento7, "23452032", "Lorena", true, "1196301205", OP, centro2, Nacimiento7);

	//Receptores
	cReceptor* receptor1 = new cReceptor(muy_grave, "Cancer de corazon", estable, "25123456", "Julieta", true, "1112347854", OP, centro1, Nacimiento1);
	cReceptor* receptor2 = new cReceptor(grave, "Cancer de higado", estable, "12456123", "Rosario", true, "1112345678", ON, centro2, Nacimiento2);
	cReceptor* receptor3 = new cReceptor(leve, "Cancer de corneas", estable, "22123456", "Juan", false, "1178945600", ABN, centro3, Nacimiento3);
	cReceptor* receptor4 = new cReceptor(muy_leve, "Cancer de piel", inestable, "50123456", "Julio", false, "1132165488", AN, centro4, Nacimiento4);
	cReceptor* receptor5 = new cReceptor(leve, "Cancer de huesos", inestable, "33789456", "Belen", true, "1185296345", AP, centro3, Nacimiento5);
	cReceptor* receptor6 = new cReceptor(grave, "Cancer de intestino", inestable, "20789456", "Ezequiel", false, "1196325803", BN, centro1, Nacimiento6);
	cReceptor* receptor7 = new cReceptor(muy_grave, "Cancer de pancreas", inestable, "20123456", "Florencia", true, "1185274155", ABN, centro2, Nacimiento7);
	

	receptor1->AgregarOrgano(corazao2);
	receptor2->AgregarOrgano(higaduli2);
	receptor3->AgregarOrgano(Corneas2);
	receptor4->AgregarOrgano(Piel2);
	receptor5->AgregarOrgano(Huesos2);
	receptor6->AgregarOrgano(Intestino2);
	receptor7->AgregarOrgano(PANcreas2);

	donante1->AgregarOrgano(corazao1);
	donante1->AgregarOrgano(PANcreas1);
	donante2->AgregarOrgano(Piel1);
	donante2->AgregarOrgano(higaduli1);
	donante3->AgregarOrgano(Corneas1);
	donante4->AgregarOrgano(Huesos1);
	donante4->AgregarOrgano(rinionn1);
	donante4->AgregarOrgano(pulmonn1);
	donante5->AgregarOrgano(corazao3);
	donante6->AgregarOrgano(pulmonn3);
	donante6->AgregarOrgano(Corneas3);
	donante7->AgregarOrgano(Piel3);
	donante7->AgregarOrgano(higaduli3);
	donante7->AgregarOrgano(PANcreas3);

	cListaReceptores* TodosLosReceptores = new cListaReceptores(MAXPACIENTES);
	TodosLosReceptores->Agregar(receptor1);
	TodosLosReceptores->Agregar(receptor2);
	TodosLosReceptores->Agregar(receptor3);
	TodosLosReceptores->Agregar(receptor4);
	TodosLosReceptores->Agregar(receptor5);
	TodosLosReceptores->Agregar(receptor6);
	TodosLosReceptores->Agregar(receptor7);

	cListaDonantes* TodosLosDonantes = new cListaDonantes(MAXPACIENTES);
	TodosLosDonantes->Agregar(donante1);
	TodosLosDonantes->Agregar(donante2);
	TodosLosDonantes->Agregar(donante3);
	TodosLosDonantes->Agregar(donante4);
	TodosLosDonantes->Agregar(donante5);
	TodosLosDonantes->Agregar(donante6);
	TodosLosDonantes->Agregar(donante7);

	cINCUCAI* incucai = new cINCUCAI("incucai");
	
	cListaPacientes* listapacientes1 = new cListaPacientes(MAXPACIENTES); //listas de pacientes correspondientes a cada centro de salud
	cListaPacientes* listapacientes2 = new cListaPacientes(MAXPACIENTES);
	cListaPacientes* listapacientes3 = new cListaPacientes(MAXPACIENTES);
	cListaPacientes* listapacientes4 = new cListaPacientes(MAXPACIENTES);

	for (int i = 0; i < incucai->getCantReceptores(); i++) {
		if ((*(TodosLosReceptores))[i]->getCentro() == centro1) {
			centro1->AgregarPaciente((*(TodosLosReceptores))[i]);
		}
		else if ((*(TodosLosReceptores))[i]->getCentro() == centro2) {
			centro2->AgregarPaciente((*(TodosLosReceptores))[i]);
		}
		else if ((*(TodosLosReceptores))[i]->getCentro() == centro3) {
			centro3->AgregarPaciente((*(TodosLosReceptores))[i]);
		}
		else if ((*(TodosLosReceptores))[i]->getCentro() == centro4) {
			centro4->AgregarPaciente((*(TodosLosReceptores))[i]);
		}
	}

   
   
   for (int i = 0; i < TodosLosDonantes->getCant(); i++) {
	   incucai->IngresarPaciente((*(TodosLosDonantes))[i]);
   }
   for (int i = 0; i < TodosLosReceptores->getCant(); i++) {
	   incucai->IngresarPaciente((*(TodosLosReceptores))[i]);
   }


	try {
		incucai->FiltroReceptoresPorOrgano(corazao1); 
	}
	catch (exception e) {
		cout << string(e.what()) << endl;
		}

	cout << *incucai;
	system("pause");
	system("cls");


}
