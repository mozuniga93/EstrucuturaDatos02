#ifndef GESTOR_H
#define GESTOR_H
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include <string>
using namespace std;

class Gestor
{
private:
    Lista lista;
    Pila pila;
    Cola cola;
public:
    string insertarEnLista(const int);
    string insertarEnPila(const int);
    string insertarEnCola(const int);
    string pasarListaAPila(const int);
    string pasarListaACola(const int);
    string pasarPilaACola();
    string pasarPilaALista();
    string pasarColaAPila();
    string pasarColaALista();
    string imprimirLista();
    string imprimirPila();
    string imprimirCola();
    bool verificarListaVacia();
};

#endif