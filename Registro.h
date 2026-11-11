#pragma once
#include <string>

using namespace std;

class Registro {
    private:
        string placa;
        string categoria;
        int cobro;
    public:
        Registro (string placa, string categoria, int cobro);
        ~Registro();
        string getPalca ()const;
        string getCategoria ()const;
        int getCobro ()const;
};