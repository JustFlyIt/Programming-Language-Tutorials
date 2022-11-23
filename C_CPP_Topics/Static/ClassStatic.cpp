//============================================================================
// Name        : ClassStatic.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Demonstrate the use and effect of the static keyword.
//
//               Context: static in class and struct  Note: only structs are
//                        shown but the same applies to the class
//============================================================================
#include <iostream>
#include <bits/stdc++.h>

struct Aircraft {
  std::string id;
  int altitude;
  int speed;

  void printState() {
    std::cout << "Current Aircraft State - ID: " << id << "  Alitude: " << altitude << "  Speed: " << speed << "\n\n";
  }
};

struct Spacecraft {
  static std::string id;
  static int altitude;
  static int speed;
  int fuel; // Not static and causes an error in the printState below when the print
            // line that tries to use it is cnot ommented out.  Static functions cannot see
            // non-static variables because they are stored in different places within the
            // executable.  Static functions/methods do not have a struct/class instance where
            // struct variables or class attributes are visible.

  static void printState() {
    std::cout << "Current Spacecraft State - ID: " << id << "  Alitude: " << altitude << "  Speed: " << speed << "\n\n";
    //std::cout << "Current Spacecraft State - ID: " << id << "  Fuel: " << fuel << "  Alitude: " << altitude << "  Speed: " << speed << "\n\n";
  }
};

// Without these declarations the references to altitude and speed will be undefined at the linker phase.
// Test by commenting them out.
std::string Spacecraft::id;
int Spacecraft::altitude;
int Spacecraft::speed;

int main(int argc, const char * argv[]) {
    std::cout << "Class Static Test Started" << "\n\n";

    // First test:  Two different instances of Aircraft; each instance with its
    //              own attribute values.

    std::cout << "First test:  Two different instances of Aircraft" << "\n";
    std::cout << "             Each instance with its own attribute values" << "\n\n";

    Aircraft ac1;
    ac1.id = "Aircraft 1";
    ac1.altitude = 3000;
    ac1.speed = 500;

    Aircraft ac2;
    ac2.id = "Aircraft 2";
    ac2.altitude = 7000;
    ac2.speed = 700;

    ac1.printState();
    ac2.printState();

    std::cout << "Second test:  Two different instances of Spacecraft" << "\n";
    std::cout << "              Each instance assigns its own values to the attributes" << "\n";
    std::cout << "              but only the last assignment effects both." << "\n";

    Spacecraft sc1;
    sc1.id = "Spacecraft 1";    //id, altitude and speed are static so regardless of
    sc1.altitude = 3000;        // of the number of Spacecraft instances, these
    sc1.speed = 500;            // variables refer to the same space in memory.
                                // These are known as instance variables.

    Spacecraft sc2;
    sc1.id = "Spacecraft 2";
    sc2.altitude = 7000;
    sc2.speed = 700;

    sc1.printState();
    sc2.printState();

    Spacecraft::id = "Spacecraft X";    // Since there is only one instance of the variable
    Spacecraft::altitude = 1234;        // for all the struct instances, the variable can be
    Spacecraft::speed = 4321;           // refered to this way.
                                        // Writing the instance variable this way helps prevent
                                        // the situation experienced in the lines before where
                                        // sc1.altitude and sc2.altitude changed state unintentionally
                                        // because of the way it was written.

    Spacecraft::printState();           // The same is for instance functions.

    std::cout << "Class Static Test Completed" << "\n\n";

    return 0;
}
