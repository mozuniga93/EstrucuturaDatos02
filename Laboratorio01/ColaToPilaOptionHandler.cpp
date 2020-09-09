#include "ColaToPilaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ColaToPilaOptionHandler::ColaToPilaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool ColaToPilaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    Pasar();

    return true;
}

void ColaToPilaOptionHandler::Pasar()
{
    cout << m_gestor->pasarColaAPila() << endl;
}

ColaToPilaOptionHandler::~ColaToPilaOptionHandler()
{
    delete m_gestor;
}