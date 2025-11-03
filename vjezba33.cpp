#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> niz = { 1, 2, 3, 4, 5, 6 };
	int suma = 0;
	int produkt = 1;
	int prag = 3;



	auto jeParan = [](int x) { return x % 2 == 0; };
	auto jeNeparan = [](int x) { return x % 2 != 0; };
	auto udvostruci = [](int x) { return 2 * x; };
	auto prepolovi = [](int x) { return x / 2; };

	
	auto dodajUSumu = [&](int x) { suma += x; };
	auto dodajUProdukt = [&](int x) { produkt *= x; };

	
	auto dodajAkoVeciOdPraga = [prag, &suma](int x) {
		if (x > prag) suma += x;
	};

	
	for (int &x : niz) {
		if (jeParan(x))
			x = prepolovi(x);
		else
			x = udvostruci(x);
	}

	cout << "Niz nakon prepolovljavanja/udvostrucavanja: ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	
	for (int x : niz) {
		dodajUSumu(x);
		dodajUProdukt(x);
	}

	cout << "Suma: " << suma << ", Produkt: " << produkt << endl;

	
	suma = 0;
	for (int x : niz) {
		dodajAkoVeciOdPraga(x);
	}

	cout << "Suma brojeva vecih od " << prag << " je: " << suma << endl;

	return 0;
}
