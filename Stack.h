/* Name: Gabriel Beedles
* Filename: Stack.h
* Date Modified: 15/4/2015
*
* Purpose: Contains an implementation of a stack
*
*/

#include <iostream>

#ifndef _Stack_
#define _Stack_
template <class T>
class Stack {
private:
	int capacity;
	int size;
	T * data;
	// Internal functions
	void grow();
public:
	// Constructors
	Stack() {
		capacity = 0;
		size = 0;
		data = NULL;
	}
	Stack(int newCapacity) {
		capacity = newCapacity;
		size = 0;
		data = new T[capacity];
	}
	Stack(const Stack & newStack);
	// Destructor
	~Stack() { if (data != NULL) delete [] data; }
	// Essential Functions
	bool pop();
	void push(const T newData);
	// Get Functions
	T peek() { return data[size-1]; }
	int getSize() { return size; }
	int getCapacity() { return capacity; }
	// Set Functions
	void setCapacity(const int newCapacity);
	// Overloaded Operators
	template <class U>
	friend std::ostream& operator<<(std::ostream& out, Stack<U>& rhs);
	// Other Functions
	bool isEmpty() { return size; }
};

// Private/Internal Functions
template <class T>
void Stack<T>::grow() {
	if (capacity == 0) {
		data = new T[1];
		capacity = 1;
	}
	else {
		// Create a new stack with double the size
		T * temp = new T[capacity * 2];
		// Copy the old stack into the new one
		for (int i = 0; i < size; ++i)
			temp[i] = data[i];
		// Delete the old stack
		delete[] data;
		// Make data point to the new stack
		data = temp;
		capacity = capacity * 2;
	}
}

// Public Functions
// Constructors
template <class T>
Stack<T>::Stack(const Stack & newStack) {
	capacity = newStack->capacity;
	size = newStack->size;
	if (size > 0) {
		data = new T[capacity];
		for (int i = 0; i < size; ++i)
			data[i] = newStack.data[i];
	}
	else
		data = NULL;
}

// Essential Functions
template <class T>
bool Stack<T>::pop() {
	if (size != 0) {
		--size;
		return true;
	}
	else
		return false;
}

template <class T>
void Stack<T>::push(const T newData) {
	if (size == capacity) {
		this->grow();
	}
	data[size++] = newData;
}

// Set Functions
template <class T>
void Stack<T>::setCapacity(const int newCapacity) {
	T * temp = new T[newCapacity];
	// Copy the old stack into the new one
	int copying = 0;
	if (size > newCapacity)
		copying = newCapacity;
	else
		copying = size;
	for (int i = 0; i < copying; ++i)
		temp[i] = data[i];
	// Delete the old stack
	delete[] data;
	// Make data point to the new stack
	data = temp;
	capacity = newCapacity;
}

// Overloaded Operators
template <class T>
std::ostream& operator<<(std::ostream& out, Stack<T>& rhs) {
	while(rhs.size > 0) {
		out << rhs.peek() << endl;
		rhs.pop();
	}
	return out;
}
#endif