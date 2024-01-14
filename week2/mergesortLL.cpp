#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
Node* merge(Node* a, Node* b);
void split(Node* s,Node** f, Node** b);
void MergeSort(Node** h){
	Node* head = *h;
	Node* a;
	Node* b;

	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	split(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);
	*h = merge(a, b);
}
Node* merge(Node* a, Node* b){
	Node* result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->data <= b->data) {
		result = a;
		result->next = merge(a->next, b);
	}
	else {
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}
void split(Node* s,Node** f, Node** b){
	Node* fast;
	Node* slow;
	slow = s;
	fast = s->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*f = s;
	*b = slow->next;
	slow->next = NULL;
}
void printList(Node* node){
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
int main(){
	Node* res = NULL;
	Node* a = NULL;
	push(&a, 17);
	push(&a, 11);
	push(&a, 4);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);
	MergeSort(&a);

	cout << "Sorted : \n";
	printList(a);

	return 0;
}
