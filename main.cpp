#include <iostream>
#include "textEdit.h"
using namespace std;

int main() {
	Text t;
	
	cout << "--- Test undo/redo khi chua co gi ---" << endl;
	t.undo();
	t.redo();
	
	cout << "--- Test insert ---" << endl;
	t.insertText("Mr beast", 0);
	t.showDocument();
	t.insertText("Mr beast", 100);   // vi tri khong hop le
	t.showDocument();
	
	cout << "--- Test delete ---" << endl;
	t.deleteText(1, 3);
	t.showDocument();
	t.deleteText(100, 3);            // vi tri khong hop le
	t.deleteText(0, 100);            // do dai khong hop le
	t.showDocument();
	
	cout << "--- Test replace ---" << endl;
	t.replaceText("kkk", 0);
	t.showDocument();
	t.replaceText("aaaaaaaa", 0);    // do dai khong hop le
	t.showDocument();
	
	cout << "--- Test undo (3 lan + 1 lan thua) ---" << endl;
	t.undo();
	t.showDocument();
	t.undo();
	t.showDocument();
	t.undo();
	t.showDocument();
	t.undo();                        // Nothing to undo!
	
	cout << "--- Test redo (3 lan + 1 lan thua) ---" << endl;
	t.redo();
	t.showDocument();
	t.redo();
	t.showDocument();
	t.redo();
	t.showDocument();
	t.redo();                        // Nothing to Redo!
	
	cout << "--- Test: sua moi thi redo bi xoa ---" << endl;
	t.undo();
	t.insertText("!", 0);
	t.redo();                        // Nothing to Redo!
	t.showDocument();
	
	return 0;
}