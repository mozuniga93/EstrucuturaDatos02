#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class PilaToListaOptionHandler :
    public AbstractOptionHandler
{
    public:
        PilaToListaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~PilaToListaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Pasar();

    private:
        Gestor* m_gestor;
};

