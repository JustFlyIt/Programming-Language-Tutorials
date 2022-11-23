//============================================================================
// Name        : ImplicitExplicitExample.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Demonstrate the implicit conversion and the use of the
//               explicit keyword to manage it.
//
//============================================================================
#include <iostream>

class Entity {
private:
  std::string m_Name;
  int m_Age;
public:
  Entity(const std::string& name)
    : m_Name(name), m_Age(0) {}
  Entity(int age)
    : m_Name("Unknown"), m_Age(age) {}
};

class Explicit_Entity {
private:
  std::string m_Name;
  int m_Age;
public:
  explicit Explicit_Entity(const std::string& name)
    : m_Name(name), m_Age(0) {}
  explicit Explicit_Entity(int age)
    : m_Name("Unknown"), m_Age(age) {}
};


int main(int argc, const char * argv[]) {
    std::cout << "Implicit Convestion and Explicit Keyword Demonstration Started" << "\n\n";

    // Constructors and implicit conversion
    // Typical constructor usage
    Entity a0("Snyder");
    Entity b0(60);

    Entity a1 = Entity("Snyder2");
    Entity b1 = Entity(61);

    // Implicit conversion with constructor
    // The compiler implicitly converts the right hand value to an entity to provide
    // to the constructor.
    Entity a2 = std::string("Snyder3");  //Will not compile without the string cast;
                                         //String cast is needed to reduce the
                                         //number of implicit conversions to one.
                                         //One is all that C++ allows.
    Entity b2 = 62;

    // Personal Opinion:  Implicit conversion could be as syntaxic nightmare.

    // Use of the explicit keyword...no longer able to do the below.
    // explicit requires the Constructors to be explicitly called
    // The below do not compile.
    Explicit_Entity ea2 = std::string("Snyder3");
    Explicit_Entity eb2 = 62;

    std::cout << "\nImplicit Convestion and Explicit Keyword Demonstration Completed" << "\n\n";

    return 0;
}
