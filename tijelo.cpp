#include <iostream>

#include "Header.h"




Vektor* vektor_novi(int kap) {
	Vektor* v = new Vektor;
	v->niz = new int[kap];
	v->log_vel = 0;
	v->fiz_vel = kap;
	return v;
}

void vektor_obrisi(Vektor* v) {
	delete[] v->niz;
	delete v;
}

void vektor_dodaj(Vektor* v, int el) {
	if (v->log_vel >= v->fiz_vel) {
		v->fiz_vel *= 2;
		int* novi = new int[v->fiz_vel];
		for (int i = 0; i < v->log_vel; i++) novi[i] = v->niz[i];
		delete[] v->niz;
		v->niz = novi;
	}
	v->niz[v->log_vel++] = el;
}

void vektor_ukloni(Vektor* v) {
	if (v->log_vel > 0) v->log_vel--;
}

int vektor_prvi(Vektor* v) {
	return v->niz[0];
}

int vektor_zadnji(Vektor* v) {
	return v->niz[v->log_vel - 1];
}

int vektor_velicina(Vektor* v) {
	return v->log_vel;
}
