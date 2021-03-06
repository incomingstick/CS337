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
    	string line;
    	int lineNumber = 0;
    	ofstream out ("out.txt");
    	while(getline(stream, line)) {
    		istringstream ln(line);
    		while(ln >> word) {
    			if(!checker.word_search(word, wordlst))
    				if(!checker.bad_word(word, lineNumber, out))
    					cout << "Stream to out.txt unexpectedly closed.";
    		}
    		lineNumber++;
    	}
    	cout << "it worked??" << endl;
    	out.close();
    	stream.close();
    }
    else {
    	cout << "Unable to open " << file << endl;
    }
    return 0;
}
