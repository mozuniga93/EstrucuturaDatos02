#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class InsertaPilaOptionHandler :
    public AbstractOptionHandler
{
    public:
        InsertaPilaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~InsertaPilaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void InsertarEnPila();

    private:
        Gestor* m_gestor;
};

