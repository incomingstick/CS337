#include "prog02.h"
#include "prog02lib.h"

int main() {
    // gets file to check
    cout << "Enter a file to spell check: ";
    string file;
    cin >> file;

    // gets wordlist dictionary to check against
    cout << "Enter a dictionary to use: ";
    string wordlst;
    cin >> wordlst;

    // open stream to read file
    ifstream stream (file.c_str());
    string word;

    if(stream.is_open()) {
    	SpellCheck checker;
    	while(stream >> word) {
    		if(!checker.word_search(word, wordlst)) {
    			//ofstream out();
    			//checker.bad_word(word, 0, out&);
    		}
    	}
    	stream.close();
    }

    return 0;
}