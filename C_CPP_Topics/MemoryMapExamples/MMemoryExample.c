/*
 ============================================================================
 Name        : MMapExample.c
 Author      : Don Snyder

 Description : Demonstration of mmap usage in C

 Note		 :  Look up munmap and fsync to see if there functions are needed.

 	 	 	 	Virtual memory system makes things convenient and fast for
 	 	 	 	moving data between RAM and disk.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
	printf("\nmmap Demonstration\n\n");

	int fd;
	struct stat mystat;
	void*file_in_memory;

	fd = open("test.txt", O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(1);
	}

	if (fstat(fd, &mystat) < 0)	{
		perror("Couldn't retrieve file size");
		close(fd);
		exit(1);
	}

	printf("File size: %lld \n\n", mystat.st_size);

	file_in_memory = mmap(0, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if (file_in_memory == MAP_FAILED) {
		perror("mmap allocation failed");
		close(fd);
		exit(1);
	}

	// Change content of file...starts at the beginning and changes four bytes
	strncpy(file_in_memory, "That", 4);

	close(fd);
	return EXIT_SUCCESS;
}

