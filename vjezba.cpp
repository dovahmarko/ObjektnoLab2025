#include <iostream>
#include "Header.h"





int main() {
	Vektor* v = vektor_novi(2);
	vektor_dodaj(v, 5);
	vektor_dodaj(v, 10);
	vektor_dodaj(v, 15);
	std::cout << vektor_prvi(v) << " " << vektor_zadnji(v) << " " << vektor_velicina(v);
	vektor_ukloni(v);
	std::cout << "\n" << vektor_zadnji(v);
	vektor_obrisi(v);
	system("pause");
	return 0;
}


/*
int*  vrati_niz() {

	int* niz = new int[10]{ 1,1 };

	for (int i = 2; i < 10; i++) {

		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main()
{

	int* niz = vrati_niz();
	for (int i = 0; i < 10; i++)
	{
		std::cout << niz[i] << " " << std::endl;
	}

	delete[] niz;
	system("pause");
	return 0;
}
*/