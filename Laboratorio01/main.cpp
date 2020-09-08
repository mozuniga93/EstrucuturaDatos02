// Monica Zuniga Arguedas
// José Rodríguez Villanueva
// Diego Herrera Jara
// Mario Sanchez Caracas
// Tarea 01: Estructura de Datos 02 

#include "Gestor.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Cola.h"
#include "Pila.h"

using namespace std;
// prototipo de funciones
int menu(int answer);
void insertarEnLista();
void insertarEnPila();
void insertarEnCola();
void pasarListaAPila();
void pasarListaACola();
void pasarPilaACola();
void pasarPilaALista();
void pasarColaAPila();
void pasarColaALista();
void imprimirLista();
void imprimirPila();
void imprimirCola();
static Gestor* gestor = new Gestor();

int main()
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

        menu(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

int menu(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnLista();
        break;
    case 2:
        insertarEnPila();
        break;
    case 3:
        insertarEnCola();
        break;
    case 4:
        pasarListaAPila();
        break;
    case 5:
        pasarListaACola();
        break;
    case 6:
        pasarPilaACola();
        break;
    case 7:
        pasarPilaALista();
        break;
    case 8:
        pasarColaAPila();
        break;
    case 9:
        pasarColaALista();
        break;
    case 10:
        imprimirLista();
        break;
    case 11:
        imprimirPila();
        break;
    case 12:
        imprimirCola();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

void insertarEnLista()
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

    cout << gestor->insertarEnLista(input) << endl;
}

void insertarEnPila()
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

    cout << gestor->insertarEnPila(input) << endl;
}

void insertarEnCola()
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

    cout << gestor->insertarEnCola(input) << endl;
}

void pasarListaAPila()
{

    cout << gestor->pasarPilaACola() << endl;
}


void pasarListaACola()
{

    cout << gestor->pasarPilaACola() << endl;
}


void pasarPilaACola()
{

    cout << gestor->pasarPilaACola() << endl;
}

void pasarPilaALista()
{

    cout << gestor->pasarPilaACola() << endl;
}

void pasarColaAPila()
{
    cout << gestor->pasarColaAPila() << endl;
}

void pasarColaALista()
{
    cout << gestor->pasarColaAPila() << endl;
}

void imprimirLista()
{

    cout << gestor->imprimirLista() << endl;
}

void imprimirPila()
{
    cout << gestor->imprimirPila() << endl;
}

void imprimirCola()
{
    cout << gestor->imprimirCola() << endl;
}

