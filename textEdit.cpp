#include <iostream>
#include "textEdit.h"
using namespace std;
Text::Text(){
	this->content = "";
}
void Text::insertText(string text, int position){
	if(text.empty()){
	 cout << "Empty text" << endl;
		return;
	}
	if(position < 0 || position > (int)content.length()){
		cout << "Invalid position!" << endl;
		return;
	}	
	content.insert(position, text);
	Action ins("Insert", position, "", text);
	undoStack.push(std::move(ins));
	redoStack.clear();
	
}
void Text::deleteText(int position, int length){
	if(content.length() == 0){
		cout << "No text!" << endl;
		return;
	}
	if(position < 0 || position > (int)content.length()){
		cout << "Invalid position!" << endl;
		return;
	}
	if(length <= 0 || length > (int)content.length() - position){
		cout << "Invalid length!" << endl;
		return;
	}
	string oldText = content.substr(position, length);
	content.erase(position, length);
	
	Action del("Delete", position, oldText, "");
	undoStack.push(std::move(del));
	redoStack.clear();
	
}
	
void Text::replaceText(string text, int position, int length){
    if(content.length() == 0){
        cout << "No text!" << endl;
        return;
    }
	if(length == 0 && text.empty()){
    	cout << "Nothing to replace!" << endl;
    	return;
	} 
    if(position < 0 || position > (int)content.length()){
        cout << "Invalid position!" << endl;
        return;
    }
    if(length < 0 || length > (int)content.length() - position){
        cout << "Invalid length!" << endl;
        return;
    }

    string oldText = content.substr(position, length);
    content.replace(position, length, text);

    Action rep("Replace", position, oldText, text);
    undoStack.push(std::move(rep));
    redoStack.clear();
    
}

void Text::showDocument() const{
	if(content.empty()){
		cout<<"Document is empty\n";
		return;
	}
	cout<<"========== DOCUMENT ==========\n"
		<<content<<"\n"
		<<"Length: "<<content.size()
	    <<"\n";
}

void Text::pushAction(const Action & action){
	undoStack.push(action);
	clearRedoStack();
}

void Text::clearRedoStack(){
	if(redoStack.isEmpty()){
		return;
	}
	redoStack.clear();
	
	cout<<"Redo stack cleared\n";
}

	
