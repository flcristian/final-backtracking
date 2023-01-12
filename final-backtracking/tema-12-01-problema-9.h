#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Se citeste un numar natural n.
// Sa se determine numarul maxim
// obtinut prin eliminarea din numar k cifre.

int numar, n, m, d; // n = numar cifre.

struct Cifra {
	int valoare = -1;
	int pozitie = -1;

	Cifra() {
	}

	Cifra(int valoare, int pozitie) {
		this->valoare = valoare;
		this->pozitie = pozitie;
	}
};

Cifra x[100];
Cifra s[100];
int valori[100];
int dim = 0;

void tipar() {
	for (int i = 0; i < d; i++) {
		cout << s[i].valoare;
	}
	cout << endl;
}

void atribuire() {
	int r = 0;
	for (int i = 0; i < d; i++) {
		r = r * 10 + s[i].valoare;
	}
	valori[dim] = r;
	dim++;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i].valoare == s[k].valoare) {
			return 0;
		}
		if (s[i].pozitie > s[i + 1].pozitie) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == d - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		s[k].valoare = x[i].valoare;
		s[k].pozitie = x[i].pozitie;
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
				atribuire();
			}
			else {
				back(k + 1);
			}
		}
	}
}

int numarCifre(int x) {
	int c = 0;
	while (x != 0) {
		c++;
		x /= 10;
	}
	return c;
}

void citire() {
	cout << "Introduceti numarul : ";
	cin >> numar;
	cout << "Introduceti m : ";
	cin >> m;

	int r = numar;
	int i = numarCifre(r);
	n = i;
	d = n - m;
	i--;

	while (i != -1) {
		x[i].pozitie = i;
		x[i].valoare = r % 10;
		i--;
		r /= 10;
	}
}

int max(int x[], int d) {
	int maxim = x[0];
	for (int i = 1; i < d; i++) {
		if (x[i] > maxim) {
			maxim = x[i];
		}
	}
	return maxim;
}

void rezolvare() {
	citire();
	back(0);
	cout << "\nMaximul este : " << max(valori, dim) << endl;
}

