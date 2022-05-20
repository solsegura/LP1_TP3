#pragma once
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class cFecha
{
	tm fecha;

public:
	
	cFecha(bool next_mes = false);//Constructor por default, inicia en la fecha de hoy
	cFecha(int d, int m, int a);//Constructor inicia en dia, mes, año
	cFecha(int dia, int mes, int anio, int hora, int minutos);
	~cFecha();
	static int HorasEntreFechas(cFecha* inicio,time_t aux_fin);//Calcula el numero de horas entre dos fechas
	void SetHoy();//Cambia la fecha a la fecha actual
	void setMesRand();
	bool FechaCompleta();//Verifica que la fecha esté completa
	string To_string();//Devuelve la fecha actual en forma de string
	void ImprimirFecha();// Imprime fecha


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

