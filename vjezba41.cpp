#include <iostream>
#include <vector>
using namespace std;


void input_vector(vector<int>& v) {
	int broj;
	cout << "Unosite brojeve : ";
	while (true) {
		cin >> broj;
		if (broj == 0)
			break;
		v.push_back(broj);
	}
}


void print_vector(const vector<int>& v) {
	cout << "Vektor: ";
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}


int main() {
	vector<int> v;
	input_vector(v);
	print_vector(v);
	return 0;
}
