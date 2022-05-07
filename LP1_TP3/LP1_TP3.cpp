#include"Template.h"
#include"cPaciente.h"
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

	typedef cLista<cPaciente> cListaPacientes;  //dejo esto aca para entender que onda los templates en el main
	cListaPacientes* Lista_Pacientes = new cListaPacientes(10);
}
