/*
 ============================================================================
 Name        : PackingTestInCProject.c
 Author      : Don Snyder
 Notes	     :  IMPORTANT - Processor is aligning to four bytes boundaries

 	 	 	 	Size of Pointers Explanation
 	 	 	 	C standard (n1256 draft)
 	 	 	 	6.2.5 Types

 	 	 	 	The size of void pointer varies system to system. If the
 	 	 	 	system is 16-bit, size of void pointer is 2 bytes. If the
 	 	 	 	system is 32-bit, size of void pointer is 4 bytes. If the
 	 	 	 	system is 64-bit, size of void pointer is 8 bytes.

 	 	 	 	Packing and alignment correction can improve performance.

 	 	 	 	A pointer to void shall have the same representation and
 	 			alignment requirements as a pointer to a character type.

 	 			Similarly, pointers to qualified or unqualified versions of
 	 			compatible types shall have the same representation and alignment
 	 			requirements. All pointers to structure types shall have the same
 	 			representation and alignment requirements as each other. All
 	 			pointers to union types shall have the same representation and
 	 			alignment requirements as each other. Pointers to other types
 	 			need not have the same representation or alignment requirements.

 Description : Packing test based of web found questions and explanations.
 
 WORK IN PROGRESS - example for s3 and s4 are not correct yet.  Adding the
 integer changed the size of the structure...why?

 The location of the int x in the struct has an effect on the memory layout.
 Each defined element in the struct will start on an alignment boundary (segment?)

 Depends on base of OS 32 vs 64 (size of chunk that can be processed at a time)
 1 word is 4 bytes in 32 bit processor
 1 word is 8 bytes in 64 bit processor

 Compiler will pad struct to max type size

 word - page - segment; issues with memory mapping

 See this link: https://www.youtube.com/watch?v=QSuBwGmFQqA for additional
 example for this code.

 Output needs notes on what is being demonstrated

 #pragma pack(1) will disable padding
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
	void *a;	// 4 bytes		   4 bytes  8 for pointer...see note in file header
	char b[2];	// 2 bytes		   2 bytes  2 for char NO PADDING!!!!!!
	int i;		// 4 bytes		   4 bytes  4 bytes for int
}__attribute__((packed));		//10 bytes TOTAL

struct s3 {
	char b1[2];	// 2 bytes 		4 bytes  2 for char and 2 for padding
	char b2[3];	// 3 bytes 		4 bytes  3 for char and 1 for padding
	char b3[4];	// 4 bytes		4 bytes  4 for char
	int x;		// 4 bytes		4 bytes  4 bytes for int
	char b4[5];	// 5 bytes		8 bytes  5 for char and 3 for padding
};								//24 bytes TOTAL

struct s4 {
	char b1[2];	// 2 bytes 		2 bytes  2 for char
	char b2[3];	// 3 bytes 		3 bytes  3 for char
	char b3[4];	// 4 bytes		4 bytes  4 for char
	int x;		// 4 bytes		4 bytes  4 bytes for int
	char b4[5];	// 5 bytes		5 bytes  5 for char
}__attribute__((packed));		//18 bytes TOTAL

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
	printf("Size of s1 structure (not packed) in bytes: %lu\n\n", sizeof(test1));

	printf("& of *a: %p\n", &(test1.a));
	printf("& of  b: %p\n", &(test1.b));
	printf("& of  i: %p\n", &(test1.i));

	struct s2 test2;
	printf("\n\nSize of s2 structure (packed) in bytes: %lu\n\n", sizeof(test2));

	printf("& of *a: %p\n", &(test2.a));
	printf("& of  b: %p\n", &(test2.b));
	printf("& of  i: %p\n", &(test2.i));

	struct s3 test2b;
	printf("\n\nSize of test2b structure (not packed) in bytes: %lu\n\n", sizeof(test2b));

	printf("Size of char b1[2] in bytes: %lu\n\n", sizeof(test2b.b1));
	printf("Size of char b2[3] in bytes: %lu\n\n", sizeof(test2b.b2));
	printf("Size of char b3[4] in bytes: %lu\n\n", sizeof(test2b.b3));
	printf("Size of char b4[5] in bytes: %lu\n\n", sizeof(test2b.b4));

	struct s4 test2c;
	printf("\n\nSize of test2c structure (packed) in bytes: %lu\n\n", sizeof(test2c));

	printf("Size of char b1[2] in bytes: %lu\n\n", sizeof(test2c.b1));
	printf("Size of char b2[3] in bytes: %lu\n\n", sizeof(test2c.b2));
	printf("Size of char b3[4] in bytes: %lu\n\n", sizeof(test2c.b3));
	printf("Size of char b4[5] in bytes: %lu\n\n", sizeof(test2c.b4));

	char *test3;
	printf("\n\nSize of char* in bytes: %lu\n\n", sizeof(test3));

	void *test4;
	printf("Size of void* in bytes: %lu\n\n", sizeof(test4));

	int test5;
	printf("Size of int in bytes: %lu\n\n", sizeof(test5));

	char test6[2];
	printf("Size of char [2] in bytes: %lu\n\n", sizeof(test6));

	char test7[4];
	printf("Size of char [4] in bytes: %lu\n\n", sizeof(test7));

	char test8[5];
	printf("Size of char [5] in bytes: %lu\n\n", sizeof(test8));

	struct testFoundation1 test9;
	printf("Size of testFoundation1 structure: %lu\n\n", sizeof(test9));

	struct testFoundation2 test10;
	printf("Size of testFoundation2 structure: %lu\n\n", sizeof(test10));

	struct testFoundation3 test11;
	printf("Size of testFoundation3 structure: %lu\n\n", sizeof(test11));

	return EXIT_SUCCESS;
}
