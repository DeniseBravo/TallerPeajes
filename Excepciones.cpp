#include "Excepciones.h"

PlacaInvalidaExcep :: PlacaInvalidaExcep (string msj) : msj (msj) {}
const char* PlacaInvalidaExcep:: what () const noexcept {return msj.c_str();}


DatosInvalidosExcep :: DatosInvalidosExcep (string msj) : msj (msj) {}
const char* DatosInvalidosExcep:: what () const noexcept {return msj.c_str();}

DescuadreCajaExcep :: DescuadreCajaExcep (string msj, int diferencia) : msj (msj), diferencia(diferencia) {}
const char* DescuadreCajaExcep:: what () const noexcept {return msj.c_str();}

int DescuadreCajaExcep:: getDiferencia()const {return diferencia; }
