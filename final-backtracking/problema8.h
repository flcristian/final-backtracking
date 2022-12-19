#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Se citesc de la tastatura numerele naturale n <= 10^9
// si S <= 45. Sa se afiseze toate submultimile de suma S,
// formate din cifrele lui n. Fisierul text subm.out va
// contine, pe cate o linie, cifrele dintr-o submultime
// generata.

struct Solutie {
	int x[100];
	int d;
};

int n, S, dim, c = 0;
int x[100];
int s[100];
Solutie solutii[100];

bool apare(int numar, int k) {
	for (int i = 0; i < k; i++) {
		if (x[i] == numar) {
			return 1;
		}
	}
	return 0;
}

int numarCifre() {
	int c = 0;
	int aux = n;
	while (n != 0) {
		c++;
		n /= 10;

	}
	n = aux;
	return c;
}

void atribuire() {
	dim = 0;
	int i = 0;
	int countCifre = numarCifre();
	int aux = n;
	while (n != 0) {
		int cifra = n / pow(10, countCifre - 1 - i);
		if (!apare(cifra, dim)) {
			x[dim] = cifra;
			dim++;
		}
		n = n % (int)(pow(10, countCifre - 1 - i));
		i++;
	}
	n = aux;
}

void tiparSiAdaugare(int k) {
	for (int i = 0; i < k; i++) {
		solutii[c].x[i] = s[i];
		cout << s[i] << " ";
	}
	solutii[c].d = k;
	cout << endl;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] >= s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int sumaSolutie(int k) {
	int suma = 0;
	for (int i = 0; i < k; i++) {
		suma += s[i];
	}
	return suma;
}

int solutie(int k) {
	int suma = sumaSolutie(k + 1);
	if (suma == S) {
		return 1;
	}
	else if (suma > S) {
		return -1;
	}
	return 0;
}

void back(int k) {
	bool sumaMaiMica = true;
	for (int i = 0; i < dim && sumaMaiMica; i++) {
		s[k] = x[i];
		if (valid(k)) {
			int sol = solutie(k);
			if (sol == 1) {
				tiparSiAdaugare(k + 1);
				c++;
			}
			else if (sol == -1) {
				sumaMaiMica = false;
			}
			else {
				back(k + 1);
			}
		}
	}
}

void output() {
	ofstream f("problema7-out.txt");
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < solutii[i].d; j++) {
			f << solutii[i].x[j];
			if (j != solutii[i].d - 1) {
				f << " ";
			}
		}
		if (i != c - 1) {
			f << endl;
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	cout << "Introduceti S : ";
	cin >> S;

	atribuire();
	back(0);
	output();
}