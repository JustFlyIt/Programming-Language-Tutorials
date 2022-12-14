/*
	File:  basicPTR.cpp

	Author: Don Snyder

	Function: C++ program to demonstrate basic memory pointer operations.

	Credit:  The foundation of this example is found here -
			http://www.cplusplus.com/doc/tutorial/pointers/
			http://tutors.ics.uci.edu/index.php/tutor-resources/81-cpp-resources/122-cpp-ref-pointer-operators
			https://www.youtube.com/watch?v=DTxHyVn0ODg&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=16


	A pointer is an integer that stores a memory address. "*" denotes a pointer.  "**" denotes a pointer to a pointer.
	The pointer is "typed" so that the compiler knows what to allocate for storage.  A TYPE DOES NOT CHANGES WHAT A POINTER IS OR DOES.
	A "void" pointer is the purest of pointers; not types."

	Summary - C++ memory pointer operators

	FOR VARIABLE DECLARATIONS-------------------------------------
    & when used with a variable declaration: "reference to"
    Example: int &ra = a;
    "ra is a reference to a"

    SPECIAL NOTE - WHEN THE & IS NEXT TO THE TYPE IT IS REFERENCE, NOT AN OPERATOR
    SEE REFERENCE TUTORIAL FOR MORE ON THIS.  REFERENCE IS AN ALIAS

    * when used with a variable declaration: "pointer to"
    Example: int *pa;
    "pa is a pointer to an integer"

	FOR ALREADY DECLARED VARIABLES-------------------------------
    & when used with an already declared variable: "address of"
    Example: &a;
    "address of a"

    * when used with an already declared pointer: "dereference"
    Example: std::cout << *pa << std::endl;
    "print the underlying value of a"

    MEMORY FUNCTIONS
    memset - allocate a specified value to memory
*/

#include <iostream>
using namespace std;

int main ()
{
  //-------------------------------------------------------------------------------------------
  // STACK BASED OPERATIONS
  void* vPtr = NULL; //A void pointer; type-less
					 //C++11 introduce nullptr, C++ keyword
  int num = 10;
  vPtr = &num;
  
  //double* dPtr = &num; // This would cause a compile error; not of the same type.
	
  int* iPtr = &num;
  // void* iPtr = &num;	// This line would be ok but the assignment that follows would be an error.
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
  // HEAP BASED OPERATIONS
  char* memBuffer = new char[8];  // Creates eight byte buffer; address of the beginning of the memory is stored in memBuffer
  memset(memBuffer, 0, 8);  	  // Initializes the memBuffer using a specified value.
	
  char** pPtr = &buffer;  // Pointer to a pointer...A pointer that contains a pointer.  So, pPtr contains a pointer
				  	  	  // points to buffer.
	
  delete[] = memBuffer;	// Delete memory allocated from the heap.
	
  return 0;
}
