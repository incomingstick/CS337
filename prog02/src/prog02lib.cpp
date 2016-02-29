#include "prog02lib.h"

bool SpellCheck::word_search(string word, string dict) {
	// open stream to read dictionary wordlist
    ifstream stream (dict.c_str());
    if(stream.is_open()) {
    	string line;
    	while(getline(stream, line))
    		if(line.find(word) != string::npos)
    			return true;
    	stream.close();
    }
    return false;
}

bool SpellCheck::bad_word(string word, int line, ofstream& out) {
    //TODO
    cout << word << " is spelled wrong, on line: " << line << endl;
    return false;
}
