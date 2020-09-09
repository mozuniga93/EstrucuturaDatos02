#include "ImprimeListaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ImprimeListaOptionHandler::ImprimeListaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool ImprimeListaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    Imprimir();

    return true;
}

void ImprimeListaOptionHandler::Imprimir()
{
    cout << m_gestor->imprimirLista() << endl;
}

ImprimeListaOptionHandler::~ImprimeListaOptionHandler()
{
    delete m_gestor;
}