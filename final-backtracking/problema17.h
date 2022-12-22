#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Se considera un numar natural n <= 100. Sa se determine
// toate modurile de scriere a lui ca suma de numere prime.
// Solutiile obtinute vor fi afisate pe ecran, cate una pe
// fiecare linie.

int n, dim = 0;
int x[100], s[1000];

int countDiv(int x) {
	int c = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			c++;
		}
	}
	return c;
}

bool prim(int x) {
	if (countDiv(x) == 2) {
		return 1;
	}
	return 0;
}

void atribuire() {
	for (int i = 2; i <= n; i++) {
		if (prim(i)) {
			x[dim] = i;
			dim++;
		}
	}
}

void tipar(int k) {
	for (int i = 0; i < k + 1; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

int sumaSolutie(int k) {
	int suma = 0;
	for (int i = 0; i < k + 1; i++) {
		suma += s[i];
	}
	return suma;
}

int solutie(int k) {
	int suma = sumaSolutie(k);
	if (n == suma) {
		return 1;
	}
	else if (n < suma) {
		return -1;
	}
	return 0;
}

bool valid(int k) {
	for (int i = 0; i < k; i++) {
		if (s[i] > s[i + 1]) {
			return 0;
		}
	}
	return 1;
}

void back(int k) {
	bool a = true;
	for (int i = 0; i < dim && a; i++) {
		s[k] = x[i];
		if (valid(k)) {
			int p = solutie(k);
			if (p == 1) {
				tipar(k);
			}
			else if (p == -1) {
				a = false;
			}
			else {
				back(k + 1);
			}
		}
	}
}

void rezolvare() {
	cout << "Introduceti n : ";
	cin >> n;
	atribuire();
	back(0);
}
