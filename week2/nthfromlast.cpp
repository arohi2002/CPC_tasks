#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void nthfromlast(struct Node* head, int N){
	int l = 0, i;
	struct Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		l++;
	}

	if (l < N){
        return;
    }

	temp = head;
	for (i = 1; i <l- N+1; i++)
		temp = temp->next;

	cout << temp->data;
	return;
}

void push(struct Node** head, int new_data){
	struct Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head);

	(*head) = new_node;
}
int main(){
	struct Node* head = NULL;
	push(&head, 20);
	push(&head, 40);
	push(&head, 150);
	push(&head, 75);
	nthfromlast(head, 3);
	return 0;
}
