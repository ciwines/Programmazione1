#include <iostream>
using namespace std;

/*
 *	OGNI OGGETTO PUO' AVERE PIU' DICHIARAZIONI MA UNA SOLA DEFINIZIONE
 *
 *	Ci sono generalmente 2N + 1 file -> main + N coppie (.cc e .h)
 *	I file <nome>.h (header) devono contenere le dichiarazioni di tutte le funzion/variabili/..
 *	definiti in <nome>.cc
 *
 *
 *
 *
 * 	g++ main.cc esempio.cc
 */

#include "esempio.h"

// extern void esempio();

int main() {
	for(int i = 0; i < 10; i++) {
		esempio();
	}

	return 0;
}