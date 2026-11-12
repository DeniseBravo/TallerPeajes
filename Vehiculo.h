#pragma once
#include <iostream>
#include <string>

using namespace std;

class Propietario;

class Vehiculo {
	protected:
		string placa;
		Propietario* propietario;
		int descuento (tarifa) const;
	public:
		Vehiculo (string placa);
		virtual ~Vehiculo();
		virtual string getTipo () const =0;
		string getPlaca ()const;
		void setPlaca ();
		virtual string info ()const;
		virtual int cobrar ()const;
		Propietario* getPropietario ()const;
		void setPropietario (Propietario* propietario);
};

ostream &operator << (ostream &os, Vehiculo & Vehiculo);

