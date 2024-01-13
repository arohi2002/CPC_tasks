#include<iostream>
using namespace std; 
class Node { 
	public: 
	int data; 
	Node *next; 
}; 
void delAlt(Node *head) { 
	if (head == NULL) {
        return;
    }
	Node *prev = head; 
	Node *node = head->next; 
	while (prev != NULL && node != NULL){ 
		prev->next = node->next; 
		delete(node);
		prev = prev->next; 
		if (prev != NULL) 
			node = prev->next; 
	} 
} 
void push(Node** h, int val) { 
	
	Node* n = new Node(); 
	n->data = val; 
	n->next = (*h); 

	(*h) = n; 
} 

void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<< node->data<<" "; 
		node = node->next; 
	} 
} 
int main() { 
	Node* head = NULL; 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	cout<<"before \n"; 
	printList(head); 

	delAlt(head); 

	cout<<"\nafter\n"; 
	printList(head); 

	return 0; 
} 
