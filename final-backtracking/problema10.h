#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Consideram n <= 10 tipuri de monede. Din fiecare
// tip avem la dispozzitie un numar nelimitat de monede.
// Generati toate modalitatiile de plata a unei nume
// S <= 30000, in conditiile date. In fisierul monede.out
// vor fi afisate variantele, in formatul din exemplu.

struct Solutie {
	int x[100];
	int dim;
};

int n, S, c = 0;
int x[100];
Solutie s;
Solutie solutii[100];

int numarMaximMonede() {
	return S / x[0];
}

void tiparSiAdaugare() {
	int trecut = 0;
	for (int i = 0; i < s.dim; i++) {
		cout << s.x[i] << " ";
	}
	solutii[c] = s;
	cout << endl;
}

void citire() {
	cout << "Introduceti n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti moneda " << i + 1 << " : ";
		cin >> x[i];
	}
	cout << "Introduceti S : ";
	cin >> S;
}

void bubbleSort() {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

int sumaSolutie() {
	int suma = 0;
	for (int i = 0; i < s.dim; i++) {
		suma += s.x[i];
	}
	return suma;
}

int solutie(int k) {
	int suma = sumaSolutie();
	if (suma == S) {
		return 1;
	}
	else if (suma > S) {
		return -1;
	}
	else {
		return 0;
	}
}

//void back(int k) {
//	bool sumaMaiMica = true;
//	for (int i = 0; i < n && sumaMaiMica; i++) {
//		s.x[k] = x[i];
//		s.dim = k + 1;
//		int sol = solutie(k);
//		if (sol == 1) {
//			tiparSiAdaugare();
//			c++;
//		}
//		else if (sol == -1) {
//			sumaMaiMica = false;
//		}
//		else {
//			back(k + 1);
//		}
//	}
//}

void rezolvare() {
	citire();
	bubbleSort();
	cout << numarMaximMonede();
}