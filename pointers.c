// Introduction to pointers in C

// Pointers - variables that store address of another variable

int a;  		// variable a of type int 

int *p;			// p ins a pointer variable that points to an integer
				// it can store the address of an integer

p = &a;			// storing the address of a in p  // & - addres/pointer 

printf("%d", p);   // will print the address of a 

/////////////////////////////////////////////////////////////////////////////////////////////////
									//	WORKING WITH POINTERS
/////////////////////////////////////////////////////////////////////////////////////////////////

int a; 		//integer 
int *p;  	// pointer to integer 
char c; 	//character 
char *po 	// pointer to charcter 
double d 	// double 
double *p1 	// pointer to double 

#include <stdio.h>

int main(){
	int a;
	int *p;
	a = 10;
	p = &a; 	// &a = address of a
	printf("%d\n", p);	// will print the address of a	
	printf("%d\n", *p); // will print the value of a
	printf("%d\n", &a); // will print the address of a

	*p = 12; // dereferencing
}

#include <stdio.h>

int main(){
	int a = 10;
	int *p;
	p = &a;
	// pointer arethmetic
	printf("Address p is %d\n", p);    // 2000
	printf("Size of integer is %d bytes\n", sizeof(int));  // 4 bytes 
	printf("Addres of integer is %d\n", p+1);  // 2004
	printf("Value at address p is %d\n ", *p);  // 10   (this is the value of a)
	printf("value at address p+1 is %d\n" *(p+1));		// garbage
}


/////////////////////////////////////////////////////////////////////////////////////////////////
						//POINTER TYPES, VOID POINTER, POINTER ARITHMETIC
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int(){
	int a = 1025;
	int *p;
	p = &a;
	printf("size of integer is %d bytes\n"), sizeof(int);
	printf("Address = %d, value = %d\n", p, p*);
	printf("Address = %d, value = %d\n", p+1, *(p+1));

	char *p0;
	p0 = (char*)p; // typecasting
	printf("size of char is %d bytes\n", sizeof(char));
	printf("Address = %d, value = %d\n", p0, *p0);
	printf("Address = %d, value = %d\n", p0+1, *(p0+1));
	// 1025 = 00000000 000000000 000000100 000000001
}

#include <stdio.h>

