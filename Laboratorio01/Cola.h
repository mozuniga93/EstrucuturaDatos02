#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

class Cola
{
public:
    //constructor
    Cola(void); //Constructora
    int getLongitud(void) const; //Analizadora
    Nodo* getFrente(void) const; //Analizadora
    Nodo* getFinal(void) const; //Analizadora
    void setLongitud(int l); //Modificadora
    void setFrente(Nodo*); //Modificadora
    void setFinal(Nodo*); //Modificadora
    void insertarElem(int);
    bool eliminarElem();
    int pasarColaAPila();
    bool esVacia();


protected:
    Nodo* frente;
    Nodo* final;
    int longitud;
};

#endif
