#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Fiind data o matrice A (nxn) cu elemente
// numere naturale, se cere sa se determine
// cea mai mare suma a n valori, luate
// din linii si coloane diferite.

// 1  3<  5
// 9< 2   4  -------- 9 + 3 + 47 = 59  
// 6  1  47<

struct Pozitie {
	int linie = -1;
	int coloana = -1;
};

int n;
int x[100][100];
Pozitie s[100];
int valori[100], dim = 0;

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << x[s[i].linie][s[i].coloana] << " ";
	}
	cout << endl;
}

void adaugare() {
	int suma = 0;
	for (int i = 0; i < 3; i++) {
		suma += x[s[i].linie][s[i].coloana];
	}
	valori[dim] = suma;
	dim++;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i].linie == s[k].linie || s[i].coloana == s[k].coloana) {
			return 0;
		}
	}
	return 1;
}

bool solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s[k].linie = i;
			s[k].coloana = j;

			if (valid(k)) {
				if (solutie(k)) {
					adaugare();
				}
				else {
					back(k + 1);
				}
			}
		}
	}
}

void citire() {
	ifstream f("tema-12-01-problema-17-numere.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> x[i][j];
		}
	}
	f.close();
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
	cout << "Maximul este : " << max(valori, dim) << endl;
}