#include "ImprimePilaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ImprimePilaOptionHandler::ImprimePilaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool ImprimePilaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    Imprimir();

    return true;
}

void ImprimePilaOptionHandler::Imprimir()
{
    cout << m_gestor->imprimirPila() << endl;
}

ImprimePilaOptionHandler::~ImprimePilaOptionHandler()
{
    delete m_gestor;
}
