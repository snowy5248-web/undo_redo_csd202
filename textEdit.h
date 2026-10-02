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
		string showDocument(); //this is just a test, change it when you code mr 
};

#endif