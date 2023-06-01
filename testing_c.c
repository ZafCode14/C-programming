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
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void InsertAtHead(int x){
	struct Node* newNode = GetNewNode(x);
	if(head == NULL){
		head = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}
void InsertAtTail(int x){
	struct Node* newNode = GetNewNode(x);
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
void ReversePrint(){
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
void Print(){
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
