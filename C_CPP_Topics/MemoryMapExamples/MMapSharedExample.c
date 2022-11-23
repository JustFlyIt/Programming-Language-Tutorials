/*
 ============================================================================
 Name        : MMapSharedExample.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Demonstration of mmap usage in C, Ansi-style

 Note		 :  Look up munmap and fsync to see if there functions are needed.

 	 	 	 	Virtual memory system makes things convenient and fast for
 	 	 	 	moving data between RAM and disk.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define PAGESIZE 2048

int v = 5;

int main(void) {
	puts("mmap Shared Memory Demonstration\n\n");

	uint8_t *shared_memory = mmap(NULL, PAGESIZE,
								  PROT_READ | PROT_WRITE,
								  MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*shared_memory = 34;

	if (fork() == 0) {
		v = 80;
	} else {
		wait(NULL);
	}

	printf("Not Shared: %i\n \n", v);
	printf("Shared: %i\n \n", *shared_memory);

	return EXIT_SUCCESS;
}
