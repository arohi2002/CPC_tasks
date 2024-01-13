#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

class LinkedList {
public:
	struct Node {
		int data;
		Node* next;
		Node(int d)
			: data(d)
			, next(NULL)
		{
		}
	};
	Node* head = NULL;

	void printList(){
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void push(int val){
		Node* new_node = new Node(val);
		new_node->next = head;
		head = new_node;
	}

	void append(int val){
		if (head == NULL) {
			Node* n = new Node(val);
			head = n;
			return;
		}
		Node* n1 = head;
		Node* n2 = new Node(val);
		while (n1->next != NULL) {
			n1 = n1->next;
		}
		n1->next = n2;
		n2->next = NULL;
	}

	bool isPresent(Node* head, int data)
	{
		Node* tmp = head;
		while (tmp != NULL) {
			if (tmp->data == data)
				return true;
			tmp = tmp->next;
		}
		return false;
	}

	LinkedList getIntersection(Node* head1, Node* head2){
		unordered_set<int> s;
		Node* n1 = head1;
		Node* n2 = head2;
		LinkedList res;

		while (n1 != NULL) {
			if (s.find(n1->data) == s.end()) {
				s.insert(n1->data);
			}
			n1 = n1->next;
		}

		while (n2 != NULL) {
			if (s.find(n2->data) != s.end()) {
				res.push(n2->data);
			}
			n2 = n2->next;
		}
		return res;
	}

	LinkedList getUnion(Node* head1, Node* head2){
		map<int, int> hmap;
		Node* n1 = head1;
		Node* n2 = head2;
		LinkedList res;
		while (n1 != NULL) {
			if (hmap.find(n1->data) != hmap.end()) {
				hmap[n1->data]++;
			}
			else {
				hmap[n1->data] = 1;
			}
			n1 = n1->next;
		}

		while (n2 != NULL) {
			if (hmap.find(n2->data) != hmap.end()) {
				hmap[n2->data]++;
			}
			else {
				hmap[n2->data] = 1;
			}
			n2 = n2->next;
		}

		for (auto it = hmap.begin(); it != hmap.end();
			it++) {
			res.append(it->first);
		}
		return res;
	}
};

int main()
{
	LinkedList llist1, llist2, intersection, union_list;

	llist1.push(90);
	llist1.push(9);
	llist1.push(15);
	llist1.push(10);

	llist2.push(13);
	llist2.push(2);
	llist2.push(9);
	llist2.push(8);

	intersection = intersection.getIntersection(
		llist1.head, llist2.head);
	union_list
		= union_list.getUnion(llist1.head, llist2.head);

	cout << "list1 " << endl;
	llist1.printList();

	cout << "List 2 " << endl;
	llist2.printList();

	cout << "Intersection :" << endl;
	intersection.printList();

	cout << "Union :" << endl;
	
	union_list.printList();
}

