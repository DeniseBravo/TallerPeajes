#include "Persona.h"
#include "Excepciones.h"

bool vacio (const string& s) {
	return s.find_first_not_of(" \t\r\n") == string::npos;
}

Persona::Persona (string nombre, string id) {
	if (vacio(nombre))
		throw DatosInvalidosExcep("El nombre no puede estar vacio");
	if (vacio(id))
		throw DatosInvalidosExcep("El documento no puede estar vacio");
	this->nombre = nombre;
	this->id = id;
}

Persona::~Persona () {}
string Persona::getNombre () const { return nombre; }
string Persona::getId () const { return id; }
