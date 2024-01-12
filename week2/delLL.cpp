#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};

void deleteList(Node** head){
	Node* curr = *head;
	Node* next = NULL;

	while (curr != NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

void push(Node** head, int new_data){
	
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

int main(){
	Node* head = NULL;

	push(&head, 1);
	push(&head, 4);
	push(&head, 15);
	push(&head, 16);
	push(&head, 1);

	cout << "Deleting  given linked list";
	deleteList(&head);

	cout << "\nLinked list was deleted";
}

