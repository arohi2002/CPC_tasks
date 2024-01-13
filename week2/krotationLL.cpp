#include<iostream>
using namespace std; 
class Node { 
public: 
	int data; 
	Node* next; 
}; 
void rotate(Node** head, int k) { 
	if (k == 0) 
		return; 
	Node* current = *head; 

	int count = 1; 
	while (count < k && current != NULL) { 
		current = current->next; 
		count++; 
	} 
	if (current == NULL) 
		return; 

	Node* kthNode = current; 

	while (current->next != NULL) 
		current = current->next; 

	current->next = *head; 
	*head = kthNode->next; 
	kthNode->next = NULL; 
} 

void push(Node** head, int val) { 
	Node* new_node = new Node(); 
	new_node->data = val; 
	new_node->next = (*head); 
	(*head) = new_node; 
} 

void printList(Node* node) { 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

int main(void) { 
	Node* head = NULL; 
	for (int i = 8; i > 0; i -= 1) 
		push(&head, i); 

	cout << "before\n"; 
	printList(head); 
	rotate(&head, 4); 

	cout << "\nafter rotation \n"; 
	printList(head); 

	return (0); 
} 
