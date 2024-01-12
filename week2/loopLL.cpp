#include<iostream>
#include<unordered_set>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int d){
	struct Node* n = new Node;
	n->data = d;
	n->next = (*head_ref);
	(*head_ref) = n;
}
bool detectLoop(struct Node* h){
	unordered_set<Node*> s;
	while (h != NULL) {
		if (s.find(h) != s.end())
			return true;
		s.insert(h);
		h = h->next;
	}

	return false;
}
int main(){
	struct Node* head = NULL;

	push(&head, 23);
	push(&head, 44);
	push(&head, 15);
	push(&head, 10);

	head->next->next->next->next = head;

	if (detectLoop(head))
		cout << "Loop was Found";
	else
		cout << "No Loop found";

	return 0;
}
