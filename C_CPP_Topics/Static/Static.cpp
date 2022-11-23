//============================================================================
// Name        : Static.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Holds a static variable for test purposes.
//============================================================================

#include <iostream>

// static essentially makes this private to the
// local translation unit.  No other translation
// unit can see this variable.
static int s_variable1 = 5;

// Accessed by main.cpp via an extern statement.
int s_variable2 = 7;

// When undocumented at the same time as the same
// variable in main.cpp the following error occurs:
//    multiple definition of `s_variable3'
// int s_variable3 = 15;

// As with s_variable1, this cannot be seen
// by main.cpp, causing the following error:
// error: ‘s_variable4’ was not declared in this scope
static int s_variable4 = 15;

// As with variables, static essentially makes this private to the
// local translation unit.  No other translation
// unit can see this variable.
static void Function1() {
	std::cout << "static.cpp Function1 called" << "\n\n";
}

// Accessed by main.cpp via an extern statement.  If this were marked static,
// it would not be visible outside of the static.cpp translation unit.
static void Function2() {
	std::cout << "static.cpp Function2 called" << "\n\n";
}
