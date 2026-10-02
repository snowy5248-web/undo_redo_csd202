#include "Stack.h"

Node::Node(Action data){
	this->info = data;
	this->next = nullptr;
}

Stack::Stack(){
	top = nullptr;
}
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
	Node *newNode = new Node(x);
	if(isEmpty()){
		top = newNode;
		return;
	}
	newNode->next = top;
	top = newNode;
}
Action Stack::pop(){
	Node *target = top;
	Action val = top->info;
	top = top->next;
	delete target;
	return val;
}
Action Stack::peek(){
	return top->info;
}