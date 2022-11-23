//============================================================================
// Name        : VectorTest.cpp
// Author      : DRS
// Version     :
// Copyright   : Free to the World
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

extern "C" {
	#include "elapsedTime.h"
}

unsigned int vector_add_of_n(long* ptr, long items, double* totalTimeValue) {
    struct timespec now;
	unsigned int result=0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &now);

    for (long i=0; i<items; i+=1) {
    	    //cout << "i: " << i << "   result: " << result << "\n";
        result+=ptr[i];
    }

    double timeValue = elapsedTimeSince(&now);

    //cout << "\n\nTime for vector add: " << timeValue << " (msec)\n";

    *totalTimeValue+=timeValue;

    return result;
}

unsigned int vector_add_arrays(long* ptr, long* ptr2, long* sum, long items, double* totalTimeValue) {
    struct timespec now;
	unsigned int result=0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &now);

    for (long i=0; i<items; i+=1) {
    	    //cout << "i: " << i << "   result: " << result << "\n";
        result+=ptr[i];
    }

    double timeValue = elapsedTimeSince(&now);

    //cout << "\n\nTime for vector add: " << timeValue << " (msec)\n";

    *totalTimeValue+=timeValue;

    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << "Vector Test\n";
    std::cout << std::setprecision(20) << std::fixed;

    unsigned int value = 0;
    long numberOfTestValues = 64000;
    double totalTimeValue = 0;
    int numberOfTimeIterations = 100000;

    long testValues1[numberOfTestValues];
    long testValues2[numberOfTestValues];
    long sum[numberOfTestValues];

    for (long i=0; i< numberOfTestValues; i++) {
    	   testValues1[i] = i+1;
    	   testValues2[i] = i;
    }

    for (int i=0; i<numberOfTimeIterations; i++) {
		//value = vector_add_of_n( testValues1, numberOfTestValues, &totalTimeValue);
		value = vector_add_arrays( testValues1, testValues2, sum, numberOfTestValues, &totalTimeValue);
    }

    std::cout << "\n";

    std::cout << "number of values: " << numberOfTestValues << "\n";
    std::cout << "sum of values: " << value << "\n";
    std::cout << "totalTimeValue: " << totalTimeValue << " (msec)\n";
    std::cout << "number of time iterations: " << numberOfTimeIterations << "\n";

    std::cout << "average timeValue: " << totalTimeValue/numberOfTimeIterations << " (msec) \n";

    return 0;
}
