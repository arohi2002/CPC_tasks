#include<iostream>
using namespace std;
typedef struct Node{
	int val;
	struct Node *next;
}node;

node* create(int val,node* start){
	node *p=new node();
	p->val=val;
	p->next=NULL;
	node *temp=start;
	if(start==NULL){
		start=p;
		start->next=NULL;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=p;
	}
	return start;
}
void printNode(node* s){
	node *p=s;
	while(p!=NULL){
		cout<<p->val;
		if(p->next !=NULL)cout<<"->";
		p=p->next;
	}
}
int mul(node*head1,node*head2){
	node*p=head1;
	int x=0,y=0;
	while(p!=NULL){
		x=x*10+p->val;
		p=p->next;
	}
	p=head2;
		while(p!=NULL){
		y=y*10+p->val;
		p=p->next;
	}
	return x*y;
}
int main(){
	node*head1=NULL;
	head1 = create(1,head1);
	head1 = create(1,head1);
	head1 = create(1,head1);
	node* head2=NULL;
	head2 = create(1,head2);
	head2 = create(1,head2);
	
	cout<<"LinkList 1"<<endl;
	printNode(head1);
	cout<<"\nLinkList 2"<<endl;
	printNode(head2);
	cout<<endl;
	int ans = mul(head1,head2);
	cout<<"Multiplication is : "<<ans;
}