//============================================================================
// Name        : lab5.cpp
// Author      : Nick Gaulke
// Version     :
// Copyright   : Your copyright notice
// Description : lab5 in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout << "Enter file name to read: ";
	string file;
	cin >> file;
	ifstream stream (file.c_str());
	if(stream.is_open()) {
		cout << "Enter word to search: ";
		string search;
		cin >> search;
		string line;
		int lineNumber = 1;
		while(getline(stream, line)) {
			if(line.find(search) != string::npos)
				cout << search << " found at line " << lineNumber << endl;
			lineNumber++;
		}
		stream.close();
	}
	else {
		cout << "unable to open text.txt";
	}
	return 0;
}
