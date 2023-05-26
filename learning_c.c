/*************************************************************************************************
										LEARNING C
*************************************************************************************************/

#include <stdio.h>

int main(){
	printf("Hello world!\n");
	return 0;
}

/* 
To run the code: open a terminal and go to the directory where the c file is located.
then enter the code for the compiler:      
										gcc test.c -o test 
first enter the file name, then enter compiler file name. to exicute enter:   
										./test
*/
*************************************************************************************************
										VARIABLES
*************************************************************************************************

int x;			// decloration
x = 123;		// initialization
int y = 321;	// decloration and initialization

*************************************************************************************************
										DATATYPES
*************************************************************************************************
int age = 21;			// integer
float gpa = 2.05;		// floating point
char grade = 'C';		// single character 
char name[] = "Mike";	// array of characters (string)

printf("Hello %s\n", name);
printf("You are %d years old\n", age);
printf("Your avarage grade is %c\n", grade);
printf("Your gpa is %f\n", gpa);

float c = 3.141592;								// 4 bytes (32 bits of percision) 6-7 digits %f
double d = 3.141592653589793;					// 8 bytes (64 bits of percision) 15-16 digits %lf
char f = 127;									// 1 byte (-128 to +127) %d or %c
unsigned char g = 256;							// 1 byte (0 to 255) %d or %c
short h = 32 767;								// 2 bytes (-32 768 to +32 767) %d
unsigned short i = 65 535;						// 2 bytes (0 to 65 535) %d
int j = 2 147 483 647;							// %d
unsigned int k = 4 294 957 295;					// %u
long long int l = 9 quintillion 
unsigned long long int m = 18 quintillion 


*************************************************************************************************
										FORMAT SPECIFIERS 
*************************************************************************************************
%c = character 
%s = string 
%f = float
%lf = long float (double)
%d = intiger 

			%.1 = decimal percision
			%1 = minimal field width 
			%-5 = left align
			
// When dividing divid by float and the answer should also be a float 

*************************************************************************************************
										INPUTS  
*************************************************************************************************
#include <stdio.h>
#include <sring.h>

int main(){
	char name[25];
	int age;

	printf("What's your name?");
	//scanf("%s", &name);
	fgets (name, 25, stdin);
	name[strlen(name)-1] = '\0';

	printf("How old are you?");
	scanf("%d", &age);
	printf("Hello %s, how are you?", name);
	printf("You are %d years old", &age);

	return 0;
}

*************************************************************************************************
										MATH FUNCTIONS
*************************************************************************************************

#include <stdio.h>
#include <math.h>

int main(){

	double a = sqrt(9);
	double b = pow(2,4);
	double c = round(3.14);
	double d = ceil(3.14);
	double e = floor(3.14);
	double f = fabs(3.14);
	double g = log(3);
	double h = sin(45);
	double i = cos(45);
	double j = tan(45);

	printf("\n%.2lf", j);

	return 0;
}

*************************************************************************************************
												IF	
*************************************************************************************************

#include <stdio.h>

int main(){
	if(x == 0){
		printf("X is equal to 0");
	}else if(x <= 5){
		printf("The number is between 0 and 5");	
	}else{
		printf("The number is more than 5");	
	}
}

**********************************************************
#include <stdio.h>
#include <ctype.h>

int main(){
	char unit;
	float temp;

	printf("is the temperature in (F) or (C) ?: ");
	scanf("%c", &unit);

	unit = toupper(unit);
	
	if(unit = 'C'){
		printf("Enter the temperature in Celcius: ");
		scanf("%f", &temp);
		temp = (temp * 9 / 5) + 32;
		printf("The temperature in Ferenhiet is: %.1f", temp);
	}else if(unit == 'F'){
		printf("Enter the temperature in Ferenhiet: ");
		scanf("%f", &temp);
		temp = ((temp - 32) * 5) / 9;
		printf("The temperature in Celcius is: %.1f", temp);
	}else{
		printf("%c is not valid", unit);
	}
	return 0;
}

// if you have a lot of else if statements, use the SWITCH

*************************************************************************************************
												SWITCH
*************************************************************************************************

#include <stdio.h>

int main(){
	switch(grade){
		case 'A':
			printf("You got an A");
			break;
		case 'B':
			printf("You got a B");
			break;
		case 'C':
			printf("You got a C");
			break;
		case 'D'
			printf("You got a D");
			break;
		case 'E':
			printf("You got an E");
			break;
		case 'F':
			printf("You got a F");
			break;
	}
	return 0
}


*************************************************************************************************
										ARGUMENTS AND PARAMETERS
*************************************************************************************************

#include <stdio.h>

void birthday(char x[], int y){
	printf("Happy birthday dear %s!", x);
	printf("You are %d years old!", y);
}

int main(){
	char name[] = "Bro";
	int age = 21; 
	birthday(name, age);
	return 0;
}

*****************************************************

#include <stdio.h>

double square(double x){
	return x * x;
}

int main(){
	double x = square(3.14);
	printf("%lf", x);
	return 0;
}

*************************************************************************************************
										TERNERY OPERATOR	
*************************************************************************************************

#include <stdio.h>

int findMax(int x, int y){
	return (x > y) ? x : y;
}

int main(){
	int max = findMax(3, 4);
	printf("%d", max);
	return 0;
}
*************************************************************************************************
											FUNCTION PROTOTYPE	
*************************************************************************************************

#include <stdio.h>

void hello(char[], int);

int main(){
	char name[] = "Bro";
	int age = 21;
	hello(name, age);
	return 0;
}

void hello(char name[], int age){
	printf("Hello %s", name);
	printf("You are %d years old", age);
}

*************************************************************************************************
										STRINGS
