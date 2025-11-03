#include <iostream>
using namespace std;


template <typename T>
void sortArray(T arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


template <typename T>
void printArray(T arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int intArr[] = { 5, 2, 9, 1, 5, 6 };
	double doubleArr[] = { 3.1, 2.4, 5.6, 1.2 };

	int n1 = sizeof(intArr) / sizeof(intArr[0]);
	int n2 = sizeof(doubleArr) / sizeof(doubleArr[0]);

	cout << "Prije sortiranja (int): ";
	printArray(intArr, n1);
	sortArray(intArr, n1);
	cout << "Poslie sortiranja (int): ";
	printArray(intArr, n1);

	cout << "\nPrije sortiranja (double): ";
	printArray(doubleArr, n2);
	sortArray(doubleArr, n2);
	cout << "Poslije sortiranja (double): ";
	printArray(doubleArr, n2);

	return 0;
}
