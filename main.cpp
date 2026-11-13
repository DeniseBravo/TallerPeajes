#include <iostream>
#include <vector>
#include "Persona.h"
#include "Propietario.h"
#include "Operador.h"
#include "Vehiculo.h"
#include "Carro.h"
#include "Moto.h"
#include "Bus.h"
#include "Camion.h"
#include "Caseta.h"
#include "Excepciones.h"

using namespace std;

int main () {
	vector<Persona*> personas;
	vector<Vehiculo*> vehiculos;
	Caseta* caseta = nullptr;
	
	try {
		Operador* operador = new Operador("Dennis Bravo", "1086419412", "EMP-001");
		personas.push_back(operador);
		Propietario* noVecino = new Propietario("Laura Ramirez", "1085904529", false);
		personas.push_back(noVecino);
		Propietario* vecino = new Propietario("Stephanie Mora", "1085925014", true);
		personas.push_back(vecino);
		caseta = new Caseta("Sur", operador);
		cout << "Personas: " << endl;
		
		for (size_t i = 0; i < personas.size(); i++)
			cout << personas[i]->mostrar() << endl;
		
		cout << "Casos: " << endl;
		
		Carro* carro = new Carro("ABC123", 3);
		vehiculos.push_back(carro);
		carro->setPropietario(noVecino);
		cout << "Caso 1: " << *carro << " paga: " << carro->cobrar() << endl;
		carro->setPropietario(vecino);
		cout << "Caso 2: " << *carro << " el propietario es vecino así que paga: " << carro->cobrar() << endl;
		
		Moto* moto1 = new Moto("XYZ45A", 125);
		vehiculos.push_back(moto1);
		moto1->setPropietario(vecino);
		cout << "Caso 3: " << *moto1 << " el propietario es vecino así que paga:" << moto1->cobrar() << endl;
		
		Moto* moto2 = new Moto("MOT650", 650);
		vehiculos.push_back(moto2);
		cout << "Caso 4: " << *moto2 << " paga " << moto2->cobrar() << ", es de alto cilindraje: " << (moto2->altoCilindraje() ? "Si" : "No") << endl;
		
		Bus* bus = new Bus("BUS777", 38);
		vehiculos.push_back(bus);
		bus->setPropietario(vecino);
		cout << "Caso 5: " << *bus << " el propietario es vecino, pero es bus así que paga: " << bus->cobrar() << endl;
		
		Camion* camion = new Camion("CAM301", 3);
		vehiculos.push_back(camion);
		cout << "Caso 6: " << *camion << " paga " << camion->cobrar() << endl;
		camion->agregarEje();
		cout << "Caso 7: " << *camion << " como tien un eje agregado, paga: " << camion->cobrar() << endl;
		
		try {
			Carro* malo = new Carro("", 2);
			vehiculos.push_back(malo);
			cout << "Caso 8: no se lanzo excepcion" << endl;
		} catch (const PlacaInvalidaExcep& e) {
			cout << "Caso 8: PlacaInvalidaExcep - " << e.what() << endl;
		}
	
		try {
			Camion* malo = new Camion("SFG542", 1);
			vehiculos.push_back(malo);
			cout << "Caso 9: no se lanzo excepcion" << endl;
		} catch (const DatosInvalidosExcep& e) {
			cout << "Caso 9: DatosInvalidosExcep - " << e.what() << endl;
		}
		
		Vehiculo* pasan[] = { carro, moto1, bus, camion };
		for (int i = 0; i < 4; i++)
			caseta->registrar(pasan[i]);
		cout << "Caso 10: total del día" << caseta->getTotal()
			<< " Carros: " << caseta->contarCategoria("Carro")
			<< ", Motos: " << caseta->contarCategoria("Moto")
			<< ", Buses: " << caseta->contarCategoria("Bus")
			<< ", Camiones: " << caseta->contarCategoria("Camion") << endl;
		
		try {
			caseta->cuadrarCaja(caseta->getTotal());
			cout << "Caso 11: la caja cuadra" << endl;
		} catch (const DescuadreCajaExcep& e) {
			cout << "Caso 11: DescuadreCajaExcep - " << e.what() << endl;
		}
		
		try {
			caseta->cuadrarCaja(caseta->getTotal() - 1000);
			cout << "Caso 12: la caja cuadra" << endl;
		} catch (const DescuadreCajaExcep& e) {
			cout << "Caso 12: DescuadreCajaExcep - " << e.what()
				<< " [diferencia: " << e.getDiferencia() << "]" << endl;
		}
		
		try {
			caseta->registrar(nullptr);
			cout << "Caso 14: no se lanzo excepcion" << endl;
		} catch (const DatosInvalidosExcep& e) {
			cout << "Caso 14 (extra): DatosInvalidosExcep - " << e.what() << endl;
		}
		
	} catch (const exception& e) {
		cout << "Error inesperado: " << e.what() << endl;
	}
	
	cout << "Caso 13: liberando la caseta y luego los vehiculos" << endl;
	delete caseta;
	for (size_t i = 0; i < vehiculos.size(); i++)
		delete vehiculos[i];
	for (size_t i = 0; i < personas.size(); i++)
		delete personas[i];
	
	return 0;
}
