#include<iostream>
using namespace std;
struct Node {
   int data;
   struct Node* next;
};
void add(Node** head, int data){
   Node* nodex = new Node;
   nodex->data = data;
   nodex->next = (*head);
   (*head) = nodex;
}
void split(Node* n1, Node* n2){
   Node *temp;
   if (n1 == NULL || n2 == NULL){
      return;
   }
   if (n1->next != NULL){
      temp=n1->next->next;
      n1->next = temp;
   }
   if (n2->next != NULL){
      temp=n2->next->next;
      n2->next = temp;
   }
   split(n1->next, n2->next);
}
void splitList(Node* head, Node** n1, Node** n2){
   *n1 = head;
   *n2 = head->next;
   split(*n1, *n2);
}
void display(Node* head){
   Node* curr = head;
   if (curr != NULL){
      cout<<curr->data<<" ";
      display(curr->next);
   }
}
int main(){
   Node* head = NULL;
   Node *node1 = NULL, *node2 = NULL;
   add(&head, 50);
   add(&head, 14);
   add(&head, 15);
   add(&head, 80);
   add(&head, 10);
   add(&head, 2);
   add(&head, 5);

   cout<<"given :"<<endl;
   display(head);
   splitList(head, &node1, &node2);
   cout<<endl<<"List 1: ";
   display(node1);
   cout<<endl<<"List 2: ";
   display(node2);
   return 0;
}