#include <iostream>
#include <string>
using namespace std;


struct Student {
	string ime;
	string jmbag;
	int godina;
	int ects;
	double prosjek;
};


void filter_students(Student arr[], size_t n,
	void(*akcija)(Student&),
	bool(*filter)(Student&))
{
	for (size_t i = 0; i < n; i++) {
		if (filter(arr[i])) {
			akcija(arr[i]);
		}
	}
}


void ispisiStudenta(Student &s) {
	cout << "Ime: " << s.ime
		<< ", JMBAG: " << s.jmbag
		<< ", Godina: " << s.godina
		<< ", ECTS: " << s.ects
		<< ", Prosjek: " << s.prosjek << endl;
}


void povecajGodinu(Student &s) {
	s.godina++;
}

int main() {
	
	Student studenti[] = {
		{"Ana",  "001", 1, 10, 4.0},
		{"Marko","002", 1, 0, 3.2},
		{"Iva",  "003", 2, 50, 4.1},
		{"Luka", "004", 3, 60, 3.7},
		{"Mia",  "005", 2, 40, 2.9}
	};
	size_t n = sizeof(studenti) / sizeof(studenti[0]);

	
	cout << "Studenti 1. godine koji su polozili barem jedan ispit:\n";
	auto uvjet1 = [](Student &s) { return s.godina == 1 && s.ects > 0; };
	filter_students(studenti, n, ispisiStudenta, uvjet1);
	cout << endl;

	
	cout << "Studenti s prosjekom vecim od 3.5:\n";
	auto uvjet2 = [](Student &s) { return s.prosjek > 3.5; };
	filter_students(studenti, n, ispisiStudenta, uvjet2);
	cout << endl;

	
	auto uvjet3 = [](Student &s) { return s.ects >= 45; };
	filter_students(studenti, n, povecajGodinu, uvjet3);

	
	cout << "Nakon povecanja godine:\n";
	for (auto &s : studenti) {
		ispisiStudenta(s);
	}

	return 0;
}
