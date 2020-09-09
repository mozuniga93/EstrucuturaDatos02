#include "ExitOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

ExitOptionHandler::ExitOptionHandler(int p_option) : AbstractOptionHandler(p_option)
{
}

bool ExitOptionHandler::Handle(int p_selected_option)
{
    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    cout << "Gracias por usar el sistema." << endl;
    return false;
}

ExitOptionHandler::~ExitOptionHandler()
{
}