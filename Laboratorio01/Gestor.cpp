#include "Gestor.h"
#include "Cola.h"
#include "Pila.h"

string Gestor::insertarEnLista(const int pDato) {
	bool msg;
	string resp;
	msg = lista.agregarOrdenado(pDato);
	if (msg) {
		resp = "Numero entero agregado con exito a la lista.";
	}
	else {
		resp = "Numero entero no se pudo agregar a la lista. Intente de nuevo.";
	}
	return resp;
}

string Gestor::insertarEnPila(const int pDato) {
	bool msg;
	string resp;
	msg = pila.pushElem(pDato);
	if (msg) {
		resp = "Numero entero agregado con exito a la pila.";
	}
	else {
		resp = "Numero entero no se pudo agregar a la pila. Intente de nuevo.";
	}
	return resp;
}

string Gestor::insertarEnCola(const int pDato) {
	bool msg;
	string resp;
	cola.insertarElem(pDato);
	resp = "Numero entero agregado con exito a la cola.";
	return resp;
}

string Gestor::pasarListaAPila() {
	int num;
	string resp;
	num = lista.pasarElementoLista();
	if (num != -1) {
		pila.pushElem(num);
		resp += "El ultimo elemento de la lista correspondiente a  " + to_string(num) + ", se paso de la lista a la pila. " + "\n";
	}
	else {
		resp = "La lista se encuentra vacia.";
	}
	return resp;
}

string Gestor::pasarListaACola() {
	int num;
	string resp;
	num = lista.pasarElementoLista();
	if (num != -1) {
		cola.insertarElem(num);
		resp += "El ultimo elemento de la lista correspondiente a  " + to_string(num) + ", se paso de la lista a la cola. " + "\n";
	}
	else {
		resp = "La lista se encuentra vacia.";
	}
	return resp;
}

string Gestor::pasarPilaACola() {
	int num;
	string resp;
	num = pila.popElem();
	if (num != -1) {
		cola.insertarElem(num);
		resp += "El ultimo elemento de la pila correspondiente a  " + to_string(num) + ", se paso de la pila a la cola. " + "\n";
	}
	else {
		resp = "La pila se encuentra vacia.";
	}
	return resp;
}

string Gestor::pasarPilaALista() {
	int num;
	string resp;
	num = pila.popElem();
	if (num != -1) {
		lista.agregarOrdenado(num);
		resp += "El ultimo elemento de la pila correspondiente a  " + to_string(num) + ", se paso de la pila a la lista. " + "\n";
	}
	else {
		resp = "La pila se encuentra vacia.";
	}
	return resp;
}


string Gestor::pasarColaAPila() {
	int num;
	string resp;
	num = cola.pasarColaAPila();
	if (num != -1) {
		pila.pushElem(num);
		resp += "El primer elemento de la cola correspondiente a " + to_string(num) + ", se paso de la cola a la pila. " + "\n";
	}
	else {
		resp = "La cola se encuentra vacia.";
	}
	return resp;
}

string Gestor::pasarColaALista() {
	int num;
	string resp;
	num = cola.pasarColaAPila();
	if (num != -1) {
		lista.agregarOrdenado(num);
		resp += "El primer elemento de la cola correspondiente a " + to_string(num) + ", se paso de la cola a la lista. " + "\n";
	}
	else {
		resp = "La cola se encuentra vacia.";
	}
	return resp;
}

string Gestor::imprimirLista() {
	string msg = lista.recorrerListaEnlazada();
	return msg;
}

string Gestor::imprimirPila() {
	string msg = pila.recorrerPila();
	return msg;
}

string Gestor::imprimirCola() {
	string msg = cola.recorrerCola();
	return msg;
}
