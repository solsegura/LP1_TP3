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



	 ----------------HOLA FIO----------------------------
	 Resolvi casi todos los problemas para que el codigo pueda correr, me parece que el unico que queda es un problema con la 
	 sobrecarga del ==, chequeate eso (sino no se que es).

	 Para el main, crear objetos de todos los tipos. una vez que hiciste a los donantes y receptores, cada uno tiene que agregar los 
	 organos con su metodo agregar organo. una vez que esta eso, ingresan al incucai y ahi se hace todo automaticamente. despues imprimir incucai y listo creo.

	 Algo que se puede cambiar si tenemos la voluntad es que la fecha del donante en vez de ser de tipo tm sea cFecha, estaria buenisimo pero hay 
	 que cambiarlo tambien en el constructor y eso.

	 Si piensan algo de ContarDonaciones mandenle, EXITOOOSS. A mi lo que se me ocurre es hacerla en cCentroDeSalud que tiene toda la info pero bueno... de ahi a hacerla.






*/


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
   printf("                                \n");
    
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
