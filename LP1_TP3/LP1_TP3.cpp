#include"Template.h"
#include"cPaciente.h"
#include "cINCUCAI.h"
#include "cOrgano.h"
#include <iostream>

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
