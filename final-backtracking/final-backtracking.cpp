#include "problema-mouse-metoda-2.h"

int main() {
	citire();
	cout << n << " " << m << " " << x << " " << y << " " << z << " " << t << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n\n";
	/*bordare();*/
	for (int i = 0; i < n + 2 ; i++) {
		for (int j = 0; j < m + 2 ; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	back(x-1, y-1);
}