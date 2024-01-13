#include<iostream>
using namespace std; 
class Node { 
	public: 
	int data; 
	Node *next; 
}; 

void oddevenSegregate(Node **head){ 
	Node *end = *head; 
	Node *prev = NULL; 
	Node *curr = *head; 
	while (end->next != NULL) 
		end = end->next; 

	Node *newEnd = end; 

	while (curr->data % 2 != 0 && curr != end) 
	{ 
		newEnd->next = curr; 
		curr = curr->next; 
		newEnd->next->next = NULL; 
		newEnd = newEnd->next; 
	} 

	if (curr->data%2 == 0){ 
		*head = curr; 
		while (curr != end){ 
			if ( (curr->data) % 2 == 0 ){ 
				prev = curr; 
				curr = curr->next; 
			} 
			else{ 
				prev->next = curr->next; 
				curr->next = NULL; 
				newEnd->next = curr; 
				newEnd = curr; 
				curr = prev->next; 
			} 
		} 
	} 
	else prev = curr; 
	if (newEnd != end && (end->data) % 2 != 0) 
	{ 
		prev->next = end->next; 
		end->next = NULL; 
		newEnd->next = end; 
	} 
	return; 
} 

void push(Node** head, int new_data) { 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head); 
	(*head) = new_node; 
} 
void print(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data <<" "; 
		node = node->next; 
	} 
} 
int main(){ 
	Node* head = NULL; 
	push(&head, 21); 
	push(&head, 15); 
	push(&head, 8); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 2); 
	push(&head, 0); 

	cout << "given Linked list "; 
	print(head); 

	oddevenSegregate(&head); 

	cout << "\nafter "; 
	print(head); 

	return 0; 
} 
