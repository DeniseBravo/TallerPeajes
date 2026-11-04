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
