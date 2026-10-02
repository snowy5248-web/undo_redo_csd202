#include <iostream>
#include "action.h"
using namespace std;
	Action::Action(){
		this->type = "";
		this->position = -1;
		this->oldText = "";
		this->newText = ""; 
	}
	Action::Action(string ty, int pos, string oT, string nT){
		this->type = ty;
		this->position = pos;
		this->oldText = oT;
		this->newText = nT;
	}	
	string Action::getType(){
		return type;
	}
	int Action::getPos(){
		return position;
	}
	string Action::getOldT(){
		return oldText;
	}
	string Action::getNewT(){
		return newText;
	}