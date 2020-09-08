#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include <string>
#include "stddef.h"
using namespace std;

class Pila
{
public:
    //constructor
    Pila(void); //Constructora
    int getLongitud(void) const; //Analizadora
    Nodo* getTope(void) const; //Analizadora
    void setLongitud(int l); //Modificadora
    void setTope(Nodo*); //Modificadora
    bool pushElem(int);
    int popElem();
    bool esVacia();
    string recorrerPila();

protected:
    int longitud;
    Nodo* tope;
};

#endif
