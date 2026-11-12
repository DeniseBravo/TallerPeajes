#include "Moto.h"
#include "Variante.h"
#include "Excepciones.h"

const int CILINDRAJE_ALTO = 400;

Moto::Moto (string placa, int cilindraje) : Vehiculo(placa) {
	if (cilindraje <= 0)
		throw DatosInvalidosExcep("El cilindraje de la moto debe ser mayor que cero");
	this->cilindraje = cilindraje;
}

Moto::~Moto () {
	cout << "Destruyendo moto " << placa << endl;
}

string Moto::getTipo () const { return "Moto"; }
int Moto::getCilindraje () const { return cilindraje; }
bool Moto::esAltoCilindraje () const { return cilindraje > CILINDRAJE_ALTO; }

string Moto::info () const {
	return Vehiculo::info() + " cilindraje: " + to_string(cilindraje) + " cc" + (esAltoCilindraje() ? " (alto cilindraje)" : "");
}

int Moto::cobrar () const {
	return descuento(MOTO);
}
