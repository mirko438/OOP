#include "container.h"
using namespace std;

container::container(size_t initial_capacity)
	: data(nullptr), _size(0), _capacity(initial_capacity)
{
	if (_capacity > 0)
		data = new int[_capacity];
	cout << "Konstruktor: capacity=" << _capacity << endl;
}

container::container(const container& other)
{
	_capacity = other._capacity;
	_size = other._size;
	data = new int[_capacity];
	for (size_t i = 0; i < _size; i++)
		data[i] = other.data[i];
	cout << "Copy konstruktor" << endl;
}

container::container(container&& other) noexcept
{
	data = other.data;
	_size = other._size;
	_capacity = other._capacity;
	other.data = nullptr;
	other._size = 0;
	other._capacity = 0;
	cout << "Move konstruktor" << endl;
}

container::~container()
{
	delete[] data;
	cout << "Destruktor" << endl;
}

void container::push_back(int value)
{
	if (_size == _capacity)
	{
		size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
		int* new_data = new int[new_capacity];
		for (size_t i = 0; i < _size; i++)
			new_data[i] = data[i];
		delete[] data;
		data = new_data;
		_capacity = new_capacity;
		cout << "Realokacija: new capacity=" << _capacity << endl;
	}
	data[_size++] = value;
}

size_t container::size() const { return _size; }

size_t container::capacity() const { return _capacity; }

int& container::at(size_t index) { return data[index]; }

const int& container::at(size_t index) const { return data[index]; }

void container::clear() { _size = 0; }
