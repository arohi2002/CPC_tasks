#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class nodeop{
public:
	void pushNode(class Node** h,int val){
		class Node *new_node = new Node();
		new_node->data = val;
		new_node->next = *h;
		*h = new_node;
	}
};
int main() {
class Node *head = NULL;
	class nodeop *temp = new nodeop();
	for(int i=10; i>0; i--){
		temp->pushNode(&head, i);
	}
	vector<int>v;
	while(head!=NULL){
	v.push_back(head->data);
	head=head->next;
	}
	cout<<"Middle of Linked List is :";
	cout<<v[v.size()/2]<<endl;
	return 0;
}
