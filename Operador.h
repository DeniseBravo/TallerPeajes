#pragma once 
#include "Persona.h"

class Operador : public Persona{
    private: 
        string codigo;
    public:
        Operador (string nombre, string id, string codigo);
        ~Operador();
        string getCodigo () const;
        string mostrar () const override;
};