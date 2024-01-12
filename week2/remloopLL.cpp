#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void removeLoop(struct Node*, struct Node*);

int detectAndRemoveLoop(struct Node* list){
	struct Node *s = list, *f = list;

	while (s && f && f->next) {
		s = s->next;
		f = f->next->next;
		if (s == f) {
			removeLoop(s, list);

			return 1;
		}
	}
	return 0;
}

void removeLoop(struct Node* n, struct Node* head){
	struct Node* p1 = n;
	struct Node* p2 = n;
	unsigned int k = 1, i;
	while (p1->next != p2) {
		p1 = p1->next;
		k++;
	}
	p1 = head;
	p2 = head;
	for (i = 0; i < k; i++)
		p2 = p2->next;

	while (p2 != p1) {
		p1 = p1->next;
		p2 = p2->next;
	}

	while (p2->next != p1)
		p2 = p2->next;
	p2->next = NULL;
}

void printList(struct Node* node){
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

struct Node* newNode(int key){
	struct Node* temp = new Node();
	temp->data = key;
	temp->next = NULL;
	return temp;
}
int main()
{
	struct Node* head = newNode(150);
	head->next = newNode(24);
	head->next->next = newNode(65);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(160);
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);
	cout << "after removing loop \n";
	printList(head);
	return 0;
}
