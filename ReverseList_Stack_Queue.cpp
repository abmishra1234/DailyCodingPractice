/*
	- Reverese the Linklist with Stack and Queue
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<stack>
#include<queue>

struct Node {
	int data;
	Node* next;
	Node() {
		next = nullptr;
	}
};

struct ReverseList {
	stack<Node*> stk;
	queue<Node*> queue;

	/*
		Let's implement the code for linked list
	*/
	void addNode(Node** head, int data) {
		Node* np = new Node();
		np->data = data;

		if (*head == nullptr) {
			*head = np;
		}
		else {
			np->next = *head;
			*head = np;
		}
	}

	void print(Node* head) {
		Node* start = head;
		while (start) {
			cout << start->data;
			if (start->next != nullptr)
				cout << " -> ";
			start = start->next;
		}
		cout << endl;
	}

	Node* reverseUsingStack(Node* head) {
		Node* start = head;
		
		while (start) {
			Node* curr = start;
			start = start->next;
			curr->next = nullptr;
			stk.push(curr);
		}
		
		Node* tail = head = nullptr;

		while (!stk.empty()) {
			Node* curr = stk.top();
			stk.pop();
			if (head == nullptr) {
				head = tail = curr;
			}
			else
			{
				tail->next = curr;
				tail = curr;
			}
		}
		return head;
	}

	Node* reverseUsingQueue(Node* head) {
		Node* start = head;

		while (start) {
			Node* curr = start;
			start = start->next;
			curr->next = nullptr;
			queue.push(curr);
		}

		head = nullptr;
		while (!queue.empty()) {
			Node* curr = queue.front();
			queue.pop();

			if (head == nullptr) {
				head = curr;
			}
			else
			{
				curr->next = head;
				head = curr;
			}
		}

		return head;
	}

};


// The Driver code for verification of reverse linked list is given below
int main() {
	ReverseList rl;

	/*
		Yes so the below code is for generating the linked list
	*/
	Node* head = nullptr;
	rl.addNode(&head, 4);
	rl.addNode(&head, 3);
	rl.addNode(&head, 2);
	rl.addNode(&head, 1);

	// Just verify your created linked list
	rl.print(head);

	head = rl.reverseUsingStack(head);
	// Just verify your reversed linked list using stack
	rl.print(head);

	head = rl.reverseUsingQueue(head);
	// Just verify your reversed linked list using queue
	rl.print(head);

	return 0;
}





#endif // !FORREF



