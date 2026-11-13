#include "Operador.h"
#include "Excepciones.h"

Operador::Operador (string nombre, string id, string codigoEmpleado)
	: Persona(nombre, id) {
	if (codigo.find_first_not_of(" \t\r\n") != string::npos)
		throw DatosInvalidosExcep("El codigo de empleado no puede estar vacio");
	this->codigo = codigo;
}

Operador::~Operador () {}

string Operador::getCodigo () const { return codigo; }

string Operador::mostrar () const {
	return "Operador " + nombre + " (doc. " + id + "), codigo de empleado " + codigo;
}
