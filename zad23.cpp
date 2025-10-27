#include <iostream>
#include <vector>


struct Vector {
	int* data; 
	size_t size; 
	size_t capacity; 
};


Vector* vector_new(size_t init_capacity) {
	Vector* v = new Vector;
	v->data = new int[init_capacity];
	v->size = 0;
	v->capacity = init_capacity;
	return v;
}


void vector_delete(Vector* v) {
	delete[] v->data;
	delete v;
}


void vector_push_back(Vector* v, int value) {
	if (v->size >= v->capacity) {
		size_t new_capacity = v->capacity * 2;
		int* new_data = new int[new_capacity];
		for (size_t i = 0; i < v->size; ++i)
			new_data[i] = v->data[i];
		delete[] v->data;
		v->data = new_data;
		v->capacity = new_capacity;
	}
	v->data[v->size++] = value;
}


void vector_pop_back(Vector* v) {
	if (v->size > 0)
		v->size--;
	else
		std::cerr << "Vector je prazan!\n";
}


int vector_front(const Vector* v) {
	if (v->size == 0) {
		std::cerr << "Vector je prazan!\n";
		std::exit(EXIT_FAILURE);
	}
	return v->data[0];
}


int vector_back(const Vector* v) {
	if (v->size == 0) {
		std::cerr << "Vector je prazan!\n";
		std::exit(EXIT_FAILURE);
	}
	return v->data[v->size - 1];
}


size_t vector_size(const Vector* v) {
	return v->size;
}


void vector_print(const Vector* v) {
	std::cout << "[ ";
	for (size_t i = 0; i < v->size; ++i)
		std::cout << v->data[i] << " ";
	std::cout << "]\n";
}


int main() {
	Vector* v = vector_new(2); 

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30); 

	std::cout << "Sadržaj vektora: ";
	vector_print(v);

	std::cout << "Prvi element: " << vector_front(v) << "\n";
	std::cout << "Zadnji element: " << vector_back(v) << "\n";
	std::cout << "Veličina: " << vector_size(v) << "\n";

	vector_pop_back(v);
	std::cout << "Nakon pop_back:\n";
	vector_print(v);

	vector_delete(v);
	return 0;
}