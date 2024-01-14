#include<iostream>
#include <cinttypes> 
using namespace std;
class Node { 
	public:
	int data; 
	Node* next; 
}; 
Node* XOR (Node *a, Node *b) { 
	return reinterpret_cast<Node *>(
	reinterpret_cast<uintptr_t>(a) ^ 
	reinterpret_cast<uintptr_t>(b)); 
} 
void insert(Node **h, int data) { 
	Node *new_node = new Node(); 
	new_node->data = data; 
	new_node->next = *h; 
	if (*h != NULL){ 
		(*h)->next = XOR(new_node, (*h)->next); 
	} 
	*h = new_node; 
} 
void printList (Node *head) 
{ 
	Node *curr = head; 
	Node *prev = NULL; 
	Node *next; 
	cout << "List \n"; 
	while (curr != NULL){ 	
		cout<<curr->data<<" "; 
		next = XOR (prev, curr->next); 
		prev = curr; 
		curr = next; 
	} 
} 
int main () { 
	Node *head = NULL; 
	insert(&head, 10); 
	insert(&head, 20); 
	insert(&head, 30); 
	insert(&head, 40); 

	printList (head); 

	return (0); 
} 
