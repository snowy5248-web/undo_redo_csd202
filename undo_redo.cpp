#include <iostream>
#include "textEdit.h"
using namespace std;

bool Text::isUndoEmpty(){
	if(undoStack.size() == 0){
		return true;
	}
	return false;
}

bool Text::isRedoEmpty(){
	if(redoStack.size() == 0){
		return true;
	}
	return false;
}

void Text::undo(){
	if(isUndoEmpty()){
		cout << "Nothing to undo!" << endl;
		return;
	}
	Action action = undoStack.pop();
	
	content.replace(action.getPos(), action.getNewT().length(), action.getOldT());
	
	redoStack.push(action);
}

void Text::redo(){
	if(isRedoEmpty()){
		cout << "Nothing to Redo!" << endl;
		return;
	}
	Action action = redoStack.pop();

	content.replace(action.getPos(), action.getOldT().length(), action.getNewT());
	
	undoStack.push(action);
}