*************************************************************************************************

#include <stdio.h>
#include <sring.h>

int main(){
	char string1[] = "Bro";
	char string2[] = "Code";

	strlwr(string1); 					// converts a string to lowercase
	strupr(string1); 					// converts a string to uppercase
	strcat(string1, string2);  			// appends string2 to end of string1
	strncat(tring1, string2, 1);		// appends n character from string1 to string2
	strcpy(string1, string2); 			// copy string2 to string1
	strcpy(string1, string2, 4);		// copy n characters of string2 to string1

	strset(string1, '?');		// sets all characters of a string to a given character
	strnset(string1, 'x', 1);	// sets first n character of a string to a given character 
	strrev(string1);			// reverses a string)

	int result = strlen(string1); 				// returns string lendth as int
	int result = strcmp(string1, string2);		// string compare all  characters
	int result = strncmp(string1, string2, 1); 	// string compare n characters 
	int result = strcmpi(string1, string1);		// string compare all (ignor case)
	int result = strnicmp(string1, string1, 1); // string compare n characters (ignor case)
}

*************************************************************************************************
										FOR
*************************************************************************************************

int main(){
	for(int i = 10; i >= 1; i++){
		printf("%d\n", i);
	}
	return 0;
}

*************************************************************************************************
											WHILE	
*************************************************************************************************

#include <stdio.h>
#include <string.h>

int main(){
	char name[25];
	printf("What is your name?: ");
	fgets(name, 25, stdin);
	name[strlen(name) - 1] = '\0';
	while(strlen(name) == 0){
		printf("You did not enter your name!");
		printf("What is your name?: ");
		fgets(name, 25, stdin);
		name[strlen(name) - 1] = '\0';
	}
	printf("Hello %s", name);
	return 0;
}

*************************************************************************************************
											DO WHILE	
*************************************************************************************************

int main(){
	int number = 0;
	int sum = 0; 
	do{
		printf("Enter a # obove 0: ");
		scanf("%d", &number);
		if(number > 0){
			sum += number;
		}
	}while(number > 0);
	printf("sum: %d", sum);
	return 0;
}

// While loop - cheks condition, then executes
// do while - executes, then cheks condition


*************************************************************************************************
										NESTED LOOP	
*************************************************************************************************

#include <stdio.h>

int main(){
	int rows;
	int columns;
	char symbol;

	printf("Enter # of rows: ");
	scanf("%d", &rows);

	printf("Enter # of columns: ");
	scanf("%d", &columns);

	scanf("%c", &symbol);   		// to get rid of the new line

	printf("Enter a symbol to use: ");
	scanf("%c", &symbol);

	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns; j++){
			printf("%c", symbol);
		}
		printf("\n");
	}
	return 0;
}

*************************************************************************************************
										CONTINUE AND BREAK	
*************************************************************************************************

#include <stdio.h>

int main(){
	for(int i = 1; i <= 20; i++){
		if(i = 13){
			break;  // continue
		}
		printf("%d\n", i);
	}
	return 0;
}
// the break will completely stop the loop at the specific number
// the continue will go on with passing the number 

*************************************************************************************************
											ARRAYS	
*************************************************************************************************

#include <stdio.h>

int main() {
    int numbers[6] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

	numbers[5] = 6;
    
    for (int i = 0; i < length; i++) {
        printf("$%d\n", numbers[i]);
    }
    
    return 0;
}

************************************************************

#include <stdio.h>
#include <string.h>

int main(){
	char cars[][10] = {"Mustang", "Corvette", "Camaro"};
	strcpy(cars[0], "Tesla");
	

	for(int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++){
		printf("%s\n", cars[i]);
	}
	
	return 0;
}

*************************************************************************************************
											2D ARRAYS	
*************************************************************************************************

#include <stdio.h>

int main(){
	int numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int rows = sizeof(numbers)/sizeof(numbers[0]);
	int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

	printf("rows: %d\n", rows);
	printf("columns: %d\n", columns);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%d", numbers[i][j]);
		}
		printf("\n");
	} 
	return 0;
}

*************************************************************************************************
										SWAPPING VARIABLES
*************************************************************************************************
#include <stdio.h>

int main(){

	char x = 'X';
	char y = 'Y';
	char temp;

	temp = x;
	x = y;
	y = temp;
	printf("x = %c\n", x);
	printf("y = %c\n", y);

	return 0;
}

****************************************************

#include <stdio.h>
#include <string.h>

int main(){
	char x[10] = "water";
	char y[10] = "lemonade";
	char temp[10];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
	
	printf("x = %s\n", x);
	printf("y = %s\n", y);

	return 0;
}


*************************************************************************************************
											SORTER	
*************************************************************************************************

#include <stdio.h>

void sort(int array[], int size){
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void printArray(int array[], int size){
	for(int i = 0; i < size; i++){
		printf("%d", array[i]);
	}
}

int main(){
	int array[] = {9, 8, 2, 4, 7, 3, 1, 5, 6};
	int size = sizeof(array)/sizeof(array[0]);
	sort(array, size);	
	printArray(array, size);
	printf("\n");
	return 0;
}

*************************************************************************************************
											STRUCT	
*************************************************************************************************
#include <stdio.h>
#include <string.h>

struct Player{
	char name[12];
	int score;
};

int main(){
	struct Player player1;
	struct Player player2;

	strcpy(player1.name, "Bro");
	player1.score = 4;

	strcpy(player2.name, "Bra");
	player2.score = 5;

	printf("%s ", player1.name);
	printf("%d\n", player1.score);
	printf("%s ", player2.name);
	printf("%d\n", player2.score);

	return 0;
}

*************************************************************************************************
											TYPEDEF
*************************************************************************************************

