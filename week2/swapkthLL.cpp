#include<iostream>
using namespace std; 
typedef struct Node { 
	int data; 
	struct Node* next; 
} Node; 

void push(Node** h, int new_data){ 
	Node* new_node = (Node*)malloc(sizeof(Node)); 
	new_node->data = new_data; 
	new_node->next = (*h); 
	(*h) = new_node; }
void printList(Node* node){ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout << endl; 
} 

int countingnodes(struct Node* s){ 
	int count = 0; 
	while (s != NULL) { 
		count++; 
		s = s->next; 
	} 
	return count; 
} 
 
void swapKth(struct Node** h, int k) { 
	int n = countingnodes(*h); 
	if (n < k) 
		return; 
	if (2 * k - 1 == n) 
		return; 
	Node* x = *h; 
	Node* x_prev = NULL; 
	for (int i = 1; i < k; i++) { 
		x_prev = x; 
		x = x->next; 
	} 
	Node* y = *h; 
	Node* y_prev = NULL; 
	for (int i = 1; i < n - k + 1; i++) { 
		y_prev = y; 
		y = y->next; 
	} 
	if (x_prev) 
		x_prev->next = y; 

	if (y_prev) 
		y_prev->next = x; 
	Node* temp = x->next; 
	x->next = y->next; 
	y->next = temp; 
	if (k == 1) 
		*h = y; 
	if (k == n) 
		*h = x; 
} 

int main(){ 
	struct Node* head = NULL; 
	for (int i = 8; i >= 1; i--) 
		push(&head, i); 
	cout << "Original : "; 
	printList(head); 
	for (int k = 1; k < 9; k++) { 
		swapKth(&head, k); 
		cout << "\nafter swap" << k << endl; 
		printList(head); 
	} 
	return 0; 
} 
