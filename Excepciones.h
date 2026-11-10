#pragma once 
#include <exception>
#include <string>

using namespace std;

class PlacaInvalidaExcep : public exception{
	private :
		string msj;
	public:
		PlacaInvalidaExcep (string msj);
		const char* what () const noexcept override;
};

class DatosInvalidosExcep : public exception{
	private:
		string msj;
	public:
		DatosInvalidosExcep(string msj);
		const char* what () const noexcept override;
};

class DescuadreCajaExcep : public exception{
	private:
		string msj;
		int diferencia;
	public :
		DescuadreCajaExcep (string msj, int diferencia);
		const char* what() const noexcept override;
		int getDiferencia () const;
};