#include <iostream>
#include "textEdit.h"
using namespace std;

bool Text::isUndoEmpty(){
	return undoStack.isEmpty();
}

bool Text::isRedoEmpty(){
	return redoStack.isEmpty();
}

void Text::undo(){
	if(isUndoEmpty()){
		cout << "Nothing to undo!" << endl;
		return;
	}
	Action action = undoStack.pop();
	
	content.replace(action.getPos(), action.getNewT().length(), action.getOldT());
	
	redoStack.push(std::move(action));
}

void Text::redo(){
	if(isRedoEmpty()){
		cout << "Nothing to Redo!" << endl;
		return;
	}
	Action action = redoStack.pop();

	content.replace(action.getPos(), action.getOldT().length(), action.getNewT());
	
	undoStack.push(std::move(action));
}