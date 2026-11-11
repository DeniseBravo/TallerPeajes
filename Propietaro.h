#pragma once
#include "Persona.h"

class Propietario : public Persona{
    private:
        bool vecino;
    public:
        Propietario (string nombre, string id, bool vecino);
        ~Propietario ();
        bool esVecino ();
        string mostrat () const override;
};