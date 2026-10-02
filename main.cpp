#include <iostream>
#include "textEdit.h"
using namespace std;

int main() {
	Text t;
	t.insertText("Mr beast", 0);
	cout << t.showDocument() << endl;
	t.insertText("Mr beast", 100);
	cout << t.showDocument() << endl;
	t.deleteText(1, 3);
	cout << t.showDocument() << endl;
	t.deleteText(100, 3);
	cout << t.showDocument() << endl;
	t.deleteText(0, 100);
	t.replaceText("kkk", 0);
	cout << t.showDocument() << endl;
	t.replaceText("aaaaaaaa", 0);
	cout << t.showDocument() << endl;
	
	return 0;
}