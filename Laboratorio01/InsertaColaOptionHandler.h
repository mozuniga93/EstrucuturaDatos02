#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class InsertaColaOptionHandler :
    public AbstractOptionHandler
{
    public:
        InsertaColaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~InsertaColaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void InsertarEnCola();

    private:
        Gestor* m_gestor;
};

