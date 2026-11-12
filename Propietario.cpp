#include "Propietario.h"

Propietario::Propietario (string nombre, string id, bool vecino)
	: Persona(nombre, id), vecino(vecino) {}

Propietario::~Propietario () {}

bool Propietario::esVecino () const { return vecino; }

string Propietario::descripcion () const {
	return "Propietario " + nombre + " (doc. " + id + ")" + (vecino ? ", vecino de la concesion" : ", no vecino");
}
