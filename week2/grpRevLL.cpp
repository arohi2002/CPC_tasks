#include<iostream>
using namespace std; 
class Node { 
public: 
	int data; 
	Node* next; 
}; 
Node* reverse(Node* head, int k) { 
	if (!head) {
		return NULL;} 
	Node* curr = head; 
	Node* next = NULL; 
	Node* prev = NULL; 
	int count = 0; 
	while (curr != NULL && count < k) { 
		next = curr->next; 
		curr->next = prev; 
		prev = curr; 
		curr = next; 
		count++; 
	} 
	if (next != NULL) 
		head->next = reverse(next, k); 
	return prev; 
} 

void push(Node** head, int val) {
	Node* n = new Node(); 
	n->data = val; 
	n->next = (*head); 
	(*head) = n; 
} 

void printList(Node* node) { 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

int main() { 
	Node* head = NULL; 
	push(&head, 9); 
	push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 
	cout << "before \n"; 
	printList(head); 
	head = reverse(head, 3); 

	cout << "\nReversed:\n"; 
	printList(head); 

	return (0); 
} 
