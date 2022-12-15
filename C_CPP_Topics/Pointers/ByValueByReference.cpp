#include <iostream>
using namespace std;

//----------------------------------------------------------------------------
void pass_by_value(int* p)  // Pass by value; no change
{
    //Allocate memory for int and store the address in p
    p = new int(44);  // change will be discarded once function returns

    cout << "In pass_by_value -  Value of p - " << *p << "\n";

    delete p ;

}

void pass_by_reference(int*& p)  // Pass by reference; change
{
    p = new int(55);  // change will persist when function returns

    cout << "In pass_by_reference - Value of p - " << *p << "\n";

    // Deleting the pointer would result the actual passed parameter dangling
}

//----------------------------------------------------------------------------
// First is a reference to a pointer, second is a reference to a pointer to a pointer
void foo(int*& x, int**& y) {
    // modifying x or y here will modify a or b in main
}

//----------------------------------------------------------------------------

void foo2(int *ptr)
{
    ptr = new int(50);    // Modifying the pointer to point to a different location
    cout << "In foo:\t" << *ptr << "\n";
    delete ptr ;
}

void bar(int *& ptr)
{
    ptr = new int(80);    // Modifying the pointer to point to a different location
    cout << "In bar:\t" << *ptr << "\n";
    // Deleting the pointer will result the actual passed parameter dangling
}


int main()
{
    int* p1 = NULL;
    int* p2 = NULL;

    cout << "p1 - " << *p1 << "   p2 - " << *p2 << "\n";
    pass_by_value(p1); //p1 will still be NULL after this call
    pass_by_reference(p2); //p2 's value is changed to point to the newly allocate memory

    //----------------------------------------------------------------------------
    int val = 42;
    int *a  = &val;
    int **b = &a;

    foo(a, b);
    //----------------------------------------------------------------------------

    int temp = 100 ;
    int *p = &temp ;

    cout << "Before foo:\t" << *p << "\n";
    foo2(p) ;
    cout << "After foo:\t" << *p << "\n";

    cout << "Before bar:\t" << *p << "\n";
    bar(p) ;
    cout << "After bar:\t" << *p << "\n";

    delete p;

    return 0;
}
