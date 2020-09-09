#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ImprimeColaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ImprimeColaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ImprimeColaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Imprimir();

    private:
        Gestor* m_gestor;

};

