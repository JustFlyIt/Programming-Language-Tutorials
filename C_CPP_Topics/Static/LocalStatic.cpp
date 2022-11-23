//============================================================================
// Name        : LocalStatic.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Demonstrate the use and effect of the static keyword.
//
//               Context: static in function (local scope)
//                        Focus on scope and lifetime of the variable.
//============================================================================
#include <iostream>
#include <bits/stdc++.h>

void GeneralFunction(void) {
  int a = -1;
  static int x = 0;             // The declaration is only done for the first time
                                // that ths function is called.  The variable's
                                // state is continued during all subsequent calls.

                                // static variable is stored in the static area, not
                                // the stack.

                                // If the static variable is not initialized, it
                                // defaults to zero.
   std::cout << "GeneralFunction:x - " << x << "\n\n";

   x++;
}

class Singleton {
public:
  static Singleton& getInstance() {
    static Singleton instance;  // static is important here.  The instance will unintentionally
                                // be made on the first call.  static will preserve the statement
                                // through the subsequent calls.

    return instance;
  }

  void printId() {
    std::cout << "Singleton Id" << "\n\n";
  }
};


int main(int argc, const char * argv[]) {
    std::cout << "Local Static Test Started" << "\n\n";

    // First test:  Two different instances of Aircraft; each instance with its
    //              own attribute values.

    std::cout << "First test:  First call to GeneralFunction x is 0" << "\n";

    GeneralFunction();

    std::cout << "Second test:  Each following call to GeneralFunction increments x" << "\n";
    GeneralFunction();
    GeneralFunction();
    GeneralFunction();

    std::cout << "Third test:  A simple example...singleton." << "\n";

    Singleton::getInstance().printId();

    std::cout << "Local  Static Test Completed" << "\n\n";

    return 0;
}
