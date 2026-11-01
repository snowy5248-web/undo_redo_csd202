// FILE MOI: showHistory, saveDocument, loadDocument
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <utility>
#include "textEdit.h"
using namespace std;

static void showOneStack(string title, const Stack &s){
	cout << "\n" << title << ":" << endl;
	const Node* n = s.topNode();
	if(n == nullptr){
		cout << "(empty)" << endl;
		return;
	}

	int count = 0;
	for(; n != nullptr; n = n->next){
		count++;
		cout << count << ". " << n->info.getType()
		     << " | pos=" << n->info.getPos()
		     << " | old=\"" << n->info.getOldT() << "\""
		     << " | new=\"" << n->info.getNewT() << "\"" << endl;

		if(count % 10 == 0 && n->next != nullptr){
			cout << "Press Enter to see next 10, or type q to stop: ";
			string cmd;
			if(!getline(cin, cmd) || cmd == "q"){
				break;
			}
		}
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
	if(!file){
		cout << "Error: failed to write file" << endl;
		return false;
	}
	cout << "Saved successfully" << endl;
	return true;
}

bool Text::loadDocument(const string& filename){
	ifstream file(filename.c_str());
	if(!file.is_open()){
		cout << "Error: file not found" << endl;
		return false;
	}
	// doc toan bo file vao 1 chuoi
	string tempContent((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	file.close();

	content = std::move(tempContent);
	undoStack.clear();
	redoStack.clear();

	cout << "Loaded successfully" << endl;
	return true;
}