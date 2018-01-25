```
/*
@ProgramName: Algorithms Assignment 3
@Author: Jackson Tran
@Description: Most of this code was written during class. The assignment
is to create a method called orderedSert that will add integers to the list
while maintaining ascending order.
@Course: 3013 Agorithms
@Semester: Spring 2018
@Date: January 2018
*/

#include <iostream>
#include <ctime>

using namespace std;

//Create a container for our list data
struct node {
	int data;
	node* next;
};

/**
* Class: intLinkedList
* Purpose:
*     Implements a singly linked list that holds integers.
* Methods:
*     void  frontSert(int x)
*     node* find(int key)
*     node* remove(int key)
*     void  print()
*     void orderList()
*     void orderedSert(int data)
*/
class intLinkedList {
private:
	node* Head;
public:
	intLinkedList() {
		Head = NULL;
	}
	void frontSert(int x) {
		//empty list case
		if (!Head) {
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		else {//not empty list
			node* T = new node;
			T->data = x;
			T->next = Head;
			Head = T;
		}
	}

	node* Find(int key) {
		node* temp = Head;
		while (temp) {
			if (temp->data == key) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void Remove(int key) {
		node* result = Find(key);
		if (result) {
			node* temp = Head;
			while (temp->next != result) {
				temp = temp->next;
			}
			temp->next = result->next;
			delete result;
		}
	}

	void print() {
		node* p = Head;
		while (p) {
			cout << p->data << endl;
			p = p->next;
		}
	}


	/*
	* @FunctionName: orderList
	* @Description:
	*    "add a method called orderedSert that would add an integer to the list
	*	  while maintaining ascending order." Assuming the list will have be
	*	  ordered first, orderList will order the list.
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void orderList() {
		int size = 0;
		node* current;
		node* temp1;
		node* temp2 = Head;
		while (temp2 != NULL) {
			size++;
			temp2 = temp2->next;
		}

		for (int i = 0; i < size; i++) {
			current = Head;
			while (current->next != NULL) {
				if (current->data > current->next->data) {
					swap(current->data, current->next->data);
				}
				current = current->next;
			}
		}

	}

	/*
	* @FunctionName: orderedSert
	* @Description:
	*    "add a method called orderedSert that would add an integer to the list
	*	  while maintaining ascending order." As stated, orderedSert will add
	*	  integers to the list while maintaining ascending order.
	* @Params:
	*    int data - Integer to add to the list
	* @Returns:
	*    void
	*/
	void orderedSert(int data) {
		node* temp = new node;
		temp->data = data;
		temp->next = NULL;
		node* previous = Head;
		node* current = Head->next;
		if (Head == NULL) {
			Head = temp;
			return;
		}
		if (Head->data > data) {
			temp->next = Head;
			Head = temp;
		}

		while (previous && current) {
			if (data > previous->data && data < current->data) {
				temp->next = current;
				previous->next = temp;
			}
			previous = previous->next;
			current = current->next;
			if (previous->next == NULL && previous->data < data) {
				previous->next = temp;
			}
		}
	}

};

int main() {
	// seed random number generator
	srand(87345);

	// declare instance of intLinkedList turning
	// a class definition into an "object"
	intLinkedList mylist;

	//Load 10 random ints into our list
	for (int i = 0; i<10; i++) {
		mylist.frontSert(rand() % 100);
	}

	mylist.print();
	cout << endl;

	mylist.orderList();
	mylist.print();
	cout << endl;

	mylist.orderedSert(1);
	mylist.orderedSert(3);
	mylist.orderedSert(18);
	mylist.print();

	system("pause");
	return 0;
}
```
