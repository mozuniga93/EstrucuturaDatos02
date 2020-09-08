#include "Cola.h"
#include "stddef.h"
#include <string>
using namespace std;

Cola::Cola(void) {
	//Constructora por defecto
	frente = NULL;
	final = NULL;
	longitud = 0;
}

int Cola::getLongitud(void) const { //Analizadora
	return longitud;
}
Nodo* Cola::getFrente(void) const { //Analizadora
	return frente;
}
Nodo* Cola::getFinal(void) const { //Analizadora
	return final;
}
void Cola::setLongitud(int l) { //Modificadora
	longitud = l;
}

void Cola::setFrente(Nodo* f) { //Modificadora
	frente = f;
}
void Cola::setFinal(Nodo* fi) { //Modificadora
	final = fi;
}

//En ColaEnt.cpp:
void Cola::insertarElem(int pElem) {
	Nodo* nuevo = new Nodo(pElem);
	if (this->esVacia()) {
		frente = nuevo;
		final = nuevo;
	}
	else {
		final->setSig(nuevo);
		final = nuevo;
	}
	longitud++;
}

//En ColaEnt.cpp:
bool Cola::esVacia() {
	bool colaVacia = false;
	if (getFrente() == NULL) {
		colaVacia = true;
	}
	return colaVacia;
}

//En ColaEnt.cpp:
bool Cola::eliminarElem() {
	Nodo* aux;
	if (!(this->esVacia())) {
		aux = frente;
		frente = frente->getSig();
		longitud--;
		delete aux;
		return true;
	}
	else {
		return false;
	}
}

//En Cola.cpp:
int Cola::pasarColaAPila() {
	Nodo* aux;
	int valor = -1;
	if (!(this->esVacia())) {
		aux = frente;
		valor = frente->getInfo();
		frente = frente->getSig();
		longitud--;
		delete aux;
	}
	return valor;
}

string Cola::recorrerCola() {
	string rslt = "";
	if (this->esVacia()) {
		rslt = "Cola vacia";
	}
	else {
		Nodo* aux = getFrente();
		int contador = 1;
		do {
			rslt += "Dato(" + to_string(contador) + ")=" + to_string(aux->getInfo()) + "\n";
			aux = aux->getSig();
			contador++;
		} while (aux != NULL);
	}
	return rslt;
}
