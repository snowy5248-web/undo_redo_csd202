#include <iostream>
#include <limits>
#include <string>
#include "textEdit.h"

using namespace std;

// Read an int; returns false (and cleans up) on bad input.
bool readInt(int &out) {
    cin >> out;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please enter a number!\n";
        return false;
    }
    // discard the rest of the line, including the '\n'
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

int main() {
    Text t;
    int choice = -1;
    string text, filename;
    int position, length;

    do {
        cout << "\n===== UNDO/REDO TEXT EDITOR =====\n"
                "1. Insert text (position = 0 for first input)\n"
                "2. Delete text\n"
                "3. Replace text\n"
                "4. Undo\n"
                "5. Redo\n"
                "6. Show text\n"
                "7. Save to file\n"
                "8. Load from file\n"
                "0. Exit\n"
                "Choose an option: ";

        if (!readInt(choice)) { choice = -1; continue; }  // don't let choice become 0

        switch (choice) {
            case 1:
                cout << "Enter text to insert: ";
                getline(cin, text);
                cout << "Enter position: ";
                if (!readInt(position)) break;
                t.insertText(text, position);
                break;

            case 2:
                cout << "Enter position: ";
                if (!readInt(position)) break;
                cout << "Enter length: ";
                if (!readInt(length)) break;
                t.deleteText(position, length);
                break;

            case 3:
                cout << "Enter replacement text: ";
                getline(cin, text);
                cout << "Enter position: ";
                if (!readInt(position)) break;
                cout << "Enter length: ";
                if (!readInt(length)) break;
                t.replaceText(text, position, length);
                break;

            case 4: t.undo(); break;
            case 5: t.redo(); break;
            case 6: t.showDocument(); break;

//            case 7:
//                cout << "Enter filename to save: ";
//                getline(cin, filename);
//                t.saveDocument(filename);
//                break;
//
//            case 8:
//                cout << "Enter filename to load: ";
//                getline(cin, filename);
//                t.loadDocument(filename);
//                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option, try again.\n";
        }
    } while (choice != 0);

    return 0;
}