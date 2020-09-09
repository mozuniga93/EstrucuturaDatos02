#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ImprimePilaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ImprimePilaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ImprimePilaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Imprimir();

    private:
        Gestor* m_gestor;

};

