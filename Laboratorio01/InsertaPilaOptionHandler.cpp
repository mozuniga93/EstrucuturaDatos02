#include "InsertaPilaOptionHandler.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

InsertaPilaOptionHandler::InsertaPilaOptionHandler(Gestor* p_gestor, int p_option) : AbstractOptionHandler(p_option)
{
    if (p_gestor == nullptr)
        throw std::invalid_argument("p_gestor no puede ser nulo.");

    m_gestor = p_gestor;
}

bool InsertaPilaOptionHandler::Handle(int p_selected_option)
{

    if (!CanHandle(p_selected_option))
    {
        return HasNext() ? m_next->Handle(p_selected_option) : true;
    }

    InsertarEnPila();

    return true;
}

void InsertaPilaOptionHandler::InsertarEnPila()
{
    int input = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite un numero entero a agregar: " << flush;
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

    cout << m_gestor->insertarEnPila(input) << endl;
}

InsertaPilaOptionHandler::~InsertaPilaOptionHandler()
{
    delete m_gestor;
}