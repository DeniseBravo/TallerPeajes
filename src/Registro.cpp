#include "Registro.h"
#include <iostream>

Registro::Registro(string placa, string categoria, int cobro): placa (placa), categoria (categoria), cobro(cobro){}

Registro::~Registro (){
	cout << "Destruyendo registro " << placa << endl;
}
	
string Registro:: getPlaca () const {return placa; }
string Registro:: getCategoria () const {return categoria;}
int Registro:: getCobro () const {return cobro; }
