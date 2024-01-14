#include<iostream>
using namespace std; 
class Node{ 
	public: 
	int data; 
	Node *next; 
}; 

void push(Node ** h, int val){ 
	Node* n = new Node(); 
	n->data = val; 
	n->next = (*h); 
	(*h) = n; 
} 
void printList(Node *head){ 
	Node *temp = head; 
	while (temp != NULL){ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
	cout<<endl; 
} 
void merge(Node *p, Node **q){ 
	Node *p_curr = p, *q_curr = *q; 
	Node *p_next, *q_next; 
	while (p_curr != NULL && q_curr != NULL){ 
		p_next = p_curr->next; 
		q_next = q_curr->next; 
		q_curr->next = p_next; 
		p_curr->next = q_curr; 
		p_curr = p_next; 
		q_curr = q_next; 
	} 
	*q = q_curr; 
} 
int main(){ 
	Node *p = NULL, *q = NULL; 
	push(&p, 3); 
	push(&p, 2); 
	push(&p, 1); 
	cout<<"First:\n"; 
	printList(p); 

	push(&q, 8); 
	push(&q, 7); 
	push(&q, 6); 
	push(&q, 5); 
	push(&q, 4); 
	cout<<"Second:\n"; 
	printList(q); 

	merge(p, &q); 

	cout<<"after for 1st:\n"; 
	printList(p); 

	cout<<"after for 2nd:\n"; 
	printList(q); 

	return 0; 
} 
