/*
	File:  basicTemplates.cpp

	Author: Don Snyder

	Function: C++ program to demonstrate the use of basic "templates" for STL
            and meta-programming..

	Credit:  The foundation of this example is found here -
      www.TheCherno.com
			https://www.youtube.com/watch?v=I-hZkUa9mIs&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=54&t=0s

*/
#include <iostream>
#include <string>


#define LOGX(x) std::cout << x << std::endl;
#define LOGXY(x, y) std::cout << x << y << std::endl;

// Templates allows for dynamically specifying types so that multiple
// versions of a method don't have to be made, one for each type.
// Note:  the temp function doesn't exist until compile time, when and if
// the template function is called.  A typo in the definition will not
// cause a compile error if the function is not called.  Some compilers like
// clang are exceptions to this though.

// Each time the function is called with a different type the compiler provides
// another verions of the function explicitly adding that type.
template<typename T>
void print(T value) {
  std::cout << "Type output: " << value << std::endl;
}

template<typename T, int N>
class Array {
private:
    T m_Array[N];
public:
    int getSize() const {
      return N;
    }
};

int main ()
{
  LOGX("\nStarting basicTemplates examples...\n");

  print("string output");
  print(5);
  print(10.7);

  // Can also specify type but not needed.
  // Compiler can deduce type from input.
  print<int>(8);

  // With the template, the array can be of any type and size,
  // (within the confines of the platform of course.)
  Array<int, 5> array;

  LOGXY("\nSize of array: ", array.getSize());

  LOGX("\nbasicTemplates examples ended...\n\n");
  return 0;
}
