#pragma once
class AbstractOptionHandler
{
    public:
        AbstractOptionHandler(int p_option);
        virtual ~AbstractOptionHandler();

        AbstractOptionHandler* SetNext(AbstractOptionHandler* p_handler);
        virtual bool Handle(int p_selected_option) = 0;

    protected:
        AbstractOptionHandler* m_next;
        bool HasNext();
        bool CanHandle(int p_selected_option);
        int m_option;
};

