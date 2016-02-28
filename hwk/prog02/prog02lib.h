#ifndef _prog02lib
#define _prog02lib

/// <summary>
/// returns true if the word word is found in the dictionary
/// file named dict. When word_search is called is must open
/// the dict file using a local ifstream variable, and it must
/// close the file before it returns. The function returns
/// false if the word is not found or if the dictionary file
/// is not valid.
/// </summary>
bool word_search(string word, string dict);

/// <summary>
/// prints the error message
/// "word is spelled wrong, on line: line"
/// to the specified stream. The function returns true if the
/// message is printed successfully, false if there is a problem
/// (if, for example, out is an ofstream object not associated
/// with an open file.)
/// </summary>
bool bad_word(string word, int line, ostream& out);

#endif
