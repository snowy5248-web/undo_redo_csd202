#ifndef action_H
#define action_H
#include <string>
using namespace std;

class Action{
	private:
		string type;
		int position;
		string oldText;
		string newText;
	public: 
		Action();
		Action(string ty, int pos, string oT, string nT);
		string getType();
		int getPos();
		string getOldT();
		string getNewT();
};

#endif