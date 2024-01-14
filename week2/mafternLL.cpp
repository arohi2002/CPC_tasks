#include<iostream>
using namespace std; 
class Node { 
	public: 
	int data; 
	Node *next; 
}; 
void push(Node ** h, int val) { 
	Node* n = new Node(); 
	n->data = val; 
	n->next = (*h); 
	(*h) = n; 
} 
void printList(Node *head) { 
	Node *temp = head; 
	while (temp != NULL) 
	{ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
	cout<<endl; 
} 

void maftern(Node *head, int M, int N) { 
	Node *curr = head, *t; 
	int count; 
	while (curr){ 
		for (count = 1; count < M && 
				curr!= NULL; count++) 
			curr = curr->next; 
		if (curr == NULL) 
			return; 
		t = curr->next; 
		for (count = 1; count<=N && t!= NULL; count++) 
		{ 
			Node *temp = t; 
			t = t->next; 
			free(temp); 
		} 
		curr->next = t; 
		curr = t; 
	} 
} 
int main(){ 
	Node* head = NULL; 
	int M=2, N=3; 
	push(&head, 10); 
	push(&head, 9); 
	push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	cout << "M = " << M<< " N = " << N << "\nGiven :\n"; 
	printList(head); 

	maftern(head, M, N); 

	cout<<"\nafter :\n"; 
	printList(head); 

	return 0; 
} 
