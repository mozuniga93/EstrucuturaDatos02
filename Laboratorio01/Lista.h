#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <string>
using namespace std;

class Lista
{
public:
    //constructor
    Lista();

    //accessors
    Nodo* getCabeza() const;
    void setCabeza(Nodo* cabeza);
    std::string recorrerListaEnlazada();
    int getLargo();
    void setLargo(int);
    bool agregarAlInicio(int);
    bool eliminarElemento(int);
    int buscarPosicionElemento(int);
    bool eliminarElementoPorPosicion(int);
    bool verificarListaVacia();
    bool agregarOrdenado(int);
    bool verificarSemejanzaListas(Lista, Lista);
    string imprimirInversa();
    string imprimirRecursividad(Nodo*);
    int pasarElementoLista(int);

protected:
    Nodo* cabeza;
    int largo;
};

#endif