/*
 * main.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: nfgaulke
 */
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <unistd.h>
#include <string>
#include <sstream>

using namespace std;

string get_perm(int perm);

int main(int argc, char* argv[]) {
	if(argc <= 1) return 0;
	for(int i = 1; i < argc; i++) {
		stringstream ss;
		string output;
		// get stats of the file
		struct stat fileInfo;

		// checks if file can be opened
		if(stat(argv[i], &fileInfo) == -1) {
			output += "Error: ";
			output += argv[i];
			output += " not found.\n";
			write(1, output.c_str(), output.length());
			continue;
		}

		// this will be used to get the user name
		struct passwd passInfo;
		passInfo = *getpwuid(fileInfo.st_uid);

		// checks if file is file or dir
		if(S_ISREG(fileInfo.st_mode)) {
			output += "-";
			output += get_perm((fileInfo.st_mode % 01000) / 0100);
			output += get_perm((fileInfo.st_mode % 01000) / 010);
			output += get_perm(fileInfo.st_mode % 01000) + " ";
			output += argv[i];
			output += " ";
			output += passInfo.pw_name;
			output += " ";
			string size;
			ss << fileInfo.st_size;
			ss >> size;
			output += size;
		}
		else {
			output += "d";
			output += get_perm((fileInfo.st_mode % 01000) / 0100);
			output += get_perm((fileInfo.st_mode % 01000) / 010);
			output += get_perm(fileInfo.st_mode % 01000) + " ";
			output += argv[i];
			output += " ";
			output += passInfo.pw_name;
			output += " ";

			// gets contents of dir and counts them
			DIR* dir;
			dir = opendir(argv[i]);
			int files = 0;
			while(readdir(dir))
				files++;

			string size;
			ss << files;
			ss >> size;
			output += size;
		}
		output += "\n";
		write(1, output.c_str(), output.length());
	}
	return 0;
}

string get_perm(int perm) {
	string ret;
	switch(perm % 010) {
	case 7:
		ret = "rwx";
		break;
	case 6:
		ret = "rw-";
		break;
	case 5:
		ret = "r-x";
		break;
	case 4:
		ret = "r--";
		break;
	case 3:
		ret = "-wx";
		break;
	case 2:
		ret = "-w-";
		break;
	case 1:
		ret = "--x";
		break;
	case 0:
		ret = "---";
		break;
	default:
		ret = "perm out of range";
	}
	return ret;
}
