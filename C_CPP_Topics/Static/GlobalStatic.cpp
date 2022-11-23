//============================================================================
// Name        : GlobalStatic.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Demonstrate the use and effect of the static keyword.
//
//               Context: global static, variables and functions
//============================================================================
#include <iostream>

// Same name as a variable in static.cpp; but a different value.
int s_variable1 = 10;

// Looks for the variable in an external translation
// unit...  static.cpp
extern int s_variable2;

// When undocumented at the same time as the same
// variable in static.cpp the following error occurs:
//    multiple definition of `s_variable3'
// int s_variable3 = 15;

// This function is the same as a static function in static.cpp.  When the
// static is removed from the same funciton in static.cpp the following error
// occurs:
//    multiple definition of `s_Function1()'
void Function1() {
    std::cout << "main.cpp Function1 called" << "\n\n";
}

// Looks for the function in an external translation
// unit...  static.cpp
extern void Function2();

int main(int argc, const char * argv[]) {
    std::cout << "Static Test Started" << "\n\n";

    std::cout << "s_variable1 = " << s_variable1 << "\n\n";

    std::cout << "s_variable2 = " << s_variable2 << "\n\n";

// See the s_variable3 note above regarding the multiple
// declaration error statement.
//    std::cout << "s_variable3 = " << s_variable3 << "\n\n";

// As with s_variable1, this cannot be seen
// by main.cpp, causing the following error:
// error: ‘s_variable4’ was not declared in this scope
//    std::cout << "s_variable4 = " << s_variable4 << "\n\n";

// There is a Function1 in both main.cpp and static.cpp.  The function in
// static.cpp is marked as static so it is not visible to this translation
// unit.
    Function1();

// This function call is supported by the above extern statement.  The Function2
// call in static.cpp is not marked static so it is visible to this translation
// unit.  If it were marked static, this error would occur:
//    undefined reference to `Function2()'
    Function2();

    std::cout << "Static Test Completed" << "\n\n";

    return 0;
}
