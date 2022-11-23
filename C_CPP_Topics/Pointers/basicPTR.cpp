/*
	File:  basicPTR.cpp

	Author: Don Snyder

	Function: C++ program to demonstrate basic memory pointer operations.

	Credit:  The foundation of this example is found here -
			http://www.cplusplus.com/doc/tutorial/pointers/
*/
#include <iostream>
using namespace std;

int main ()
{
  void* vPtr = NULL; 		//A void pointer; typeless
				//C++11 introduce nullptr, C++ keyword
  int num = 10;
  vPtr = &num;			// Any type can be applied here.
  
  //double* dPtr = &num;  	// This would cause a compile error; not of the same type.
	
  int* iPtr = &num;
  // void* iPtr = &num;		// This line would be ok but the assignment that follows would be an error.
				// The type is needed so that the compiler knows what to allocate for storage.
  *iPtr = 10;
	
  int firstvalue, secondvalue;
  int * mypointer;

  mypointer  = &firstvalue;   	// What is the memory address of firstvalue?
  *mypointer = 10;		// Deferencing the pointer so that the value can be stored at the memory location.
				// Can now read from or write to the data pointed to by the pointer value.
  mypointer = &secondvalue;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
	
  //-------------------------------------------------------------------------------------------
  // Pointers to buffers and data on the heap.
	
  char* memBuffer = new char[8];  // Creates eight byte buffer; address of the beginning of the memory is stored in memBuffer
  memset(memBuffer, 0, 8);  	  // Initializes the memBuffer
	
  char** pPtr = &buffer; 	  // Pointer to a pointer...A pointer that contains a pointer.  So, pPtr contains a pointer 
				  // points to buffer.
	
  delete[] = memBuffer;
	
  return 0;
}
