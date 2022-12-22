#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Consideram un vector A ce contine n <= 10 numere intregi.
// Sa se genereze toate permutarile acestuia care respecta
// conditia ca cel mai mic si cel mai mare numar sa
// ramana pe poizitii initiale. Datele se introduc de la
// tastatura, iar solutiile obtinute vor fi afisate pe ecran,
// cate una pe fiecare linie.

int n;
int maxim, minim, indiceMaxim, indiceMinim;
int x[100], s[100];

void tipar() {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
		if (s[i] == maxim && i != indiceMaxim) {
			return 0;
		}
		if (s[i] == minim && i != indiceMinim) {
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
		s[k] = x[i];
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void citire() {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti A[" << i << "] : ";
		cin >> x[i];
	}
}

void maximSiMinim() {
	int a = x[0], b = x[0];
	int ia = 0, ib = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > a) {
			a = x[i];
			ia = i;
		}
		if (x[i] < b) {
			b = x[i];
			ib = i;
		}
	}
	maxim = a;
	minim = b;
	indiceMaxim = ia;
	indiceMinim = ib;
}

void rezolvare() {
	citire();
	maximSiMinim();
	back(0);
}
