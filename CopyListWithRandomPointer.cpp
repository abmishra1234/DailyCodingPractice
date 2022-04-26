/*
	Copy List with Random Pointer
	There are multiple approach to this 
	
	Approach 01 - Based on mapping table for origional and copied nodes


*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<unordered_map>

struct Node {
	int data;
	Node* next;
	Node* random;

	Node() {
		random = next = nullptr;
	}
};

struct CopyList {
	/*
		This below method is suppose to be for adding the node into the linked list.
		So in below code we only assigned the value of next pointer in chain.
		what we have not done yet that assignment of random pointer  
	*/
	void addNode(Node** head, int data) {
		Node* np = new Node();
		np->data = data;

		if (*head == nullptr) {
			*head = np;
		}
		else
		{
			np->next = *head;
			*head = np;
		}
	}
	/* Print method for printing the list data & random data*/
	void print(Node* head) {
		Node* start = head;
		while (start) {
			cout << start->data << " | Random->data = " << start->random->data << endl;
			start = start->next;
		}
	}
	
	/*
		Let's create one mapping between the two nodes ( origional vs new corresponding node )

		Step 01:
		1. Iterate the origional linked list 

		
	
	*/
	void Clone_Approach01(Node* head, Node** out_head, Node** out_tail) {
		unordered_map<Node*, Node*> nodemapping;
		
		Node* start = head;
		Node* curr = nullptr;

		while (start) {
			curr = new Node();
			curr->data = start->data;
			if (*out_head == nullptr) {
				*out_head = *out_tail = curr;
			}
			else
			{
				(*out_tail)->next = curr;
				(*out_tail) = curr;
			}
			Node* bkp = start;
			start = start->next;
//			bkp->next = bkp->random = nullptr;
			nodemapping.insert(make_pair(bkp, curr));
		}

		// So another loop you have to write for setting the random pointer
		start = head;
		curr = nullptr;
		Node* copy_curr = *out_head;
		while (start) {
			copy_curr->random = nodemapping.find(start->random)->second;
			start = start->next;
		}
	}

	void setRandoms(Node** head) {
		// 1 , random pointer points 3
		(*head)->random = (*head)->next->next;

		// 2's random points to 1
		(*head)->next->random = (*head);

		// 3's random points to 5
		(*head)->next->next->random = (*head)->next->next->next->next;

		// 4's random points to 3
		(*head)->next->next->next->random = (*head)->next->next;

		// 5's random points to 2
		(*head)->next->next->next->next->random = (*head)->next;
	}

};

// Driver code for the Copy List problem
int main() {

	CopyList cl;
	
	Node* head = nullptr;
	cl.addNode(&head, 5);
	cl.addNode(&head, 4);
	cl.addNode(&head, 3);
	cl.addNode(&head, 2);
	cl.addNode(&head, 1);

	// Now let me see how we will set the random pointer in driver code
	cl.setRandoms(&head);

	// check this before cloning the linked list
	cl.print(head);

	// Now let's write the logic for cloning this linklist


	Node* out_head = nullptr;
	Node* out_tail = nullptr;

	cl.Clone_Approach01(head, &out_head, &out_tail);
	// This is the print of element from clone
	cl.print(out_head);


	return 0;
}





#endif // !FORREF

