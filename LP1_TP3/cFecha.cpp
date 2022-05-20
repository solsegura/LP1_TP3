#include "cFecha.h"

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


cFecha::cFecha(bool next_mes) {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	if (next_mes) {

	}
		//setr rand
	SetHoy();

	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m ;
	fecha.tm_year = a -1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a, int hs, int min) {

	fecha.tm_hour = hs;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m;
	fecha.tm_year = a-1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {
}

int cFecha::HorasEntreFechas(cFecha* inicio, cFecha* fin)
{
	int dif = 0;
	time_t aux_inicio = mktime(&(inicio->fecha)); //paso las fechas a segundos
	time_t aux_fin = mktime(&(fin->fecha));
	//if -1 falla la conversion
	//verifico que las fechas que recibo no sean null ni est�n incompletas
	if ((inicio != NULL && fin != NULL) && inicio->FechaCompleta() && fin->FechaCompleta())
	{
		//verifico que fecha fin > fecha inicio con operador sobrecargado
		if (*inicio > *fin)
			throw exception("Las fechas no son v�lidas");
		else
		{
			dif = difftime(aux_fin, aux_inicio) / (3600); //calculo la diferencia de tiempo en segundos, transforma a horas, y la devuelvo
			return dif;
		}
	}
	else throw exception("Fechas incompletas");
}

void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha y hora actual
	fecha.tm_sec = aux->tm_sec;
	fecha.tm_min = aux->tm_min;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
}

void cFecha::setMesRand()
{

	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha y hora actual
	fecha.tm_sec = aux->tm_sec;
	fecha.tm_min = aux->tm_min;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;

	fecha.tm_mon++; //sumamos uno al mes para la consign QUE AL FINAL ERA OPCIONAL
}

bool cFecha::FechaCompleta()
{
	if (fecha.tm_year != 0 && fecha.tm_mon != 0 && fecha.tm_mday != 0 && fecha.tm_hour>=0 && fecha.tm_min>=0 && fecha.tm_sec>=0) //verifico que los par�metros de d�a no est�n en sus valores nulos
		return true;
	return false;
}

string cFecha::To_string()
{
	return to_string(fecha.tm_year + 1900) +
		"/" + to_string(fecha.tm_mon + 1) +
		"/" + to_string(fecha.tm_mday);
}

void cFecha::ImprimirFecha() {
	cout << To_string() << endl;;
}

tm cFecha::getFecha()
{
	return this->fecha;
}

