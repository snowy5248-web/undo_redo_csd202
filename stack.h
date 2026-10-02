#ifndef stack_H
#define stack_H
#include "action.h"
class Node{
	public:
		Action info;
		Node *next;
		Node(Action data);
};

class Stack{
	private:
		Node *top;
	public:
		Stack();
		bool isEmpty();
		int size();
		void push(Action x);
		Action pop();
		Action peek();
};

#endif