#pragma once 
#include "Vehiculo.h"

class Carro : public Vehiculo{
    private:
        int pasajeros;
    public:
        Carro (string placa, int pasajeros);
        ~Carro();
        string getTipo ()cont override;
        int getPasajeros () const;
        void agregarPasajero ();
        string info () const override;
        int cobrar () const override;
};