#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>

using namespace std;

enum Zog { KUPE, SPADE, DINARE, BASTE };

class Karta {
public:
	int broj;  
	Zog zog;

	Karta(int broj, Zog zog) : broj(broj), zog(zog) {}
};

class Mac {
public:
	vector<Karta> karte;

	Mac() {
		for (int z = KUPE; z <= BASTE; z++)
			for (int b = 1; b <= 10; b++)
				karte.emplace_back(b, (Zog)z);
	}

	void promijesaj() {
		auto rng = default_random_engine(time(nullptr));
		shuffle(karte.begin(), karte.end(), rng);
	}

	vector<Karta> podijeli() {
		vector<Karta> ruka(karte.begin(), karte.begin() + 10);
		karte.erase(karte.begin(), karte.begin() + 10);
		return ruka;
	}
};

class Igrac {
public:
	string ime;
	vector<Karta> ruka;
	int bodovi = 0;

	Igrac(string ime) : ime(ime) {}

	void primiKarte(vector<Karta> k) {
		ruka = k;
	}

	void akuza() {
		map<Zog, int> ima1;
		map<Zog, int> ima2;
		map<Zog, int> ima3;

		map<int, int> brojKarata;

		for (auto &k : ruka) {
			brojKarata[k.broj]++;

			if (k.broj == 1) ima1[k.zog]++;
			if (k.broj == 2) ima2[k.zog]++;
			if (k.broj == 3) ima3[k.zog]++;
		}

		
		for (int z = KUPE; z <= BASTE; z++) {
			if (ima1[(Zog)z] > 0 && ima2[(Zog)z] > 0 && ima3[(Zog)z] > 0) {
				bodovi += 3;
			}
		}

		
		for (auto &x : brojKarata) {
			if (x.second >= 3 && (x.first == 1 || x.first == 2 || x.first == 3)) {
				if (x.second == 3) bodovi += 3;
				if (x.second == 4) bodovi += 4;
			}
		}
	}
};

string nazivZoga(Zog z) {
	switch (z) {
	case KUPE: return "kupe";
	case SPADE: return "spade";
	case DINARE: return "dinare";
	case BASTE: return "baste";
	}
	return "?";
}

string nazivBroja(int b) {
	switch (b) {
	case 1: return "As";
	case 2: return "Duja";
	case 3: return "Trica";
	}
	return to_string(b);
}

int main() {
	int brojIgraca;
	cout << "Unesi broj igraca (2 ili 4): ";
	cin >> brojIgraca;

	while (brojIgraca != 2 && brojIgraca != 4) {
		cout << "Nepodrzan broj igraca. Unesi 2 ili 4: ";
		cin >> brojIgraca;
	}

	vector<Igrac> igraci;
	for (int i = 0; i < brojIgraca; i++) {
		cout << "Unesi ime igraca #" << (i + 1) << ": ";
		string ime;
		cin >> ime;
		igraci.emplace_back(ime);
	}

	Mac mac;
	mac.promijesaj();

	for (auto &igr : igraci) {
		igr.primiKarte(mac.podijeli());
	}

	
	for (auto &igr : igraci) {
		cout << "\nKarte igraca " << igr.ime << ":\n";
		for (auto &k : igr.ruka) {
			cout << "  " << nazivBroja(k.broj) << " od " << nazivZoga(k.zog) << endl;
		}
	}

	
	for (auto &igr : igraci) {
		igr.akuza();
	}

	cout << "\n\n--- Rezultati akuze ---\n";
	for (auto &igr : igraci) {
		cout << igr.ime << " ima " << igr.bodovi << " bodova iz akuze.\n";
	}

	return 0;
}
