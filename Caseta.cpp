#include "Caseta.h"
#include "Excepciones.h"

Caseta::Caseta (string nombre, Operador* operador) : operador(operador), total(0) {
	if (nombre.find_first_not_of(" \t\r\n") == string::npos)
		throw DatosInvalidosExcep("El nombre estar vacio");
	if (operador == nullptr)
		throw DatosInvalidosExcep("Es necesario un operador");
	this->nombre = nombre;
}

Caseta::~Caseta () {
	cout << "Destruyendo caseta " << nombre << endl;
	for (size_t i = 0; i < registros.size(); i++)
		delete registros[i];
}

string Caseta::getNombre () const { return nombre; }
Operador* Caseta::getOperador () const { return operador; }

int Caseta::registrar (Vehiculo* vehiculo) {
	if (vehiculo == nullptr)
		throw DatosInvalidosExcep("No se puede registrar el paso de un vehiculo nulo");
	int valor = vehiculo->cobrar();
	registros.push_back(new Registro(vehiculo->getPlaca(), vehiculo->getTipo(), valor));
	total += valor;
	return valor;
}

int Caseta::getTotal () const { return total; }
int Caseta::getCantidadRegistros () const { return (int)registros.size(); }

int Caseta::contarCategoria (const string& categoria) const {
	int n = 0;
	for (size_t i = 0; i < registros.size(); i++)
		if (registros[i]->getCategoria() == categoria) n++;
	return n;
}

void Caseta::cuadrarCaja (int declaracion) const {
	if (declaracion != total) {
		int dif = declaracion - total;
		string msj = "La caja no cuadra: declarado " + to_string(declaracion) + ", recaudado " + to_string(total)
			+ ", diferencia " + to_string(dif) + (dif < 0 ? " (faltante)" : " (sobrante)");
		throw DescuadreCajaExcep(msj, dif);
	}
}
