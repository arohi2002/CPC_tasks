#include<iostream>
#include <stack>
#include <cstdlib>
using namespace std;
class Node {
public:
	int data;
	Node(int d) { data = d; }
	Node* next;
};

bool isPalindrome(Node* head){
	Node* slow = head;
	stack<int>s;
	while (slow != NULL) {
		s.push(slow->data);
		slow = slow->next;
	}

	while (head != NULL) {
		int i = s.top();
		s.pop();
		if (head->data != i) {
			return false;
		}
		head = head->next;
	}
	return true;
}

int main(){
	Node one = Node(1);
	Node two = Node(2);
	Node three = Node(3);
	Node four = Node(2);
	Node five = Node(1);
	five.next = NULL;
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	Node* temp = &one;
	int ans = isPalindrome(&one);
	if (ans == 1)
		cout << "yes\n";
	else
		cout << "no\n";

	return 0;
}

