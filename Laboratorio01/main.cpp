// Monica Zuniga Arguedas
// José Rodríguez Villanueva
// Diego Herrera Jara
// Mario Sanchez Caracas
// Tarea 01: Estructura de Datos 02 

#include "DefaultFactory.h"
#include "MainMenu.h"

using namespace std;

int main()
{
    DefaultFactory* factory = new DefaultFactory();
    MainMenu* menu = factory->CreateMainMenu();

    menu->Display();

    return 0;
}
