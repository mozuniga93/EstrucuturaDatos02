#pragma once
#include "AbstractOptionHandler.h"
class UnknownOptionHandler :
    public AbstractOptionHandler
{
    public:
        UnknownOptionHandler();
        virtual ~UnknownOptionHandler();

        bool Handle(int p_selected_option);
};

