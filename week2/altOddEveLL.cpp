#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
};
void print(Node* head){
    Node *t=head; 
    while(t!=NULL){
        cout<<t->value<<" ";
        t=t->next;
    }
    cout<<endl;
}

Node* new_node(int num){
    Node* t=new Node;
    t->value=num;
    t->next=NULL;
    return t;
}
 
Node* insert(Node* head, int num){
    Node* t=new_node(num);
    if(head==NULL) 
    {
        head=t;  
        return head;
    }
    Node *s=head; 
    while(s->next!=NULL) 
        s=s->next; 
    s->next=t;
    return head;
}
 
void oddEve(Node* head){
    stack<Node*> odd;
    stack<Node*> even;
    int p=1;
    while (head!=NULL){
 
        if(head->value%2!=0 && p%2==0) 
        {
            odd.push(head);
        }
        else if(head->value%2==0 && p%2!=0) 
        {
            even.push(head);
        }
        head=head->next;
        p++;
    }
    while (!odd.empty()&&!even.empty()) 
    {
 
        swap(even.top()->value,odd.top()->value);
        even.pop();
        odd.pop();
    }
}
 
int main()
{ 
	Node* head=new_node(5);
	head=insert(head,6);
	head=insert(head,12);
	head=insert(head,11);
	head=insert(head,1);
	head=insert(head,18);
   	
	cout<<"Linked List before: ";
	print(head);
	oddEve(head);
 	
	cout<<"Linked List after: ";
	print(head);
    return 0;
}