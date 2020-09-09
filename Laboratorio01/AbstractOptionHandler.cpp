#include "AbstractOptionHandler.h"

#include <iostream>

using namespace std;

AbstractOptionHandler::AbstractOptionHandler(int p_option)
{
    m_next = nullptr;
    m_option = p_option;
}

AbstractOptionHandler* AbstractOptionHandler::SetNext(AbstractOptionHandler* p_handler)
{
    m_next = p_handler;
    return m_next;
}

bool AbstractOptionHandler::CanHandle(int p_selected_option)
{
    return m_option == p_selected_option;
}

bool AbstractOptionHandler::HasNext()
{
    return m_next != nullptr;
}

AbstractOptionHandler::~AbstractOptionHandler()
{
    if (m_next != nullptr) delete m_next;
}