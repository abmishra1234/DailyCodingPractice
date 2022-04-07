/*
	Detect the loop or cycle in Linkedlist

*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<unordered_set>

struct Node {
	int data;
	Node* next;
	Node() {
		next = nullptr;
	}
};

struct DetectLoop {
	// Adding node into linked list
	void addNode(Node** head, int data) {

		Node* newNode = new Node();
		newNode->data = data;

		if (*head == nullptr) {
			*head = newNode;
		}
		else
		{
			newNode->next = *head;
			(*head) = newNode;
		}
	}
	/*
		Approach 01 - 
		
		Using the hash table for maintainnig the elemen and check if you are reaching the samenode before termination
		to NULL than it will be cycle otherwise not a cycle in linked list

		In this approach, every thing seems fine to me except we had taken extra memory for maintaing the node cache to compare
		So how to remove this extra memory requirement is the improvement goal of this approach.

	/*	*/
	bool isCycle_Approach01(Node* head) {
		unordered_set<Node*> nodecache;
		Node* start = head;
		while (start) {
			if (nodecache.find(start) != nodecache.end()) {
				return true;
			}
			else
				nodecache.insert(start);
			start = start->next;
		}
		return false;
	}
	/*
		So your target of this approach is Time O(n), space is O(1)					
		One more good approach is Two pointer approach

		on the same linklist there are two iterator one which is moving one step ahead, and other which is moving two step ahead
		see if they meet before encounter the nullptr. If both pointer met your loop will end and return the affirmation for cycle exist,
		otherwise return false since cycle don't exist.

	*/
	bool isCycle_Approach02(Node* head) {
		Node* slow = head;
		Node* fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				return true;
			}
		}

		return false;
	}

};


	/*
		Driver code for checking the Cycle detection in linkedlist
	*/
	int main() {
		DetectLoop dl;
		Node* head = nullptr;
		dl.addNode(&head, 5);
		dl.addNode(&head, 4);
		dl.addNode(&head, 3);
		dl.addNode(&head, 2);
		dl.addNode(&head, 1);

		// creating the loop from below code
		head->next->next->next->next->next = head->next;

		cout << "Detected Cycle : " << dl.isCycle_Approach01(head) << endl;

		cout << "Approach02 --> Detected Cycle : " << dl.isCycle_Approach02(head) << endl;


		return 0;
	}

#endif // !FORREF


