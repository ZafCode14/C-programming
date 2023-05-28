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

