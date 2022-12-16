#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Se citest ce la tastatura numerele naturale n <= 10 si
// m <= 50. Consideram primele m numere primee de cel putin
// doua cifre. Sa se scrie in fisierul prime.out toate
// sirurile de n numere prime dinstincte din cele m,
// fiecare sir scris pe cate o linie.

int n, m;
int s[100];
int solutii[1000][1000];