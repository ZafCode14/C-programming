//////////////////////////////////////////////////////////////////////////////////////////////////
								 	// DATA STRUCTURE
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
							 	// LINKED LIST-IMPLEMENTATION 
//////////////////////////////////////////////////////////////////////////////////////////////////

struct node
{
	int data;
	struct node* link;
}
// node* - the pointer to the node 
// int - the datatype or any datatype of the node
// node - pointer + datatype

node* A; 
A = NULL;    // here we created a pointer that points nowhere // empty list

node* temp = (node*)malloc(sizeof(node)); // will create a node

(*temp).data = 2;	// temp -> data = 2;	// the value of the first node // dereferencing
(*temp).link = null;// temp -> link = NULL; // pointer of the first node and it points to nothing
A = temp; 				// write the address of the newly created node in A

// to create a new node 

temp = new node();
temp -> data = 4;	// here we created a new node but it is not connected to the previous node
temp -> link = NULL;

// traversal logic of the list 

node*temp1 = A;
while(temp1 -> link! = NULL){
	temp1 = temp1 - link;
	print "temp -> data";
}
temp1 -> link = temp;  // creates the link ( from temp to temp1 )

//////////////////////////////////////////////////////////////////////////////////////////////////
							 	// INSERTING A NODE AT BEGINNING 
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;	// this is the head node and it is allways in the beginning

void Insert(int x){
	struct Node* temp = (int*)malloc(sizeof(struct Node)); 	// creating a space for the node
	(*temp).data = x; 			// temp -> data = x;	// value of the node 
	temp -> next = head;		// when the list is empty head is = NULL 
	// in other words: point new temp to old temp!! and old temp will always = NULL
	head = temp; 				// pointing the head to the temp node
}
// creating every ricently added in the beginning of the list
void Print(){
	struct Node* temp = head;  	// this variable is going to have the address of the head
	printf("List is: ");
	while(temp != NULL){		// while temp is not in the end 
		printf(" %d", temp -> data);	// print the data of the temp
		temp = temp -> next;	// keep traversing the list
	}
	printf("\n");
}
int main(){  
	head = NULL; // so far we created an empty list with just a pointer that points nowhere
	printf("How many numbers?\n");
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Enter a number \n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
								// INSERTING A NODE AT nth POSITION	 
//////////////////////////////////////////////////////////////////////////////////////////////////

// linked list: Inserting a node at begginnnig
#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int data, int n){		// recieving an integer and the position
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));	// creating the node 
	temp1 -> data = data;	// Node value 
	temp1 -> next = NULL;	// Node pointer
	if(n == 1){		// if there is 1 node 
		temp1 -> next = head; 	// point the node temp1 to head, which is NULL
		head = temp1;	// pointing the head node to to the addresss of temp1 
		 // which makes the node temp 1 pointing to NULL and being pointet to by head
	}else{
		struct Node* temp2 = head;	// create a second pointer that points to head
		for(int i = 0; i < n-2; i++){ // this for will not execute untill the third node
			temp2 = temp2 -> next; 
		}
		temp1 -> next = temp2 -> next; 	// the created node will point to NULL
		// temp2 -> next // is the previous nodes next which is NULL
		temp2 -> next = temp1; // now (temp2 - next) is liked to the newly created node (tamp1) 
	}
		
}
void Print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ", temp -> data);
		temp = temp -> next; 
	}
	printf("\n");
}
int main(){
	head = NULL; // empty list  // global variable Node*
	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 3);
	Insert(5, 4);
	Print();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
								// DELETING A NODE AT nth POSITION	 
//////////////////////////////////////////////////////////////////////////////////////////////////

// Linked List: Delete a node at nth position

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head;	// global head pointer 

