// RemoveNthNodeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

class RemoveNthNodeFromEnd {
public:

	template<class T>
	static Node<T>* Remove(Node<T>* head, int n) {
		if (head == nullptr) return nullptr;

		Node<T>* first = nullptr;
		Node<T>* second = head;
		int count = 1;

		while (++count <= n) second = second->next;

		while (second->next != nullptr) {
			first = (first == nullptr) ? head : first->next;
			second = second->next;
		}

		if (first == nullptr) head = head->next;
		else first->next = first->next->next;

		return head;
	}
};
	
class SwapAlternateNodes {
public:
	template<class T>
	static Node<T>* swap (Node<T>* curNode) {

		Node<T>* first = curNode;
		if (first == nullptr) return nullptr;

		Node<T>* second = first->next;
		if (second == nullptr) return first;
		
		first->next = swap(second->next);
		second->next = first;

		return second;

			
	};
};


//10 -> 20 -> 30 -> 40 -> 50 ->o
//				    2

int main()
{
	{
		LinkedList<int> list;
		list.addNode(10);
		list.addNode(20);
		list.addNode(30);
		list.addNode(40);
		list.addNode(50);
		list.addNode(60);

		//list.print();

		//list.head = RemoveNthNodeFromEnd::Remove(list.head, 7);

		list.print();

		list.head = SwapAlternateNodes::swap(list.head);
		
		list.print();
	}
}

