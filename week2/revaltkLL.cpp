#include<iostream>
using namespace std;

class Node { 
	public:
	int data; 
	Node* next; 
}; 

Node *altKrev(Node *head, int k) 
{ 
	Node* c = head; 
	Node* next; 
	Node* prev = NULL; 
	int count = 0; 

	while (c != NULL && count < k) 	{ 
	next = c->next; 
	c->next = prev; 
	prev = c; 
	c = next; 
	count++; 
	} 
	
	if(head != NULL) 
	head->next = c; 
	count = 0; 
	while(count < k-1 && c != NULL){ 
	c = c->next; 
	count++; 
	} 
	if(c != NULL) 
	c->next = altKrev(c->next, k); 
	return prev; 
} 

void push(Node** head, int val){ 
	Node* n = new Node();
	n->data = val; 
	n->next = (*head);	 
	(*head) = n; 
} 

void printList(Node *node) { 
	int count = 0; 
	while(node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
		count++; 
	} 
} 
int main(void) { 
	Node* head = NULL; 
	int i;
	for(i = 16; i > 0; i--) 
	push(&head, i); 

	cout<<"Given\n"; 
	printList(head); 
	head = altKrev(head, 3); 

	cout<<"\nafter \n"; 
	printList(head); 
	return(0); 
} 

