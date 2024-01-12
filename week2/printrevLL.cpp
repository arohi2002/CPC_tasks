#include<iostream>
using namespace std;

class Node { 
	public:
	int data; 
	Node* next; 
}; 

void printReverse(Node* head){ 
	
	if (head == NULL) {
	return; }

	printReverse(head->next); 

	cout << head->data << " "; 
} 

void push(Node** h, char newData) { 

	Node* newNode = new Node();
	newNode->data = newData; 
	newNode->next = (*h); 

	(*h) = newNode; 
} 

int main() 
{ 
	Node* head = NULL; 
    	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 
	
	printReverse(head); 
	return 0; 
} 

