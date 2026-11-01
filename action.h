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
		const string& getType() const;
		int getPos() const;
		const string& getOldT() const;
		const string& getNewT() const;
};

#endif