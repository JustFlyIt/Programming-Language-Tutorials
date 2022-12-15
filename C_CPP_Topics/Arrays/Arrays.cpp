//============================================================================
// Name        : FunctionPointer.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Demonstrate the use and effect of the function pointers.
//
//============================================================================
#include <iostream>
#include <vector>

void StatusFunction() {
  static int id = 1;

  std::cout << "StatusFunction has been called; id - " << id << std::endl << std::endl;

  id++;
}

void StatusFunction2() {
  int id = 1;

  std::cout << "StatusFunction has been called; id - " << id << std::endl << std::endl;

  id++;
}

void StatusFunctionWithParam(int id) {

  std::cout << "StatusFunction has been called; id - " << id << std::endl << std::endl;

  id++;
}

void ProcessFunction (int value) {
  std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*processFunction)(int)) {
  for (int value : values)
    processFunction(value);
}

int main(int argc, const char * argv[]) {
    std::cout << "Function Pointer Demonstration Started" << "\n\n";

    // General Function Call Demo:  Non-pointer call to a function (normal)
    std::cout << "General Function Call Demo:  call the function StatusFunction()" << "\n\n";
    StatusFunction();

    // General Function Call Demo:  Non-pointer call to a function (normal)
    std::cout << "General Function Call Demo:  call the function StatusFunction2()" << "\n\n";
    StatusFunction2();

    // Function Pointer Declaration Demo:  Pointer call to a function - without auto
    std::cout << "Function Pointer Declaration Demo:  call the function StatusFunction()" << "\n\n";

    //For variables, specifies that the type of the variable that is being
    //declared will be automatically deduced from its initializer.
    void(*statusFunction2)();
    statusFunction2 = StatusFunction;

    // OR

    // void(*statusFunction2) = StatusFunction;

    statusFunction2();
    statusFunction2();

    // Auto Demo:  Pointer call to a function - with auto
    //             Auto is used to make declaration clearer, less complex
    std::cout << "Auto Demo:  call the function StatusFunction()" << "\n\n";

    //For variables, specifies that the type of the variable that is being
    //declared will be automatically deduced from its initializer.
    auto statusFunction3 = StatusFunction;
    statusFunction3();
    statusFunction3();

    // typedef Demo:  Pointer call to a function - with typedef
    //             typedef is used to make declaration clearer, less complex
    std::cout << "typedef Demo:  call the function StatusFunction()" << "\n\n";

    typedef void(*StatusFunctionType)();
    StatusFunctionType statusFunction4 = StatusFunction;

    statusFunction4();

    // Param Demo:  Pointer call to a function - with param
    //             typedef is used to make declaration clearer, less complex
    //             parameterized
    std::cout << "Param Demo:  call the function StatusFunctionWithParam(int)" << "\n\n";

    typedef void(*StatusFunctionTypeParam)(int);
    StatusFunctionTypeParam statusFunction5 = StatusFunctionWithParam;

    statusFunction5(10);
    statusFunction5(100);
    statusFunction5(1000);
    statusFunction5(10000);

    // ForEach Demo:  Pointer call to a function - with param
    //             typedef is used to make declaration clearer, less complex
    //             parameterized
    std::cout << "ForEach Demo:  call the function StatusFunctionWithParam(int)" << "\n\n";

    std::vector<int> values = { 1, 3, 5, 7, 11, 13};

    ForEach(values, ProcessFunction);

    std::cout << "\nFunction Pointer Demonstration Completed" << "\n\n";

    return 0;
}
