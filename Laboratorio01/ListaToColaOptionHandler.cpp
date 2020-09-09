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
    cout << m_gestor->pasarPilaACola() << endl;
}

ListaToColaOptionHandler::~ListaToColaOptionHandler()
{
    delete m_gestor;
}