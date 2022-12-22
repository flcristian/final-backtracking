#include <iostream>

using namespace std;
int x[100]{};
int monede[100] = { 0,10,2,4,8 };
int n=4, s = 0, suma=100, nr;

void tipar(int k) {

	for (int i = 1; i <= k; i++) {

		if (x[i] > 0) {
			cout << x[i] << "*" << monede[i] << " ";
		}
	}
	cout << endl;
}

void back(int k) {

	if (s == suma) {

		tipar(k-1);
	}
	else {

		x[k] = -1;
		while (x[k] * monede[k] + s < suma && k < n+1) {
			x[k] = x[k] + 1;
			s = s + x[k] * monede[k];
			back(k + 1);
			s = s - x[k] *monede[k];
		}
	}
}


void sol() {

	back(1);
	
}
