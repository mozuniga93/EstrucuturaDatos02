#include "Nodo.h"
#include "stddef.h"

//constructor
Nodo::Nodo()
{
    setInfo(0);
    setSig(NULL);
}

Nodo::Nodo(int info, Nodo* sig) : info(info), sig(sig)
{
}

Nodo::Nodo(int info) : info(info), sig(NULL)
{
}
//accessors
int Nodo::getInfo() const {
    return info;
}
void Nodo::setInfo(int info) {
    Nodo::info = info;
}

Nodo* Nodo::getSig() const {
    return sig;
}
void Nodo::setSig(Nodo* sig) {
    Nodo::sig = sig;
}
