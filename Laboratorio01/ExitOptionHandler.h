#pragma once
#include "AbstractOptionHandler.h"

class ExitOptionHandler :
    public AbstractOptionHandler
{
    public:
        ExitOptionHandler(int p_option);
        virtual ~ExitOptionHandler();

        bool Handle(int p_selected_option);

};

