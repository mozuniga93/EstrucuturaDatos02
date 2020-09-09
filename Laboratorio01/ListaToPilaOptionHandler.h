#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ListaToPilaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ListaToPilaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ListaToPilaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Pasar();

    private:
        Gestor* m_gestor;
};