int(){
	int a = 1025;
	int *p;
	p = &s;
	printf("size of integer is %d bytes\n"), sizeof(int);
	printf("Address = %d, value = %d\n", p, p*);
	printf("Address = %d, value = %d\n", p+1, *(p+1));
	
	//void pointer - Generic pointer
	void *p0;
	p0 = p;
	printf("Address = %d", p0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
									//POINTER TO POINTER
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
int main(){
	int x = 5;
	int* p = &x;	// asigning p as a pointer to x
	*p = 6;			// derefrencing x = 6
	int** q = &p;	// asigning q as a pointer to p
	int*** r = &q;	// asigning r as a pointer to q

	printf("%d\n", p);   	// 225
	printf("%d\n", *p);   	// 6
	printf("%d\n", *q);   	// 225			// 225 is a made up address of x
	printf("%d\n", **q);   	// 6
	printf("%d\n", **r);   	// 225
	printf("%d\n", ***r);   // 6

	***r = 10;			//changing variable x by referencing to ***r
	printf("x = %d\n", x);		// 10

	**q = *p +2;
	printf("x = %d\n", x);   // 12
}

/////////////////////////////////////////////////////////////////////////////////////////////////
						//POINTERS AS FUNCTION ARGUMENTS - CALL BY REFERENCE
/////////////////////////////////////////////////////////////////////////////////////////////////
//         application's memory
// (Heap, Stack, Static/Global, Code(text))

// mostly will be talking about Stack

#include <stdio.h>

void Increment(int a){
	a = a + 1;
}
int main(){
	int a;			// This function will not increment because addresses are different
	a = 10;
	Increment(a);
	printf("a = %d", a);
}
// On the other hand: call by reference

#include <stdio.h>
void Increment(int *p){
	*p = (*p) + 1;
}
int main(){		// In this you are pointing the address to the function, so it will
	int a;     	// so it increment a expected 
	a = 10;
	Increment(&a);
	printf("a = %d", a);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
									//POINTERS AND ARRAYS
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
int main(){
	int A[] = {2, 4, 5, 8, 1};
	printf("%d\n", A);			// Print the first address of the array
	printf("%d\n", &A[0]);		// Print the first address of the array
	printf("%d\n", A[0]);		// Print the first variable of the array
	printf("%d\n", *A);			// print the first variable of the array

	int *p = A;
	A++; // invalid
	p++; // valid	

	int i;
	for(i = 0; i < 5; i++){
		printf("Address = %d\n", &A[i]);
		printf("Address = %d\n", A+i);
		printf("Value = %d\n", A[i]);
		printf("Value = %d\n", *(A+i));
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
								// ARRAYS AS FUNCTION ARGUMENTS
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int SumOfElements(int A[], int size){   // (int A[]) can also be written as (int* A)
	int i, sum = 0;
	int size2 = sizeof(A)/sizeof(A[0]); // here the size of A is equal to 1 because A is a pointer
	for(i = 0; i < size; i++){			// as apposed to A in the main function
		sum+= A[i];   	// A[i] is *(A+i)
	}
	return sum;
}
int main(){
	int A[] = {1, 2, 3, 4, 5};
	int size = sizeof(A)/sizeof(A[0]); 	// here the size will be dsisplayed correctly
	int total = SumOfElements(A, size)
	return 0;
}

// double the array by two
#include <stdio.h>

void Double(int* A, int size){  	// int* A or in A[]   ... are the same 
	int i, sum = 0;
	for(i = 0; i < size; i++){
		A[i] = 2*A[i];
	}
} 	

int main(){
	int A[] = {1, 2, 3, 4, 5};
	int size = sizeof(A)/sizeof(A[0]);
	int i; 
	Double(A, size);
	for(i = 0; i < size; i++){
		printf("%d", A[i]);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
								// CHARACTER ARRAYS AND POINTRS
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
void print(char* C){
	int i = 0;
	while(*(C+i) != '\0'){			// iterate every location until you reach '\0'
		printf("%c", C[i]);			// print every charactr
		i++;						// !! dont forget that *(C+i) = C[i]
	printf("\n");
}
int main(){
	char C[20] = "Hello";
	print(C);
}

#include <stdio.h>
void print(char* C){	// You can alsa make it a const ( const char* C  )
	while(*C != '\0'){			// This will also work perfectly because 
		printf("%c", *C);		// *C is being the character while	
		C++;					// C is the addres of the character 	
	}
	printf("\n");
}
int main(){
	char C[20] = "Hello";
	//char *C = "Hello"; 		// string gets stored as compile time constant and it can not 
	print(C);					// be modified
}
// the difference is: the first method is iterating the position of the character by 1, while 
// the second method is iterating the address of the character by 1 


/////////////////////////////////////////////////////////////////////////////////////////////////
						// POINTERS AND MULTI-DIMENTIONAL ARRAYS
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
int main(){

	int A[2][3] = {{3, 5, 8},{9, 2, 1}};
	int (*p)[3] = A;

	printf("The address of A[0] = %d\n", A);					// or &A[0] 
	printf("The address of A[1] = %d\n\n", A+1);				// or &A[1]

	printf("The address of A[0][0] = %d\n", *A);				// or &A[0][0] or A[0]
	printf("The address of A[0][1] = %d\n", *A+1);				// or &A[0][1] or A[0]+1
	printf("The address of A[0][2] = %d\n\n", *A+2);			// or &A[0][2] or A[0]+2

	printf("The address of A[1][0] = %d\n", *(A+1));			// or &A[1][0] or A[1]
	printf("The address of A[1][1] = %d\n", *(A+1)+1);			// or &A[1][1] or A[1]+1
	printf("The address of A[1][2] = %d\n\n", *(A+1)+2);		// or &A[1][2] or A[1]+2

	printf("The value of A[0][0] = %d\n", *(*A) );				// or A[0][0]
	printf("The value of A[0][1] = %d\n", *(*A+1) );			// or A[0][1]
	printf("The value of A[0][2] = %d\n", *(*A+2) );			// or A[0][2]
	
	printf("The value of A[1][0] = %d\n", *(*(A+1)) );			// or A[1][0]
	printf("The value of A[1][1] = %d\n", *(*(A+1)+1) );		// or A[1][1]
	printf("The value of A[1][2] = %d\n", *(*(A+1)+2) );		// or A[1][2]
}

//   A[i][j] = *(A[i]+j) = *(*(A+i)+j)
//   &A[i][j] = A[i]+j = *(A+i)+j

#include<stdio.h>

void Func(int B[][2][2]){		// or (B*)[2][2]

}
int main(){
	int B[3][2][2] = {
		{{2,5}, {7, 9}},
		{{3, 4}, {6, 1}},
		{{0, 8}, {11, 12}}
	};
	(*p)[2][2] = B
	return 0;
}
//   A[i][j][k] = *(A[i][j]+k) = *(*(A[i]+j)+k) = *(*(*(A+i)+j)+k)

/////////////////////////////////////////////////////////////////////////////////////////////////
								// POINTERS AND DYNAMIC MEMORY 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main(){
	int a; // goes on stack
	int *p;
	p = (int*)malloc(sizeof(int));   // creates a dynamic pointer with space int the heap
	*p = 10;					// need to dereference to asign a value 
	free(p);			// it is important to free space from the heap when it is no need

	p = (int*)malloc(10*sizeof(int));   	// asigning new space in the heap 10 int spaces 
	*p = 20;			//  value of address p which is located in the heap section
	*(p+1) = 24; 		// next value in the list 
	*(p+2) = 43; 		// next value and so on....
}

// IMPOTATNT FUNCTIONS FOR DYNAMIC MEMORY

Alocating block of memory:
// * malloc		-	 void* malloc(size_t size)
					// size_t - unsigned integer
			// returns a void pointer that gives the address of the firs bite tha it alocates
			// you can not derefference a void pointer
			// to derreference need to typecast:
					 int*p = (int*)malloc(3*sizeof(int));

// * calloc		- 	 void* calloc(size_t num, size_t size) 
					 int *p = (int*)calloc (3, sizeof(int));
			// the difference is that calloc sets all byte positions with value 0,
			// while malloc sets garbage 

// * realloc	- 	 void* realloc(void* Str, size_t size)

Dealocating block of memory:
// * free


#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int *A = (int*)malloc(n*sizeof(int)); 	// dynamically allocated array
	for(int i = 0; i < n; i++){
		A[i] = i + 1;
	}
	int *B = (int*)realloc(A, 2*n*sizeof(int));  	// resizing the array
	int *C = (int*)realloc(A, 0);   // equivalent to free(A)
	int *D = (int*)realloc(NULL, n*sizeof(int));   // equivalent to malloc

	printf("Prev block address = %d, new address = %d\n", A, B);
// if both addresses are the same then the previous block was extended,
// else a new block was created, while the previous block was removed.
	for(int i = 0; i < 2*n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
								// POINTERS AS FUNCTION RETURNS 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
void PrintHelloWorld(){
	printf("Hello World\n");
}
int* Add(int* a, int* b){		// called function
	int* c = (int*)malloc(sizeof(int));
	*c = (*a) + (*b);
	return c;	// returning pointer to integer
}

int main(){			// calling function
	int a = 2, b = 4;
	int* ptr = Add(&a, &b);		// a and b are integers local to Main
	PrintHelloWorld();
	printf("sum = %d\n", *ptr);
}
// in this case it is important to use malloc because if we don't, the pointer variable c will be
// store in the stack memory section. After the Add method will be deleted from the stack, in the
// main method the address of the pointer will still be there. so when the hello world is being 
// exicuted it might overright the pointers value so the value might turn out garbage.


/////////////////////////////////////////////////////////////////////////////////////////////////
								// FUNCTION POINTERS 
/////////////////////////////////////////////////////////////////////////////////////////////////

// testing buffer


#include <stdio.h>
int Add(int a, int b){
	return a + b;
}
void PrintHello(char *name){
	printf("Hello %s\n", name);
}
int main(){
	int c;
	int (*p)(int, int);			// the syntax for pointing to a function
	p = &Add; // p = Add     (two statements are the same)
	c = (*p)(2, 3); // p(2, 3)	// de-referencing and exicuting the function 
								// declaring a function pointer
	printf("%d\n", c);
	
	void ptr(char*);
	PrintHello("Tom");	
}
/////////////////////////////////////////////////////////////////////////////////////////////////
								// FUNCTION POINTERS AND CALLBACKS 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>


int compare(int a, int b){					// sorting arrays using pointer functions 
	if(a > b){
		return 1;
	}else{
		return -1;
	}
}
int absolute_compare(int a, int b){		// you may use one of two functions in the main function
	if(abs(a) > abs(b)){
		return 1;
	}else{
		return -1;
	}
}
void BubbleSort(int *A, int n, int (*compare)(int, int)){
	int i, j, temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-i-1; j++){
			if(compare(A[j], A[j+1]) > 0){	// comparing the position of variables
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}
int main(){
	int i, A[] = {3, -2, 1, -5, 6, 4};
	BubbleSort(A, 6, absolute_compare);	
	for(i = 0; i < 6; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
	int A = *((int*)a);  // typecasting to int* and getting the value 
	int B = *((int*)b);
	return A-B;		// abs(B) - abs(A);
}
int main(){
	int i, A[] = {-31, 22, -1, 50, -6, 4};
	qsort(A, 6, sizeof(int), compare); 		// comparing using qsort 
	for(i = 0; i < 6; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
