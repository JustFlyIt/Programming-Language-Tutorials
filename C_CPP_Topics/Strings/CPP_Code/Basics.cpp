#include <iostream>
#include <string.h>
#include <stdio.h>

// Const reference; no copy made and string is read only
void lookAtString(const std::string& stringInput) {
  std::cout << "stringInput: " << stringInput << std::endl;
}

int main() {

  const char* name = "Snyder";

  char name3[6] = {'S', 'n', 'y', 'd', 'e', 'r'};  // No null end
  char name2[] = {'S', 'n', 'y', 'd', 'e', 'r'};   // Includes null end

  std::cout << "name: " << name << std::endl;

  std::cout << "lenght of name: " << strlen(name) << std::endl;

  std::cout << "name3 (no null terminator...may have bad chars): " << name3 << std::endl;

  name2[2] = 'x';

  std::cout << "name2: " << name2 << std::endl;

  std::string name4 = "Snyder";

  std::cout << "name4: " << name4 << std::endl;
  name4 += ", Don";
  std::cout << "name4 (appended +=): " << name4 << std::endl;
  name4.append(" R ");
  std::cout << "name4 (.appended): " << name4 << std::endl;


}
