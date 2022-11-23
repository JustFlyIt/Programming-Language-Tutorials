#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <sys/sysinfo.h>

static bool s_threadFinished = false;

void ProcessorThread() {
	
	//using namespace std::chrono::chrono_literals;

	std::cout << "Started thread; id = " << std::this_thread::get_id() << "\n";
	
	while (!s_threadFinished) {
		std::cout << "Processing...id=" << std::this_thread::get_id() << "\n";
		sleep(1);
	}
}

int main() {
	std::cout << "\n\nThread Example Started...\n\n";

	int numberOfCpus = 0;

	numberOfCpus = get_nprocs();

	std::cout << "System has " << numberOfCpus << " CPUs and this many configured: " << get_nprocs_conf() << "\n\n";

	if (__cplusplus == 201703L) std::cout << "C++17\n";
	    else if (__cplusplus == 201402L) std::cout << "C++14\n";
	    else if (__cplusplus == 201103L) std::cout << "C++11\n";
	    else if (__cplusplus == 199711L) std::cout << "C++98\n";
	    else std::cout << "pre-standard C++\n";

	vector<thread> threads;

	for (int i=0; i<numberOfCpus; i++)
		threads.push_back(std::thread worker(ProcessorThread));
	
	std::cin.get();
	s_threadFinished = true;
	
	worker.join();

	std::cout << "ProcessorThread Finished \n";
	
	std::cout << "Started 'main' thread...id = " << std::this_thread::get_id() << "\n";
	

	std::cin.get();
}
