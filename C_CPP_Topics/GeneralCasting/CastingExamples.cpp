//============================================================================
// Name        : CastingExamples.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Demonstrate various casting operations and their effects.
//
//============================================================================
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::cout << "Casting Demonstration Started" << "\n\n";

    // Demonstrate the use of static_cast
    std::cout << "The following demonstrates the results from a static_cast: " << std::endl << std::endl;
    double x = 5 + static_cast<double>(12.75);
    std::cout << "Value of x: " << x << std::endl << std::endl;

    double x2 = 5 + (double)12.75;
    std::cout << "Value of x2 without static_cast: " << x2 << std::endl << std::endl;

    // Demonstrate a compilable bad casting
    std::cout << "The following is a cast that compiles but produces bad results: " << std::endl << std::endl;
    char c = 10;  // 1 byte
    std::cout << "Before cast:  value c: " << +c << std::endl << std::endl;

    int *p = (int*)&c;  //The address of one byte c has been put to a integer
                        //pointer.  When p is written to, it is assumed that
                        //the memory allocated is four bytes instead of one.
                        //This is a problem.

    *p = 1065727;   //Error: stack corruption?

    //Notice the output from the following statement. c is now -1 (all 16 bits set to one.).
    //Deferenced *p is the value assigned above: 1065727.  c was cast to a four byte integer
    //even though it is actually a one byte char.  Since c and p are stack hosted
    //variables, something somewhere is screwed up, even if it hasn't manifested
    //itself yet.
    std::cout << "After cast:  values of c, and deferenced p: " << +c << "  " << "  " << *p << std::endl << std::endl;

    std::cout << "\nCasting Demonstration Completed" << "\n\n";

    return 0;
}
