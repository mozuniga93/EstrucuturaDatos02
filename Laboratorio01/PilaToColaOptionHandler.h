#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class PilaToColaOptionHandler :
    public AbstractOptionHandler
{
    public:
        PilaToColaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~PilaToColaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Pasar();

    private:
        Gestor* m_gestor;
};

