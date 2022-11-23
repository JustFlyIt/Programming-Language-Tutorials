/*
	File:  CPPThreads.cpp

	Author: Don Snyder

	Function: CPP program to demonstrate multithreading using three different callables.

		  The primary demonstration is the calling a std::thread operation...providing
		  three different examples on how to call the std::thread.

		  NOTE THE LAMBDA EXPRESSION USE AS THE THIRD EXAMPLE FOR STARTING A std::thread

	Credit:  The foundation of this example is found here -
			https://www.geeksforgeeks.org/multithreading-in-cpp/
      https://www.youtube.com/watch?v=wXBcwHwIt_I&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=63&t=0s
*/

#include <iostream>
#include <unistd.h>
#include <thread>

// C/C++ function
void foo(int Z) {
  std::thread::id  thisThreadId = std::this_thread::get_id();

	for (int i = 0; i < Z; i++) {
		std::cout << "std::thread Function, id = "  << thisThreadId << " using function pointer as callable" << std::endl;

    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}

// A callable object as defined within a C++ class
class threadObj {
public:
	void operator()(int x)
	{
    std::thread::id  thisThreadId = std::this_thread::get_id();

		for (int i = 0; i < x; i++)
			std::cout << "std::thread Callable Object, id = "  << thisThreadId << " using function object as callable" << std::endl;

      std::cout.flush();

      std::this_thread::sleep_for(std::chrono::seconds(1));
	}
};

int main() {
	std::cout << "Threads 1 and 2 and 3 operating independently" << std::endl;

	// This std::thread is launched by using function pointer as callable
	std::thread th1(foo, 3);

	// This std::thread is launched by using function object as callable
	std::thread th2(threadObj(), 3);

	// Define a Lambda Expression
	auto f = [](int x) {
    std::thread::id  thisThreadId = std::this_thread::get_id();

		for (int i = 0; i < x; i++)
			std::cout << "std::thread Lamda, id = "  << thisThreadId << " using lambda expression as callable" << std::endl;

      std::cout.flush();

      std::this_thread::sleep_for(std::chrono::seconds(4));
	};

	// This std::thread is launched by using lamda expression as callable
	std::thread th3(f, 3);

	// Wait for the threads to finish: t1, t2, t3
	th1.join();
	th2.join();
	th3.join();

	return 0;
}
