#include "UnknownOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

UnknownOptionHandler::UnknownOptionHandler() : AbstractOptionHandler(-1)
{
}

bool UnknownOptionHandler::Handle(int p_selected_option)
{
    cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    return true;
}

UnknownOptionHandler::~UnknownOptionHandler()
{
}