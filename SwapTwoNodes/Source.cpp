#include <iostream>
using namespace std;

struct node {
	int id;
	node* next = NULL;
};

class LinkedList {
public:
	node* first=NULL;
	node* last=NULL;

	// swaps the mth node from start with the nth node from end
	void swapNodes(int m, int n) {

		//finding the mth node from start
		node* p = first, * followP = NULL;
		int j=0;
		for (int i = 1; i < m; i++) {
			followP = p;
			p = p->next;
			j = i;
			if (p == NULL)
				break;
		}
		if (j != m - 1) {
			cout << "First Index of out Bounds" << endl;
			return;
		}

		//finding the nth node from end
		node* q = first, * followQ = NULL, * k = last;
		for (int i = 1; i <= n; i++) {
			q = first;
			followQ = NULL;
			j = i;
			while (q != k) {
				followQ = q;
				q = q->next;
			}
			if (q == NULL)
				break;
			k = followQ;
		}
		if (j != n) {
			cout << "Second Index of out Bounds" << endl;
			return;
		}

		//cannot swap if they are the same node
		if (p == q) {
			cout << "Same node. Cannot be swapped!" << endl;
			return;
		}

		//swapping of nodes
		if (followP == NULL) {
			first = q;
		}
		else {
			followP->next = q;
		}

		if (followQ == NULL) {
			first = p;
		}
		else {
			followQ->next = p;
		}

		node* temp = p->next;
		p->next = q->next;
		q->next = temp;

		if (q->next == NULL)
			last = q;
		if (p->next == NULL)
			last = p;
		cout << "Nodes have been swapped!" << endl;
	}


	void insertEnd(int x) {
		node* curr = new node;
		curr->id = x;
		if (first == NULL) {
			first = last = curr;
		}
		else {
			last->next = curr;
			last = curr;
		}
	}
	void deleteEnd() {
		if (first == NULL) {
			return;
		}
		else if (first == last) {
			node *q = last;
			delete q;
			first = last = NULL;
		}
		else {
			node* p = NULL;
			while (p->next != NULL) {
				p = p->next;
			}
			node* q = last;
			last = p;
			delete q;
		}

	}

	void display() {
		node* p = first;
		if (p == NULL) {
			return;
		}
		else {
			while (p != NULL) {
				cout << p->id << endl;
				p = p->next;
			}
		}
	}
};

int main() {

	LinkedList l1;
	int choice;

	do {
		cout << "\n1: Insert Value At End\n2: Delete Value From End\n3: Swap Any Two Values\n4: Display Values";
		cout << "\n0: Exit\n";
		do {
			cout << "Choose an option (0-4): ";
			cin >> choice;
		} while (choice < 0 || choice > 4);

		switch (choice) {
		case 0:
			exit(0);
		case 1: 
			{
				cout << "Enter value: ";
				int x;
				cin >> x;
				l1.insertEnd(x);
				cout << "Value Inserted!" << endl;
			}
			break;
		case 2: 
			{
				l1.deleteEnd();
				cout << "Value Deleted From End!" << endl;
			}
			break;
		case 3: 
		{
			int m, n;
			cout << "Swap which node from start?";
			cin >> m;
			cout << "With which node from end? ";
			cin >> n;
			l1.swapNodes(m, n);
		}
			break;
		case 4: l1.display();
			break;
		}
	} while (choice != 0);

}