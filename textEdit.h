#ifndef textEdit_H
#define textEdit_H
#include <string>
#include "stack.h"
class Text{
	private:
		string content;
		Stack undoStack;
		Stack redoStack;
	public:
		Text();
		void insertText(string text, int position);
		void deleteText(int position, int length);
		void replaceText(string text, int position);
		void showDocument() const;
		void pushAction(const Action & action);
		void clearRedoStack(); 
};

#endif
