#include "MainMenu.h"
#include "AbstractOptionHandler.h"

#include <string>
#include <iostream>

using namespace std;

MainMenu::MainMenu(AbstractOptionHandler* p_handler)
{
    if (p_handler == nullptr)
        throw std::invalid_argument("p_handler no puede ser nulo.");

    m_handler = p_handler;
}

void MainMenu::Display()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Favor digite un numero del menu:" << endl;
        cout << "1. Insertar en Lista Ordenada." << endl;
        cout << "2. Insertar en Pila." << endl;
        cout << "3. Insertar en Cola." << endl;
        cout << "4. Pasar de Lista a Pila." << endl;
        cout << "5. Pasar de Lista a Cola." << endl;
        cout << "6. Pasar de Pila a Cola." << endl;
        cout << "7. Pasar de Pila a Lista." << endl;
        cout << "8. Pasar de Cola a Pila." << endl;
        cout << "9. Pasar de Cola a Lista." << endl;
        cout << "10. Imprimir Lista." << endl;
        cout << "11. Imprimir Pila." << endl;
        cout << "12. Imprimir Cola." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        /*menu(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }*/

        keepLooping = m_handler->Handle(answer);

    } while (keepLooping);
}

MainMenu::~MainMenu()
{
    delete m_handler;
}