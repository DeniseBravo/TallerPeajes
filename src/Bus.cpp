#include "Bus.h"
#include "Variante.h"
#include "Excepciones.h"

Bus::Bus (string placa, int puestos) : Vehiculo(placa) {
	if (puestos < 1)
		throw DatosInvalidosExcep("El bus debe tener al menos un puesto.");
	this->puestos = puestos;
}

Bus::~Bus () {
	cout << "Destruyendo bus " << placa << endl;
}

string Bus::getTipo () const { return "Bus"; }
int Bus::getPuestos () const { return puestos; }

string Bus::info () const {
	return Vehiculo::info() + " puestos: " + to_string(puestos);
}
 int Bus:: cobrar () const {
	return BUS;
}
