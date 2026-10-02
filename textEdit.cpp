#include <iostream>
#include "textEdit.h"
using namespace std;
Text::Text(){
	this->content = "";
}
void Text::insertText(string text, int position){
	if(position < 0 || position > content.length()){
		cout << "Invalid position!" << endl;
		return;
	}
	content.insert(position, text);
	Action ins("Insert", position, "", text);
	undoStack.push(ins);
	while(!redoStack.isEmpty()){
		redoStack.pop();
	}
}
void Text::deleteText(int position, int length){
	if(position < 0 || position > content.length()){
		cout << "Invalid position!" << endl;
		return;
	}
	if(position + length > content.length()){
		cout << "Invalid length!" << endl;
		return;
	}
	string oldText = content.substr(position, length);
	content.erase(position, length);
	
	Action del("Delete", position, oldText, "");
	undoStack.push(del);
	while(!redoStack.isEmpty()){
		redoStack.pop();
	}
}
	
void Text::replaceText(string text, int position){
	if(position < 0 || position > content.length()){
		cout << "Invalid position!" << endl;
		return;
	}
	if(position + text.length() > content.length()){
		cout << "Invalid length!" << endl;
		return;
	}
	string oldText = content.substr(position, text.length());
	content.replace(position, text.length(), text);
	
	Action rep("Replace", position, oldText, text);
	undoStack.push(rep);
	while(!redoStack.isEmpty()){
		redoStack.pop();
	}
}
string Text::showDocument(){
	return content;
}
	