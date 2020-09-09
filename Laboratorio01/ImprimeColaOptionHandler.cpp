#include "ImprimeColaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ImprimeColaOptionHandler::ImprimeColaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool ImprimeColaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    Imprimir();

    return true;
}

void ImprimeColaOptionHandler::Imprimir()
{
    cout << m_gestor->imprimirCola() << endl;
}

ImprimeColaOptionHandler::~ImprimeColaOptionHandler()
{
    delete m_gestor;
}