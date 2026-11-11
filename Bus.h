#pragma once 
#include "Vehiculo.h"

class Bus : public Vehiculo{
    private:
        int puestos;
    public:
        Bus (string placa, int puestos);
        ~Bus();
        string getTipo ()cont override;
        int getPuestos () const;
        string info () const override;
        int cobrar () const override;
};