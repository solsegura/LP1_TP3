#pragma once
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class cFecha
{

	tm fecha;

public:
	//Constructor por default, inicia en la fecha de hoy
	cFecha(bool next_mes = false);

	//Constructor inicia en dia, mes, año
	cFecha(int d, int m, int a);

	cFecha(int dia, int mes, int anio, int hora, int minutos);

	~cFecha();


	//Calcula el numero de horas entre dos fechas
	static int HorasEntreFechas(cFecha* inicio, cFecha* fin);


	//Cambia la fecha a la fecha actual
	void SetHoy();
	void setMesRand();
	//Verifica que la fecha esté completa
	bool FechaCompleta();

	//Devuelve la fecha actual en forma de string
	string To_string();

	// Imprime fecha
	void ImprimirFecha();


	bool operator<(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this < aux_otra;
	}

	bool operator>(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this > aux_otra;
	}

	bool operator==(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this == aux_otra;
	}

	bool operator!=(cFecha& otra) {
		return !(*this == otra);
	}

	tm getFecha();

};

