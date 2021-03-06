#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 2)
		return 0;
	else if(argc == 2) {
		cout << argv[1] << endl;
		return 0;
	}
	char* temp;
	for(int i = 1; i < argc; i++) {
		for(int j = i; j > 0 && strcmp(argv[j], argv[j-1]) < 0; j--) {
			temp = argv[j];
			argv[j] = argv[j-1];
			argv[j-1] = temp;
		}
	}
	for(int i = 1; i < argc; i++) {
		cout << argv[i] << endl;
	}
}
