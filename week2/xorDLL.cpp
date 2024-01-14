#include <iostream>
#include <cstdint>
struct Node {
	int data;
	Node* both;
};

class XORLL{
private:
	Node* head;
	Node* tail;
	Node* XOR(Node* a, Node* b);

public:

	XORLL();
	void insert_at_head(int data);
	void insert_at_tail(int data);
	void delete_from_head();
	void delete_from_tail();
	void print_list();
};

XORLL::XORLL(){
	head = tail = nullptr; 
}

Node* XORLL::XOR(Node* a, Node* b){
	return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void XORLL::insert_at_head(int data){
	Node* new_node = new Node();
	new_node->data = data;
	new_node->both = XOR(nullptr, head);

	if (head) {
		head->both
			= XOR(new_node, XOR(head->both, nullptr));
	}
	else {
		tail = new_node;
	}
	head = new_node;
}

void XORLL::insert_at_tail(int data){
	Node* new_node = new Node();
	new_node->data = data;
	new_node->both = XOR(tail, nullptr);

	if (tail) {
		tail->both
			= XOR(XOR(tail->both, nullptr), new_node);
	}
	else {
		head = new_node;
	}
	tail = new_node;
}

void XORLL::delete_from_head()
{
	if (head) {
		Node* next = XOR(head->both, nullptr);
		delete head;
		head = next;

		if (next) {
			next->both = XOR(next->both, head);
		}
		else {
			tail = nullptr;
		}
	}
}

void XORLL::delete_from_tail()
{
	if (tail) {
		Node* prev = XOR(tail->both, nullptr);
		delete tail;
		tail = prev;

		if (prev) {
			prev->both = XOR(prev->both, tail);
		}
		else {
			head = nullptr;
		}
	}
}

void XORLL::print_list(){
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		std::cout << current->data << " ";
		Node* next = XOR(prev, current->both);
		prev = current;
		current = next;
	}
	std::cout << std::endl;
}

int main(){
	XORLL root;
	root.insert_at_head(10);
	root.insert_at_head(20);
	root.insert_at_tail(30);
	root.insert_at_tail(40);
	
	root.print_list();
	root.delete_from_head();
	root.print_list();
	root.delete_from_tail();
	root.print_list();
	return 0;
}
