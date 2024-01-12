#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
	}
};
struct LinkedList {
	Node* head;
	LinkedList() { 
        head = NULL; }
	
 void reverse(){
		Node* curr = head;
		Node *prev = NULL, *next = NULL;

		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	void print(){
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data){
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main(){
	LinkedList linkedlist;
	linkedlist.push(23);
	linkedlist.push(14);
	linkedlist.push(35);
	linkedlist.push(65);

	cout << "linked list before\n";
	linkedlist.print();

	linkedlist.reverse();

	cout << "\nafter reversing \n";
	linkedlist.print();
	return 0;
}
