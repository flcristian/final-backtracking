#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Sa se genereze toate tablourile patratice
// binare de ordin n (n <= 10), care au proprietatea
// ca atat fiecare linie, cat si fiecare coloana
// contin exact un element egal cu 1. Fiecare tablou
// va fi afisat pe n linii in fisierul text matrice.out
// numerele in cadrul liniei fiind separate prin cate un
// spatiu. In fisier, intre tablourile rezultate va exista
// o linie goala.

int n, c, c2 = 0;
int s[100];

struct Multime {
	int indice;
	int y[100];

	Multime() {
	}

	Multime(int indice, int x[100]) {
		this->indice = indice;
		for (int i = 0; i < n; i++) {
			y[i] = x[i];
		}
	}
};

Multime x[100];
Multime s2[1000];
Multime solutiiOutput[1000][1000];

void atribuire() {
	Multime a(c, s);
	x[c] = a;
}

bool valid1(int k) {
	int c = 0;
	for (int i = 0; i <= k; i++) {
		if (s[i] == 0) {
			c++;
		}
		if (s[k] == s[i] && s[k] != 0 && i != k) {
			return 0;
		}
	}
	if (c == n) {
		return 0;
	}
	return 1;
}

bool solutie1(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back1(int k) {
	for (int i = 0; i < 2; i++) {
		s[k] = i;
		if (valid1(k)) {
			if (solutie1(k)) {
				atribuire();
				c++;
			}
			else {
				back1(k + 1);
			}
		}
	}
}

void tiparSiAtribuire() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			solutiiOutput[c2][i].y[j] = s2[i].y[j];
			cout << s2[i].y[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool valid2(int k) {
	for (int i = 0; i < k; i++) {
		if (s2[i].indice == s2[k].indice) {
			return 0;
		}
	}
	return 1;
}

bool solutie2(int k) {
	if (k == n - 1) {
		return 1;
	}
	return 0;
}

void back2(int k) {
	for (int i = 0; i < n; i++) {
		s2[k] = x[i];
		if (valid2(k)) {
			if (solutie2(k)) {
				tiparSiAtribuire();
				c2++;
			}
			else {
				back2(k + 1);
			}
		}
	}
}

void output() {
	ofstream f("problema3-out.txt");
	for (int i = 0; i < c2; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				f << solutiiOutput[i][j].y[k];
				if (k != n - 1) {
					f << " ";
				}
			}
			if (i != c2 - 1 || j != n - 1) {
				f << endl;
			}
		}
		if (i != c2 - 1) {
			f << endl;
		}
	}
	f.close();
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;

	c = 0;
	back1(0);
	back2(0);
	output();
}