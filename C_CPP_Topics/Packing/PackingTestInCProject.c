/*
 ============================================================================
 Name        : PackingTestInCProject.c
 Author      : Don Snyder
 Notes	     :  IMPORTANT - Processor is aligning to four bytes boundaries

 	 	 	 	Size of Pointers Explanation
 	 	 	 	C standard (n1256 draft)
 	 	 	 	6.2.5 Types

 	 	 	 	27 A pointer to void shall have the same representation and
 	 			alignment requirements as a pointer to a character type.39)
 	 			Similarly, pointers to qualified or unqualified versions of
 	 			compatible types shall have the same representation and alignment
 	 			requirements. All pointers to structure types shall have the same
 	 			representation and alignment requirements as each other. All
 	 			pointers to union types shall have the same representation and
 	 			alignment requirements as each other. Pointers to other types
 	 			need not have the same representation or alignment requirements.

 Description : Packing test based of web found questions and explanations.
 
 WORK IN PROGRESS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct s1 {
	void *a;	// 8 bytes		   8 bytes  8 for pointer...see note in file header
	char b[2];	// 2 bytes		   4 bytes  2 for char and 2 for padding
	int i;		// 4 bytes		   4 bytes  4 bytes for int
};								//12 bytes TOTAL

struct s2 {
	void *a;	// 8 bytes		   8 bytes  8 for pointer...see note in file header
	char b[2];	// 2 bytes		   4 bytes  2 for char NO PADDING!!!!!!
	int i;		// 4 bytes		   4 bytes  4 bytes for int
}__attribute__((packed));		//10 bytes TOTAL

struct testFoundation1
{
	unsigned char test1 : 2;	// Each char is 8 bits
	unsigned char test2 : 2;	// The first byte of structure holds test1, 2 and 3
	unsigned char test3 : 4;
	unsigned char test4 : 8;	// The second byte of structure holds test4
};								// 2 bytes TOTAL

struct testFoundation2
{
	unsigned char test1 :2;		// 2 bits in the first byte
	unsigned char test2 :2;     // 2 bits in the first byte
	unsigned int test3 : 4;		// 4 bits in the first byte...if size goes greater than 4
								// than 4 then 2 bytes will be needed to store the structure
								// See following testFoundation3 example
} __attribute__((packed));		// 8 bits/1 byte TOTAL because of the __attribute__((packed))

struct testFoundation3
{
	unsigned char test1 :2;		// 2 bits in the first byte
	unsigned char test2 :2;     // 2 bits in the first byte
	unsigned int test3 : 5;		// 5 bits exceeds the first byte...a second byte is needed
} __attribute__((packed));		// 9 bits/2 bytes TOTAL because of the __attribute__((packed))


int main(void) {
	puts("Packing Test In C Project Started\n\n");

	struct s1 test1;
	printf("Size of s1 structure in bytes: %lu\n\n", sizeof(test1));

	struct s2 test2;
	printf("Size of s2 structure in bytes: %lu\n\n", sizeof(test2));

	char *test3;
	printf("Size of char* in bytes: %lu\n\n", sizeof(test3));

	void *test4;
	printf("Size of void* in bytes: %lu\n\n", sizeof(test4));

	int test5;
	printf("Size of int in bytes: %lu\n\n", sizeof(test5));

	char test6[2];
	printf("Size of char [2] in bytes: %lu\n\n", sizeof(test6));

	struct testFoundation1 test7;
	printf("Size of testFoundation1: %lu\n\n", sizeof(test7));

	struct testFoundation2 test8;
	printf("Size of testFoundation2: %lu\n\n", sizeof(test8));

	struct testFoundation3 test9;
	printf("Size of testFoundation3: %lu\n\n", sizeof(test9));

	return EXIT_SUCCESS;
}
