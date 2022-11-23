//============================================================================
// Name        : StopEndUseLinux.cpp
// Author      : Don Snyder
// Version     :
// Copyright   : Northrop Grumman
// Description : Stop using "endl".  It includes a performance busting
//               flush() operation everytime.
//               std::endl = '\n' << flush  // Is flush really needed?
//
//             Work in progress.
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>

void write_file_output(std::ostream &os) {
   os << "do something\n";       // change to endl for performance difference
   os << "do something  else\n";  // change to endl for performance difference
}

void write_file_output(std::stringstream &ss) {
   ss << "do something\n";       // change to endl for performance difference
   ss << "do something else\n";  // change to endl for performance difference
}

void writeln(std::ostream &os, const std::string &str) {
   //os << str << '\n';            //faster
   os << str << std::endl;         //slower
}

int main() {
   std::ofstream outfile("output.txt", std::ios_base::trunc);

   // Example 1
   for (int i=0; i < 1000000; ++i) {
      writeln(outfile, "Hello World");
   }

   outfile << std::flush;

   // Example 2: 10x slower
//   write_file_output(outfile);

   // Example 3: 10x faster
/*
   std::stringstream ss;
   write_file_output(ss);
   outfile << ss.str();

*/
   return 0;
}
