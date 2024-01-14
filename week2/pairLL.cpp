#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void pairWiseSwap(Node* head)
{
	Node* temp = head;
	while (temp != NULL && temp->next != NULL) {
	
		swap(temp->data,temp->next->data);
		temp = temp->next->next;
	}
}

void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	Node* node = NULL;
    push(&node, 7);
    push(&node, 6);
	push(&node, 5);
	push(&node, 4);
	push(&node, 3);
	push(&node, 2);
	push(&node, 1);

	cout << "Linked list "
		<< "before \n";
	printList(node);

	pairWiseSwap(node);

	cout << "\nLinked list "
		<< "after \n";
	printList(node);

	return 0;
}
