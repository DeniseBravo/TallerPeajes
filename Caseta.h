#pragma once 
#include <string>
#include <vector>
#include "Vehiculo.h"
#include "Operador.h"
#include "Registro.h"

using namespace std;

class Caseta{
    private:
        string nombre;
        Operador* operador;
        vector <Registro*> registros;
        int total;
    public:
        Caseta (string nombre, Operador* operador);
        ~Caseta ();
		Caseta (const Caseta&) = delete;
		Caseta& operator= (const Caseta&) = delete;

        string getNombre () const;
        Operador* getOperador () const;
        int registro (Vehiculo* vehiculo);
        int getTotal () const;
        int getCantidadRegistros ()const;
        int contarCategoria (const string)
}
