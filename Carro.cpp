#include "Carro.h"
#include "Variante.h"
#include "Excepciones.h"

Carro::Carro (string placa, int pasajeros) : Vehiculo(placa) {
	if (pasajeros < 1)
		throw DatosInvalidosExcep("El carro debe llevar al menos un pasajero.");
	this->pasajeros = pasajeros;
}

Carro::~Carro () {
	cout << "Destruyendo carro " << placa << endl;
}

string Carro::getTipo () const { return "Carro"; }
int Carro::getPasajeros () const { return pasajeros; }
void Carro::subirPasajero () { pasajeros++; }

string Carro::info () const {
	return Vehiculo::info() + " pasajeros: " + to_string(pasajeros);
}

int Carro::cobrar () const {
	return descuento(CARRO);
}
