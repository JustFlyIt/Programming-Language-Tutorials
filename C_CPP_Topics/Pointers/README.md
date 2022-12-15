# Pointer

Compile:  Compile example with: g++ -std=c++11 xxxx.cpp

Key concept:  a pointer is nothing more than an integer containing an address of memory.  TYPES ARE NOT REQUIRED

A POINTER IS AN INTEGER VARIABLE THAT JUST POINTS TO A LOCATION OF MEMORY.

When a type is provided all that is being indicated is that the the memory at the address that the pointer contains is of that type.

Allocated memory is done from the heap.

*ptr - dereferencing a pointer - accessing the data.
&num - address of operator - return that address of the variable or item.

void* - a typeless pointer; types are for convenience but do not change what a pointer is.

If running on a 32bit machine, pointers are four bytes - 32bits, 8bits/byte, 4 bytes.
If running on a 64bit machine, pointers are eight bytes - 64bits, 8 bits/byte, 8 bytes.

Types are required to tell the compiler how much to read or write.

The source code contains several examples of how memory pointers are declared and used.  Pay particular attention to the idea that a pointer contains a value...that value is a location of memory.

A pointer to a pointer, **, denotes a pointer that points to a pointer.

0 to a pointer represents "null".  This can also be represented as NULL or nullptr (introduced in C++ 11)
