/*
	File:  basicReferences.cpp

	Author: Don Snyder

	Function: C++ program to demonstrate the use of basic "references".

	Credit:  The foundation of this example is found here -
      www.TheCherno.com
			https://www.youtube.com/watch?v=IzoFn3dfsPA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=18&t=0s

*/
#include <iostream>

#define LOG(x, y) std::cout << x << y << std::endl;

// Passed by value put's a new value on the stack;
// its not the original value though.
void IncrementByValue(int value) {
  value++;
}

// Passed pointer to value to function
void IncrementWithPtr(int *value) {
  (*value)++;   //Deference the pointer to reach the value to be incremented.
  	  	  	  	//This is needed so that the value is incremented; not the pointer}
}

// Passed a reference to function
void IncrementWithReference(int& value) {
  value++;      //Reference simplifies the syntax.
}

int main ()
{
  int a = 5;
  LOG("a passed to Increment: ", a);
  IncrementByValue(a);
  LOG("a is not incremented in IncrementByValue because it was passed by value: ", a);
  IncrementWithPtr(&a); //Use address of operator to pass the address to the function.
                        //& is not a reference here
  LOG("a is incremented in IncrementWithPtr: ", a);
  //IncrementWithReference(a); //As definition defines, call creates a refence to a.
  LOG("a is incremented in IncrementWithReference: ", a);

                // USE OF THE & DEPENDS ON CONTEXT
  int* d = &a;  // This is not a reference; its a use of the "address of operator"

  int& ref = a; // This is a reference; and alias to a pointer.  The & is part
                // of the type declaration.  ref can be used as if it is "a".

  ref = 2;

  int b = 8;
  ref = b;      //Can reset the reference to b; a is now equal to 8

  LOG("Value of ref: ", ref);

  //int& ref2;    //Cannot do this; must set the refence to something
                //Generates a compile error
  return 0;
}
