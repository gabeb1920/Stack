/* Name: Gabriel Beedles
* Filename: mainStack.cpp
* Date Modified: 15/4/2015
*
* Purpose: Contains a main function to test the implementation of a stack
*
*/

#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
	Stack<int> intStack;

	for (int i = 0; i < 10; ++i)
		intStack.push(i);

	cout << "Top element in the stack is: " << intStack.peek() << endl;
	cout << "Stack capacity is: " << intStack.getCapacity() << " and size is: " << intStack.getSize() << endl;

	cout << "intStack contains:\n" << intStack << endl;

	cout << "At the end the stack capacity is: " << intStack.getCapacity() << " and size is: " << intStack.getSize() << endl;

	int junk;
	cin >> junk;

	return 0;
}