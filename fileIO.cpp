#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include "textEdit.h"
using namespace std;

static void showOneStack(string title, Stack &s){
	cout << "\n" << title << ":" << endl;
	if(s.isEmpty()){
		cout << "(empty)" << endl;
		return;
	}

	Stack temp;
	int count = 0;

	while(!s.isEmpty()){
		Action a = s.pop();
		count++;
		cout << count << ". " << a.getType()
		     << " | pos=" << a.getPos()
		     << " | old=\"" << a.getOldT() << "\""
		     << " | new=\"" << a.getNewT() << "\"" << endl;
		temp.push(a);

		if(count % 10 == 0 && !s.isEmpty()){
			cout << "Press Enter to see next 10, or type q to stop: ";
			string cmd;
			if(!getline(cin, cmd) || cmd == "q"){
				break;
			}
		}
	}

	while(!temp.isEmpty()){
		s.push(temp.pop());
	}
}

void Text::showHistory(){
	showOneStack("UNDO STACK", undoStack);
	showOneStack("REDO STACK", redoStack);
}

bool Text::saveDocument(const string& filename){
	ofstream file(filename.c_str());
	if(!file.is_open()){
		cout << "Error: cannot open file" << endl;
		return false;
	}
	file << content;
	file.close();
	cout << "Saved successfully" << endl;
	return true;
}

bool Text::loadDocument(const string& filename){
	ifstream file(filename.c_str());
	if(!file.is_open()){ 
		cout << "Error: file not found" << endl;
		return false;
	}
	string tempContent((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	file.close();

	content = tempContent;
	while(!undoStack.isEmpty()) undoStack.pop();
	while(!redoStack.isEmpty()) redoStack.pop();

	cout << "Loaded successfully" << endl;
	return true;
}