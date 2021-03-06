#include "ListaToPilaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ListaToPilaOptionHandler::ListaToPilaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool ListaToPilaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    Pasar();

    return true;
}

void ListaToPilaOptionHandler::Pasar()
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
            cout << "Favor digite la posicion del elemento de la lista a pasar a pila: " << flush;
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

        cout << m_gestor->pasarListaAPila(input) << endl;
    }
}

ListaToPilaOptionHandler::~ListaToPilaOptionHandler()
{
    delete m_gestor;
}