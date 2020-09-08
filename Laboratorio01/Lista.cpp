#include "Lista.h"
#include "stddef.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//constructor
Lista::Lista()
{
    setCabeza(NULL);
    setLargo(0);
}

//accessors
Nodo* Lista::getCabeza() const {
    return cabeza;
}
void Lista::setCabeza(Nodo* cabeza) {
    Lista::cabeza = cabeza;
}

int Lista::getLargo() {
    return largo;
}
void Lista::setLargo(int largo) {
    Lista::largo = largo;
}

std::string Lista::recorrerListaEnlazada() {
    string rslt = "";
    if (getCabeza() == NULL) {
        rslt = "Lista vacia";
    }
    else {
        Nodo* aux = getCabeza();
        int contador = 1;
        do {
            rslt += "Dato(" + to_string(contador) + ")=" + to_string(aux->getInfo()) + "\n";
            aux = aux->getSig();
            contador++;
        } while (aux != NULL);
    }
    return rslt;
}

bool Lista::agregarAlInicio(int pDato) {
    Nodo* nuevo = new Nodo();
    nuevo->setInfo(pDato);
    if (getCabeza() == NULL) {
        setCabeza(nuevo);
    }
    else {
        nuevo->setSig(this->cabeza);
        setCabeza(nuevo);
    }
    setLargo(getLargo() + 1);
    return true;
}

int Lista::buscarPosicionElemento(int pDato) {
    Nodo* aux;
    int pos;
    for (aux = getCabeza(), pos = 1; aux != NULL; aux = aux->getSig(), pos++) {
        if (aux->getInfo() == pDato) {
            return pos;
        }
    }
    if (aux == 0) {
        pos = -1;
    }
    return pos;
}

bool Lista::eliminarElemento(int pDato) {
    Nodo* aux, * ant;
    int i, pos = buscarPosicionElemento(pDato);
    if (pos == -1) {
        return false;
    }
    else {
        for (i = 1, ant = 0, aux = getCabeza(); i < pos; i++) {
            ant = aux;
            aux = aux->getSig();
        }

        if (ant != 0) {
            ant->setSig(aux->getSig());
        }
        else {
            setCabeza(aux->getSig());
        }

        delete aux;
        setLargo(getLargo() - 1);
        return true;
    }
}


bool Lista::eliminarElementoPorPosicion(int pPosicion) {
    Nodo* aux, * ant;
    int i;
    if (getCabeza() == NULL) {
        return false;
    }
    else {
        for (i = 1, ant = 0, aux = getCabeza(); aux->getSig() != NULL, i < pPosicion; i++) {
            ant = aux;
            aux = aux->getSig();
        }

        if (ant != 0) {
            ant->setSig(aux->getSig());
        }
        else {
            setCabeza(aux->getSig());
        }

        delete aux;
        setLargo(getLargo() - 1);
        return true;
    }
}



bool Lista::verificarListaVacia() {
    if (getCabeza() == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool Lista::agregarOrdenado(int pDato) {
    Nodo* nuevo = new Nodo();
    nuevo->setInfo(pDato);
    Nodo* aux = getCabeza();
    if (getCabeza() == NULL || nuevo->getInfo() < aux->getInfo()) {
        nuevo->setSig(getCabeza());
        setCabeza(nuevo);
    }
    else {
        while (aux->getSig() != NULL && aux->getSig()->getInfo() < nuevo->getInfo()) {
            aux = aux->getSig();
        }
        if (aux->getSig() != NULL) {
            nuevo->setSig(aux->getSig());
        }
        aux->setSig(nuevo);
    }
    setLargo(getLargo() + 1);
    return true;
}

string Lista::imprimirRecursividad(Nodo* nodoaux) {
    string rslt = "";
    std::stringstream sstm;
    if (nodoaux == NULL) {
        return rslt;
    }
    else {
        sstm << imprimirRecursividad(nodoaux->getSig()) << nodoaux->getInfo() << endl;
        rslt += sstm.str();
    }
    return rslt;
}

string Lista::imprimirInversa() {
    Nodo* aux = getCabeza();
    return imprimirRecursividad(aux);
}

bool Lista::verificarSemejanzaListas(Lista pLista1, Lista pLista2) {
    Nodo* aux = pLista1.getCabeza();
    Nodo* aux2 = pLista2.getCabeza();
    bool encuentra, rslt;

    for (int i = 1; aux != NULL; aux = aux->getSig(), i++) {
        encuentra = false;
        for (int j = 1; aux2 != NULL; aux2 = aux2->getSig(), j++) {
            if (aux->getInfo() == aux2->getInfo()) {
                encuentra = true;
                aux2 = pLista2.getCabeza();
                break;
            }
        }
        //Si encuentra es FALSE significa que las listas SON semejantes.
        if (!encuentra) {
            rslt = false;
            return rslt;
        }
    }

    //Si encuentra es TRUE significa que las listas SON semejantes.
    if (encuentra == true) {
        rslt = true;
        return rslt;
    }
}




