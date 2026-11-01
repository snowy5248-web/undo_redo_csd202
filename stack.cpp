#include "stack.h"
#include <utility>

Node::Node(Action data) : info(std::move(data)), next(nullptr) {} //move(data) casts the data straight to info instead of copying

Stack::Stack(){
	top = nullptr;
}
void Stack::clear() {
    while (top) { Node* t = top; top = top->next; delete t; }
}
Stack::~Stack() { clear(); }
bool Stack::isEmpty(){
	return top == nullptr;
}
int Stack::size(){
	int count = 0;
	Node *temp = top;
	while(temp != nullptr){
		count++;
		temp = temp->next;
	}
	return count;
}
void Stack::push(Action x){
	Node *newNode = new Node(std::move(x));
	newNode->next = top;      //so that it works for empty case
	top = newNode;
}
Action Stack::pop(){
	Node *target = top;
	Action val = std::move(top->info);
	top = top->next;
	delete target;
	return val;
}
Action Stack::peek(){
	return top->info;
}