#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class InsertaListaOptionHandler :
    public AbstractOptionHandler
{
    public:
        InsertaListaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~InsertaListaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void InsertarEnLista();

    private:
        Gestor* m_gestor;
};

