#include <iostream>
using namespace std;


int& at(int* arr, int i) {
	return arr[i];
}

int main() {
	int niz[5] = { 10, 20, 30, 40, 50 };

	cout << "Prije: " << niz[2] << endl;

	
	at(niz, 2)++;

	cout << "Poslije: " << niz[2] << endl;
	return 0;
}