void Insert(int x){ 					// inserting a node at the end of the list 
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));// creating space for node
	temp1 -> data = x;					// temp1 value 
	temp1 -> next = NULL;				// temp1 pointer 
	if(head == NULL){					// plcing the first node 
		head = temp1;					// poit head to temp1
	}else{								// placing the next nodes 
		struct Node* temp2 = head;		// creating access to the first node 
		while(temp2 -> next != NULL){	
			temp2 = temp2 -> next;		// reaching the node before the last 
		}
		temp2 -> next = temp1;	// setting the pointer of the node before the last ponting to
	} 							// the newly created node 	
}
void Print(){					// printing the list 
	struct Node* temp = head;	// crearing access to the first node with temp
	printf("list is: ");	
	while(temp != NULL){				// keep loopint through until you reach node with NULL 
		printf("%d ", temp -> data);	// print the data in the node 
		temp = temp -> next;			// move to the next node
	}
	printf("\n");
}
void Delete(int n){					// deleting a node 
	struct Node* temp1 = head;		// access the first node and name it temp1
	if(n == 1){						// if we want to delete the fist position
		head = temp1 -> next;		// link the head to the node after temp1 
		free(temp1);				// delete temp1
	}else{
		int i;
		for(i = 0; i < n-2; i++){		// to access the third node or any node after the third
			temp1 = temp1 -> next;
		}
		struct Node* temp2 = temp1 -> next; // accessing the current node with temp2
		temp1 -> next = temp2 -> next;		// linking the node before to the node after  
		free(temp2);						// deleting the current node 
	}
}
int main(){
	head = NULL;
	Insert(1);
	Insert(3);
	Insert(6);
	Insert(4);
	Insert(8);
	Print();
	int n;
	printf("Enter a position\n");
	scanf("%d", &n);
	Delete(n);
	Print();
}


//////////////////////////////////////////////////////////////////////////////////////////////////
								// 	REVERSE A LIKED LIST
//////////////////////////////////////////////////////////////////////////////////////////////////

// Reverse a linked list using a loop iterative solution
// and removing the head from global and passing it as local in main
#include<stdio.h>
#include<stdlib.h>
									// here i will try to explain the local use of head
struct Node{					
	int data; 
	struct Node* next;
};
void Insert(struct Node** head, int x){ 	// recieving a pointer to a pointer
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
	}else{
		struct Node* temp1 = *head;
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}
void Print(struct Node* temp){
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
struct Node* Reverse(struct Node* head){
	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
int main(){
	struct Node* head = NULL;
	Insert(&head, 3);	// passing a pointer of the head pointer
	Insert(&head, 1);
	Insert(&head, 9);
	Insert(&head, 7);
	Insert(&head, 4);
	Print(head);
	head = Reverse(head);
	Print(head);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
							// LISINT LINKED LIST USING RECURSION
//////////////////////////////////////////////////////////////////////////////////////////////////

// print linked list using recursion

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* Insert(struct Node* head, int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}else{
		struct Node* temp1 = head;
		while(temp1->next != NULL){
			temp1 = temp1->next;
		} 
		temp1->next = temp;
	}
	return head;
}
void Print(struct Node* p){
	if (p == NULL){
		return;
	}
	Print(p->next);
	printf("%d ", p->data);		// will print in reversed order
}
int main(){
	struct Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 3);
	head = Insert(head, 9);
	Print(head);
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
							// 	DOUBLY LINKED LIST-IMPLEMENTATION 
//////////////////////////////////////////////////////////////////////////////////////////////////

// doubly linked implementation 

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;	// using a global variable
struct Node* GetNewNode(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;		// the function for getting a new node
	newNode->next = NULL;
	return newNode;
}
void InsertAtHead(int x){
	struct Node* newNode = GetNewNode(x); 	// the function for creating a node in the beginning
	if(head == NULL){
		head = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}
void InsertAtTail(int x){
	struct Node* newNode = GetNewNode(x); 	// the function for creating a node at the end
	if(head == NULL){
		head = newNode;
	}else{
		struct Node* oldNode = head;
		while(oldNode->next != NULL){
			oldNode = oldNode->next;
		}
			oldNode->next = newNode;
			newNode->prev = oldNode;
			newNode->next = NULL;
	}
}
void ReversePrint(){	// the function for reversing the list	
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL){
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
void Print(){	// printing the list 
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(){
	head = NULL; // empty list 
	InsertAtTail(2);
	InsertAtTail(9);
	InsertAtTail(7);
	InsertAtTail(4);
	Print();
	ReversePrint();
}
