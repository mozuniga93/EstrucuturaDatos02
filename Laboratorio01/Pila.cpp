#include "Pila.h"

Pila::Pila(void) { //Constructora
	longitud = 0;
	tope = NULL;
}
int Pila::getLongitud(void) const { //Analizadora
	return longitud;
}
Nodo* Pila::getTope(void) const { //Analizadora
	return tope;
}
void Pila::setLongitud(int l) { //Modificadora
	longitud = l;
}

void Pila::setTope(Nodo* t) { //Modificadora
	tope = t;
}

//En PilaEnt.cpp:
int Pila::popElem() {
	Nodo* aux;
	int valor = -1;
	if (!(this->esVacia())) {
		aux = tope;
		valor = tope->getInfo();
		tope = tope->getSig();
		longitud--;
		delete aux;
	}
	return valor;
}

//En PilaEnt.cpp:
bool Pila::pushElem(int pElem) {
	Nodo* nuevo = new Nodo(pElem);
	if (nuevo == NULL) {
		return false;
	}
	else {
		if (this->esVacia()) {
			tope = nuevo;
		}
		else {
			nuevo->setSig(tope);
			tope = nuevo;
		}
		longitud++;
		return true;
	}
}

//En PilaEnt.cpp:
bool Pila::esVacia() {
	bool pilaVacia = false;
	if (getTope() == NULL) {
		pilaVacia = true;
	}
	return pilaVacia;
}

string Pila::recorrerPila() {
	string rslt = "";
	if (getTope() == NULL) {
		rslt = "Pila vacia";
	}
	else {
		Nodo* aux = getTope();
		int contador = 1;
		do {
			rslt += "Dato(" + to_string(contador) + ")=" + to_string(aux->getInfo()) + "\n";
			aux = aux->getSig();
			contador++;
		} while (aux != NULL);
	}
	return rslt;
}
