#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void input_vector(vector<int>& v) {
	int x;
	while (cin >> x && x != 0) {
		v.push_back(x);
	}
}

void print_vector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i + 1 < v.size()) cout << " ";
	}
	cout << "\n";
}

int main() {
	vector<int> v;
	cout << "Unesite brojeve (0 za kraj): ";
	input_vector(v);

	cout << "Originalni vektor: ";
	print_vector(v);

	vector<int> uniq;
	for (int x : v) {
		if (find(uniq.begin(), uniq.end(), x) == uniq.end()) {
			uniq.push_back(x);
		}
	}

	cout << "Jedinstveni elementi: ";
	print_vector(uniq);

	sort(uniq.begin(), uniq.end(), [](int a, int b) {
		return abs(a) < abs(b);
	});

	cout << "Sortirani po apsolutnoj vrijednosti: ";
	for (size_t i = 0; i < uniq.size(); ++i) {
		cout << uniq[i];
		if (i + 1 < uniq.size()) cout << ", ";
	}
	cout << "\n";

	return 0;
}
