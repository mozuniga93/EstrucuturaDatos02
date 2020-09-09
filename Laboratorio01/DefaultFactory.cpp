#include "DefaultFactory.h"
#include "Gestor.h"
#include "AbstractOptionHandler.h"
#include "InsertaListaOptionHandler.h"
#include "InsertaPilaOptionHandler.h"
#include "InsertaColaOptionHandler.h"
#include "ListaToPilaOptionHandler.h"
#include "ListaToColaOptionHandler.h"
#include "PilaToColaOptionHandler.h"
#include "PilaToListaOptionHandler.h"
#include "ColaToPilaOptionHandler.h"
#include "ColaToListaOptionHandler.h"
#include "ImprimeListaOptionHandler.h"
#include "ImprimePilaOptionHandler.h"
#include "ImprimeColaOptionHandler.h"
#include "ExitOptionHandler.h"
#include "UnknownOptionHandler.h"
#include "MainMenu.h"

#include <string>
#include <iostream>

using namespace std;

DefaultFactory::DefaultFactory()
{
	m_gestor = nullptr; 
	m_handler = nullptr;
	m_menu = nullptr;
}

Gestor* DefaultFactory::CreateGestor()
{
	if (m_gestor == nullptr)
		m_gestor = new Gestor();

	return m_gestor;
}

AbstractOptionHandler* DefaultFactory::CreateMenuOptionHandler()
{	
	if (m_handler == nullptr)
	{
		//armando la cadena de responsabilidad ()

		Gestor* gestor = CreateGestor();
		m_handler = new InsertaListaOptionHandler(gestor, 1); //1er slabón de la cadena
		AbstractOptionHandler* insertaPilaHandler = new InsertaPilaOptionHandler(gestor, 2);	
		AbstractOptionHandler* insertaColaHandler = new InsertaColaOptionHandler(gestor, 3);	
		AbstractOptionHandler* listaToPilaHandler = new ListaToPilaOptionHandler(gestor, 4);
		AbstractOptionHandler* listaToColaHandler = new ListaToColaOptionHandler(gestor, 5);
		AbstractOptionHandler* pilaToColaHandler = new PilaToColaOptionHandler(gestor, 6);
		AbstractOptionHandler* pilaToListaHandler = new PilaToListaOptionHandler(gestor, 7);
		AbstractOptionHandler* colaToPilaHandler = new ColaToPilaOptionHandler(gestor, 8);
		AbstractOptionHandler* colaToListaHandler = new ColaToListaOptionHandler(gestor, 9);
		AbstractOptionHandler* printListaHandler = new ImprimeListaOptionHandler(gestor, 10);
		AbstractOptionHandler* printPilaHandler = new ImprimePilaOptionHandler(gestor, 11);
		AbstractOptionHandler* printColaHandler = new ImprimeColaOptionHandler(gestor, 12);
		AbstractOptionHandler* exitHandler = new ExitOptionHandler(0);
		AbstractOptionHandler* unknownOptionHandler = new UnknownOptionHandler();				

		m_handler->SetNext(insertaPilaHandler)	//eslabón 2
				 ->SetNext(insertaColaHandler)	//eslabón 3
				 ->SetNext(listaToPilaHandler)
				 ->SetNext(listaToColaHandler)
				 ->SetNext(pilaToColaHandler)
				 ->SetNext(pilaToListaHandler)
				 ->SetNext(colaToPilaHandler)
				 ->SetNext(colaToListaHandler)
				 ->SetNext(printListaHandler)
				 ->SetNext(printPilaHandler)
				 ->SetNext(printColaHandler)
				 ->SetNext(exitHandler)
				 ->SetNext(unknownOptionHandler); //último eslabón de la cadena.
	}

	return m_handler;
}

MainMenu* DefaultFactory::CreateMainMenu()
{
	if (m_menu == nullptr)
	{
		AbstractOptionHandler* handler = CreateMenuOptionHandler();
		m_menu = new MainMenu(handler);
	}

	return m_menu;
}

DefaultFactory::~DefaultFactory()
{
	delete m_gestor;
	delete m_handler;
	delete m_menu;
}