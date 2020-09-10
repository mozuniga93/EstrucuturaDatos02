#include "ListaToColaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ListaToColaOptionHandler::ListaToColaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool ListaToColaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    Pasar();

    return true;
}

void ListaToColaOptionHandler::Pasar()
{
    bool listaVacia = m_gestor->verificarListaVacia();
    if (listaVacia) {
        cout << "La lista se encuentra vacia." << endl;
    }
    else {
        cout << m_gestor->imprimirLista() << endl;
        int input = -1;
        bool valid = false;
        do
        {
            cout << "Favor digite la posicion del elemento de la lista a pasar a cola: " << flush;
            cin >> input;
            if (cin.good())
            {
                valid = true;
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error. Favor inserte un numero entero." << endl;
            }
        } while (!valid);

        cout << m_gestor->pasarListaACola(input) << endl;
    }
}

ListaToColaOptionHandler::~ListaToColaOptionHandler()
{
    delete m_gestor;
}