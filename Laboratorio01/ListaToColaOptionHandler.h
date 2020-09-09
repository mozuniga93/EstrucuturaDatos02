#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ListaToColaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ListaToColaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ListaToColaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Pasar();

    private:
        Gestor* m_gestor;
};

