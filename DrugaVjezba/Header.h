struct Vektor {
	int* niz;
	int log_vel;
	int fiz_vel;
};

Vektor* vektor_novi(int kap);

void vektor_obrisi(Vektor* v);

void vektor_dodaj(Vektor* v, int el);

void vektor_ukloni(Vektor* v);

int vektor_prvi(Vektor* v);

int vektor_zadnji(Vektor* v);

int vektor_velicina(Vektor* v);
