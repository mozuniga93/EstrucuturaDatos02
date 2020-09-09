#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ColaToListaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ColaToListaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ColaToListaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Pasar();

    private:
        Gestor* m_gestor;
};

