#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
Node* intersectionNode(Node* head1, Node* head2){
	while (head2){
		Node* temp = head1;
		while (temp){
			if (temp == head2)
				return head2;
			temp = temp->next;
		}
		head2 = head2->next;
	}
	return NULL;
}

int main(){
	Node* newNode;
	Node* head1 = new Node();
	head1->data = 50;
	Node* head2 = new Node();
	head2->data = 2;
	newNode = new Node();
	newNode->data = 46;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 5;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	Node* intersectionPoint
		= intersectionNode(head1, head2);

	if (!intersectionPoint)
		cout << " No Intersection  \n";
	else
		cout << "Intersection Point is : "
			<< intersectionPoint->data << endl;
}

