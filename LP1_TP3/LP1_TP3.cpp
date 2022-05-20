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
string lista_organos[9] = {"Corazon", "Higado", "Pancreas", "Huesos", "Rinion", "Pulmones", "Intestino", "Piel", "Corneas"};
int main()
{
	/* ----------EXPLICACION DE ESTO--------
	 primero usamos typedef para decirle al visual "las listas que guarden cPaciente se van a ser cListaPacientes"
	 seria como darle un nombre especifico a un tipo de lista template (basandonos en el tipo de dato que guarda)
	
	Habiendo ya aclarado que esas listas van a ser de pacientes, ahi hago como siempre el new como si fuera una 
	listra de pacientes normal, no template (igual que en el TP2)

		    _   _
		   (.)_(.)
		_ (   _   ) _
	   / \/`-----'\/ \
	 __\ ( (     ) ) /__
	 )   /\ \._./ /\   (
      )_/ /|\   /|\ \_(
	 
	 Te dejo un sapo de regalo, lav u

	 */
/*
	 ----------------HOLA FIO----------------------------
	 Resolvi casi todos los problemas para que el codigo pueda correr, me parece que el unico que queda es un problema con la 
	 sobrecarga del ==, chequeate eso (sino no se que es).

	 Para el main, crear objetos de todos los tipos. una vez que hiciste a los donantes y receptores, cada uno tiene que agregar los 
	 organos con su metodo agregar organo. una vez que esta eso, ingresan al incucai y ahi se hace todo automaticamente. despues imprimir incucai y listo creo.

	 Algo que se puede cambiar si tenemos la voluntad es que la fecha del donante en vez de ser de tipo tm sea cFecha, estaria buenisimo pero hay 
	 que cambiarlo tambien en el constructor y eso.

	 Si piensan algo de ContarDonaciones mandenle, EXITOOOSS. A mi lo que se me ocurre es hacerla en 
	 cCentroDeSalud que tiene toda la info pero bueno... de ahi a hacerla.
*/


	/*
   printf("       |  \\ \\ | |/ /\n");
   printf("       |  |\\ `' ' /             \n");
   printf("       |  ;'      \\     / ,    \n");
   printf("       | ;    _,   |    / / ,   \n");
   printf("       | |   (  `-.;_,-' '-' ,  \n");
   printf("       | `,   `-._       _,-'_  \n");
   printf("       |,-`.    `.)    ,<_,-'_, \n");
   printf("      ,'    `.   /   ,'  `;-' _,\n");
   printf("     ;        `./   /`,    \\-'  \n");
   printf("     |         /   |  ;\\   |\\   \n");
   printf("     |        ;_,._|_,  `, ' \\  \n");
   printf("     |        \\    \\ `       `, \n");
   printf("     `      __ `    \\         ;,\n");
   printf("      \\   ,'  `      \\,        ;\n");
   printf("       \\_(            ;,      ;;\n");
   printf("       |  \\           `;,     ;;\n");
   printf("       |  |`.          `;;,   ;'\n");
   printf("       |  |  `-.        ;;;;,;' \n");
   printf("       |  |    |`-.._  ,;;;;;'  \n");
   printf("       |  |    |   | ``';;;'    \n");
   printf("                                \n");*/
	//fechas
	cFecha* Nacimiento1 = new cFecha(1, 5, 1971);
	cFecha* Nacimiento2 = new cFecha(12, 3, 1998);
	cFecha* Nacimiento3 = new cFecha(9, 4, 1960);
	cFecha* Nacimiento4 = new cFecha(3, 4, 2001);
	cFecha* Nacimiento5 = new cFecha(12, 11, 2002);
	cFecha* Nacimiento6 = new cFecha(2, 12, 2004);
	cFecha* Nacimiento7 = new cFecha(24, 1, 2001);

	//vehiculos
	cVehiculo* avion1 = new cAvion("");
	cVehiculo* avion2 = new cAvion();
	cVehiculo* helicoptero1 = new cHelicoptero();
	cVehiculo* helicoptero2 = new cHelicoptero();
	cVehiculo* ambulancia1 = new cAmbulancia();
	cVehiculo* ambulancia2 = new cAmbulancia();

	//centros 
	cCentroDeSalud* centro1 = new cCentroDeSalud("Centro 1", "Sarmiento 1800", "Monserrat", "4469883652", "Buenos Aires", );
	cCentroDeSalud* centro2 = new cCentroDeSalud("Centro 2","Callao 500", "Barracas", "446989652", "Cordoba");
	cCentroDeSalud* centro3 = new cCentroDeSalud("Centro 3","Rivadavia 900", "Caballito", "445395254", "San Juan");
	cCentroDeSalud* centro4 = new cCentroDeSalud("Centro 4","Olavarria 300", "Barracas", "4449852367", "Buenos Aires",);

	//donantes
	cPaciente* donante1 = new cDonante("", "", "22458933", "Fiorella", Nacimiento1,true, "1125253636", OP, centro1,    );
	cPaciente* donante2 = new cDonante("", "", "33168025", "Sol", Nacimiento2, true, "1145874536", ON, centro2, );
	cPaciente* donante3 = new cDonante("", "", "12459863", "Valentina", Nacimiento3, true, "1112345678", ABN, centro3, );
	cPaciente* donante4 = new cDonante("", "", "13650428", "Bruno", Nacimiento4, false, "1198745632", AP, centro4, );
	cPaciente* donante5 = new cDonante("", "", "21014258", "Juan", Nacimiento5, false, "1125896314", BP, centro1, );
	cPaciente* donante6 = new cDonante("", "", "12543698", "Pepe", Nacimiento6, false, "1174125896", BN, centro3, );
	cPaciente* donante7 = new cDonante("", "", "23452032", "Lorena", Nacimiento7, true, "1196301205", OP, centro2, );

	//paientes
	cPaciente* receptor1 = new cReceptor("", muy_grave, /*que poronga es patologia*/, estable, "25123456", "Julieta", Nacimiento1, true, "1112347854", OP, centro1, );
	cPaciente* receptor2 = new cReceptor("", grave, /*que poronga es patologia*/, estable, "12456123", "Rosario", Nacimiento2, true, "1112345678", ON, centro2, );
	cPaciente* receptor3 = new cReceptor("", leve, /*que poronga es patologia*/, estable, "22123456", "Juan", Nacimiento3, false, "1178945600", ABN, centro3, );
	cPaciente* receptor4 = new cReceptor("", muy_leve, /*que poronga es patologia*/, inestable, "50123456", "Julio", Nacimiento4, false, "1132165488", AN, centro4, );
	cPaciente* receptor5 = new cReceptor("", leve, /*que poronga es patologia*/, inestable, "33789456", "Belen", Nacimiento5, true, "1185296345", AP, centro3, );
	cPaciente* receptor6 = new cReceptor("", grave, /*que poronga es patologia*/, inestable, "20789456", "Ezequiel", Nacimiento6, false, "1196325803", BN, centro1, );
	cPaciente* receptor7 = new cReceptor("", muy_grave, /*que poronga es patologia*/, inestable, "20123456", "Florencia", Nacimiento7, true, "1185274155", ABN, centro2, );


    

	//receptores
   cINCUCAI* incucai = new cINCUCAI("incucai");
	typedef cLista<cPaciente> cListaPacientes;  //dejo esto aca para entender que onda los templates en el main
	cListaPacientes* Lista_Pacientes = new cListaPacientes(10);
	//Lista_Pacientes->Buscar();
	cOrgano* corazao = new cOrgano("corazon");

	try {
		incucai->FiltroReceptoresPorOrgano(corazao);
	}
	catch (exception e) {
		cout << string(e.what()) << endl;
		}
}
