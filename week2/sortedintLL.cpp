#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void push(Node** head, int new_data);
Node* sortedllinter(Node* a, Node* b){
	Node t;
	Node* tail = &t;
	t.next = NULL;
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;}
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return (t.next);
}

void push(Node** head, int new_data){

	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->data = new_data;
	new_node->next = (*head);

	(*head) = new_node;
}

void printList(Node* node){
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
}

int main(){
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;
	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);
	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sortedllinter(a, b);
	cout<<"Linked list intersection containing common items of a & b \n";
	printList(intersect);
}
