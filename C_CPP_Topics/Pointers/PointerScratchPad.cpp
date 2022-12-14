/*
	File:  PointerScratchPad.cpp

	Author: Don Snyder

	Function: C++ program to demonstrate basic memory pointer operations.

	Credit:  The foundation of this example is found here -
			http://www.cplusplus.com/doc/tutorial/pointers/
*/
#include <iostream>
using namespace std;

void increment(int value) {
	cout << "increment value called with = " << value << '\n';
	value++;
	cout << "incremented value:  " << value << '\n';
}

void incrementWithReference(int& value) {
	cout << "increment value (reference) called with = " << value << '\n';
	value++;
	cout << "incremented value (reference):  " << value << '\n';
}

int main ()
{
	int val1 = 4;  // Integer value contains 4.  Size of "int" is four bytes
	
	cout << "val1 = " << val1 << '\n';
	cout << "address of val1: " << &val1 << '\n';
	
	int *val2 = &val1;
	*val2 = 6;
	cout << "val1 = " << val1 << '\n';
	cout << "value pointed at by val2: " << *val2 << '\n';
	cout << "address contents of val2: " << val2 << '\n';

	int& val3aliasV1 = val1;
	val3aliasV1 = 9;
	cout << "val1 = " << val1 << '\n';

	increment(val1);
	cout << "val1 = " << val1 << '\n';

	incrementWithReference(val1);
	cout << "val1 = " << val1 << '\n';

	int** valPtr = &val2;
	cout << "address of val1: " << &val1 << '\n';
	cout << "int** valPtr = &val2;" << '\n';
	cout << "&valPtr = " << &valPtr << '\n';
	cout << "*valPtr = " << *valPtr << '\n';
	cout << "**valPtr = " << **valPtr << '\n';

	return 0;
}
