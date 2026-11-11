#pragma once 
#include "Vehiculo.h"

class Moto : public Vehiculo{
    private:
        int cilindraje;
    public:
        Moto (string placa, int cilindraje);
        ~Moto();
        string getTipo ()cont override;
        int getCilindraje () const;
        bool altoCilindraje () const;
        string info () const override;
        int cobrar () const override;
};