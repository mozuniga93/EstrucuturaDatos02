#pragma once

#include "AbstractOptionHandler.h"

class MainMenu
{
	public:
		MainMenu(AbstractOptionHandler* p_handler);
		virtual ~MainMenu();

		void Display();

	private:
		AbstractOptionHandler* m_handler;
};

