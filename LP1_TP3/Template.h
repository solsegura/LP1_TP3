#pragma once

using namespace std;

template <class T>
class cLista {
	T* Vector;
	int Tamanio;
	int Cant_act;
public:
	cLista(int tam);
	~cLista();
	void Agregar(T* nuevo_item);  //tiene throw, recordar hacer catch
	void Eliminar(T* item);
	T* Quitar(T* item);
	int Buscar(T* item); //devuelve la posicion del item
};

template<class T>
inline cLista<T>::cLista(int tam)
{
	this->Tamanio = tam;
	this->Cant_act = 0;
	this->Vector = new T[this->Tamanio];
	for (int i = 0; i < this->Tamanio; i++)
		this->Vector[i] = NULL;
}

template<class T>
inline cLista<T>::~cLista()
{
	delete [] this->Vector;
}

template<class T>
inline void cLista<T>::Agregar(T* nuevo_item)
{
	if (this->Cant_act < this->Tamanio) {
		try {
			if (this->Buscar(nuevo_item) == -1)
				this->Vector[(this->Cant_act)++] = nuevo_item;  //guardo el nuevo item e incremento la cant actual con postincremento
		}
		catch (...) {}; //buscar lanza exception si no encuentra, pero no queremos imprimirla en este caso
		else
			throw new exception("Ya se encontraba en la lista");
	}
	else
		throw new exception("No hay mas lugar en la lista");
}

template<class T>
inline void cLista<T>::Eliminar(T* item)
{
	int idx = this->Buscar(item);
	this->Vector[idx] = this->Vector[--Cant_act];  //decremento uno a cant actual y muevo el ultimo elemento de la lista al lugar del que quiero borrar
	this->Vector[Cant_act] = NULL; //borro el ultimo elemento de la lista (ya lo puse en otra posicion)
}

template<class T>
inline T* cLista<T>::Quitar(T* item)
{
	int idx = this->Buscar(item);
	return this->Vector[idx];
}

template<class T>
inline int cLista<T>::Buscar(T* item)
{
	for (int i = 0; i < this->Cant_act; i++) {
		if (this->Vector[i] == item)
			return i;
	}
	throw new exception("NO_SE_ENCUENTRA_EN_LA_LISTA");   //lanzamos una excepcion si no encuentra
	return -1;  
}