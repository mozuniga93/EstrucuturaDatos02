#pragma once
#include "AbstractOptionHandler.h"
#include "Gestor.h"

class ColaToPilaOptionHandler :
    public AbstractOptionHandler
{
    public:
        ColaToPilaOptionHandler(Gestor* p_gestor, int p_option);
        virtual ~ColaToPilaOptionHandler();

        bool Handle(int p_selected_option);

    protected:
        void Pasar();

    private:
        Gestor* m_gestor;
};

