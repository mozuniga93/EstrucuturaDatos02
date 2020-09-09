#pragma once

#include "Gestor.h"
#include "AbstractOptionHandler.h"
#include "MainMenu.h"

class DefaultFactory
{
	public:
		DefaultFactory();
		virtual ~DefaultFactory();

		Gestor* CreateGestor();
		AbstractOptionHandler* CreateMenuOptionHandler();
		MainMenu* CreateMainMenu();

	private:
		Gestor* m_gestor;
		AbstractOptionHandler* m_handler;
		MainMenu* m_menu;

};

