#include<iostream>
using namespace std;

class Node { 
	public:
	int data; 
	Node* next; 
};  
void sort(Node *head) { 
	int count[3] = {0, 0, 0};
	Node *p = head; 
	while (p != NULL) { 
		count[p->data] += 1; 
		p = p->next; 
	} 
	int i = 0; 
	p = head; 

	while (p != NULL){ 
		if (count[i] == 0) 
			++i; 
		else
		{ 
			p->data = i; 
			--count[i]; 
			p = p->next; 
		} 
	} 
} 

void push (Node** h, int val){ 
	Node* new_node = new Node();

	new_node->data = val; 
	new_node->next = (*h); 
	(*h) = new_node; 
} 
void printList(Node *node) { 
	while (node != NULL){ 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout << endl; 
} 

int main(void) 
{ 
	Node *head = NULL; 
	push(&head, 0); 
	push(&head, 1); 
	push(&head, 0); 
	push(&head, 2); 
    push(&head, 1); 
	push(&head, 1); 
	push(&head, 1); 
    push(&head, 2); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 2); 

	cout << "before \n"; 
	printList(head); 

	sort(head);

	cout << "after\n"; 
	printList(head); 

	return 0; 
} 

