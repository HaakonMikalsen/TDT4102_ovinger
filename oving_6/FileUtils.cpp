#include "FileUtils.h"

#include "std_lib_facilities.h"

void writeUserInputToFile(const std::string &path) {
    // BEGIN: 1a
    string input = "";
    ofstream outputStream{path};
    while (true) {
        cin >> input;
        if (input == "quit") {
            break;
        }
        outputStream << input << endl;
    }
    // END: 1a
}

void addLineNumbers(const std::string &filename) {
    // BEGIN: 1b
    string newFileName = filename + ".linum";
    ifstream readFile{filename};
    if (!readFile) {  // Sjekker om strømmen ble åpnet
        std::cout << "Could not open file" << std::endl;
		return;
    }
	ofstream writeFile{newFileName};
	string nextLine;	
	int c= 1;
	while(getline(readFile, nextLine)){
		writeFile << c<<":"<<nextLine<<endl;
		c++;
	}


    // END: 1b
}