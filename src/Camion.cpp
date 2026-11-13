#include "Camion.h"
#include "Variante.h"
#include "Excepciones.h"

Camion::Camion (string placa, int ejes) : Vehiculo(placa) {
	if (ejes < 2)
		throw DatosInvalidosExcep("El camion debe tener al menos dos ejes");
	this->ejes = ejes;
}

Camion::~Camion () {
	cout << "Destruyendo camion " << placa << endl;
}

string Camion::getTipo () const { return "Camion"; }
int Camion::getEjes () const { return ejes; }
void Camion::agregarEje () { ejes++; }

string Camion::info () const {
	return Vehiculo::info() + " ejes: " + to_string(ejes);
}

int Camion::cobrar () const {
	return CAMION_EJE * ejes;
}
