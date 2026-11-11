#pragma once 
#include "Vehiculo.h"

class Camion : public Vehiculo{
    private:
        int ejes;
    public:
        Camion (string placa, int ejes);
        ~Camion();
        string getTipo ()cont override;
        int getEjes () const;
        void agregarEje ();
        string info () const override;
        int cobrar () const override;
};