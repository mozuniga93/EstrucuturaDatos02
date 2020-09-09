#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ImprimeListaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ImprimeListaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ImprimeListaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Imprimir();

    private:
        Gestor* m_gestor;

};

