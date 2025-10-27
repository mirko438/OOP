#include <iostream>
#include <vector>
using namespace std;

double** alociraj(int m, int n) {
	double** A = new double*[m];
	for (int i = 0; i < m; i++) A[i] = new double[n];
	return A;
}

void dealociraj(double** A, int m) {
	for (int i = 0; i < m; i++) delete[] A[i];
	delete[] A;
}

void unesi(double** A, int m, int n) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
}

void generiraj(double** A, int m, int n, double a, double b) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = a + (double)rand() / RAND_MAX * (b - a);
}

void ispisi(double** A, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(10) << fixed << setprecision(4) << A[i][j];
		cout << endl;
	}
}

double** zbroji(double** A, double** B, int m, int n) {
	double** C = alociraj(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
}

double** oduzmi(double** A, double** B, int m, int n) {
	double** C = alociraj(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = A[i][j] - B[i][j];
	return C;
}

double** transponiraj(double** A, int m, int n) {
	double** T = alociraj(n, m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			T[j][i] = A[i][j];
	return T;
}

double** pomnozi(double** A, double** B, int m, int n, int p) {
	double** C = alociraj(m, p);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	return C;
}

int main() {
	srand(time(0));
	int m = 2, n = 3;
	double** A = alociraj(m, n);
	double** B = alociraj(m, n);
	generiraj(A, m, n, -5, 5);
	generiraj(B, m, n, -5, 5);

	cout << "A:\n"; ispisi(A, m, n);
	cout << "\nB:\n"; ispisi(B, m, n);

	double** C = zbroji(A, B, m, n);
	cout << "\nA + B:\n"; ispisi(C, m, n);

	double** T = transponiraj(A, m, n);
	cout << "\nTransponirana A:\n"; ispisi(T, n, m);

	dealociraj(A, m);
	dealociraj(B, m);
	dealociraj(C, m);
	dealociraj(T, n);
}