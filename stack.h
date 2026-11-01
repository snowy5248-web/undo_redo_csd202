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
		~Stack();
		Stack(const Stack&) = delete;
		Stack& operator=(const Stack&) = delete;
		void clear();
		bool isEmpty();
		int size();
		void push(Action x);
		Action pop();
		Action peek();
};

#endif