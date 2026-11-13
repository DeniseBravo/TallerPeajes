#pragma once
#include <string>

using namespace std;

class Persona {
    protected:
        string nombre;
        string id;
    public:
        Persona (string nombre, string id);
        virtual ~Persona();
        string getNombre () const;
        string getId () const;
        virtual string mostrar () const =0;
};
