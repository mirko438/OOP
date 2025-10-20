#include <iostream>
using namespace std;

int* fibonacci(int n)
{
	int* niz = new int[n];
	niz[0] = 1;
	niz[1] = 1;

	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];

	}
	return niz;

}

int main() {
	int n;
	cout << "unesite brojeve";
	cin >> n;
	int* niz = fibonacci(n);
	cout << "finonacci niz";
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";

	}
	delete[] niz;
	return 0;
}
