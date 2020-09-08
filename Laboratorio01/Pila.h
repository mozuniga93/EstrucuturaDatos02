#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

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
    bool popElem();
    int pasarPilaACola();
    bool esVacia();

protected:
    int longitud;
    Nodo* tope;
};

#endif
