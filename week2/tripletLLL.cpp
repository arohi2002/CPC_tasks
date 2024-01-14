#include<iostream>
using namespace std;
class Node{ 
	public:
	int data; 
	Node* next; 
}; 
void push (Node** h, int val){
	Node* n = new Node();
	n->data = val; 
	n->next = (*h); 
	(*h) = n; 
} 

bool isSumSorted(Node *hA, Node *hB, 
				Node *hC, int hD){ 
	Node *a = hA;  
	while (a != NULL){ 
		Node *b = hB; 
		Node *c = hC; 
		while (b != NULL && c != NULL){ 
			int sum = a->data + b->data + c->data; 
			if (sum == hD){ 
			cout << "Triplet Found: " << a->data << " " << 
								b->data << " " << c->data; 
			return true; 
			} 
			else if (sum < hD) 
				b = b->next; 
			else 
				c = c->next; 
		} 
		a = a->next;
	} 

	cout << "No triplet"; 
	return false; 
} 

int main(){ 
	Node* hA = NULL; 
	Node* hB = NULL; 
	Node* hC = NULL; 
	push (&hA, 20); 
	push (&hA, 4); 
	push (&hA, 15); 
	push (&hA, 10); 
	push (&hB, 10); 
	push (&hB, 9); 
	push (&hB, 4); 
	push (&hB, 2); 
	push (&hC, 1); 
	push (&hC, 2); 
	push (&hC, 4); 
	push (&hC, 8); 

	int hD = 25; 

	isSumSorted (hA, hB, hC, hD); 

	return 0; 
} 

