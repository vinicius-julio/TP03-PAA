#ifndef SHIFTAND_H
#define SHIFTAND_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAXTAMTEXTO 1000
#define MAXTAMPADRAO 10
#define MAXCHAR 256 //Defines para uso em algoritmo ShiftAnd aproximado
#define NUMMAXERROS 10
typedef char TipoTexto [MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];
void ShiftAndAproximado(TipoTexto t, long n, TipoPadrao P, long m, long k,int Operacoes[]);
#endif
