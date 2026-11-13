#include "Vehiculo.h"
#include "Propietario.h"
#include "Variante.h"
#include "Excepciones.h"

void validarPlaca (const string & placa){	
	if (placa.find_first_not_of("\t\r\n") == string :: npos)
		throw PlacaInvalidaExcep ("La placa no puede estar vacía."); 
}

Vehiculo:: Vehiculo (string placa) : propietario (nullptr){
		validarPlaca (placa);
		this-> placa= placa;
}

Vehiculo:: ~Vehiculo(){}

string Vehiculo:: getPlaca () const { return placa; }

void Vehiculo:: setPlaca (string placa){
	validarPlaca (placa);
	this-> placa= placa;
}

Propietario* Vehiculo:: getPropietario () const {return propietario; }

void Vehiculo:: setPropietario (Propietario* propietario){
	this-> propietario= propietario;
}

int Vehiculo:: descuento (int tarifa) const{
	if (propietario != nullptr && propietario->esVecino())
		return tarifa * (100 - DESCUENTO)/ 100;
	return tarifa;
}

string Vehiculo:: info () const{
	return getTipo () + " " + placa;
}

ostream &operator << (ostream &os, const Vehiculo & vehiculo) {
	os << vehiculo.info();
	return os;
}
