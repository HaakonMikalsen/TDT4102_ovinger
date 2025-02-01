#include "utilities.h"

#include <random>

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++)
        startValue += increment;

    return startValue;
}

// BEGIN: 1d
void incrementByValueNumTimesRef(int& startValue, int increment, int numtimes) {
    for (int i = 0; i < numtimes; i++) {
        startValue += increment;
    }
}
// END: 1d

// BEGIN: 1e
void swapNumbers(int& num1, int& num2) {
    int temp = num2;
    num2 = num1;
    num1 = temp;
}
// END: 1e

// BEGIN: 2b
void printStudent(Student stud) {
    cout << "Name: " << stud.name << endl
         << "Age: " << stud.age << endl
         << "Study program: " << stud.studyProgram << endl;
}
// END: 2b

// BEGIN: 2c
bool isInProgram(Student stud, string progamName) {
    if (stud.studyProgram == progamName) {
        return true;
    }
    return false;
}
// END: 2c

// BEGIN: 3a
string randomizeString(int letterCOunt, char uppperLimit, char lowerLimit) {
    string randomString = "";

    // Create a random device and generator
    random_device rd;
    default_random_engine generator(rd());

    // Define the range for the random number
    uniform_int_distribution<int> distribution(lowerLimit, uppperLimit);
    for (int i = 0; i < letterCOunt; i++) {
        // cout << distribution(generator)<<endl;
        int randomNum = distribution(generator);
        char randomCh = static_cast<char>(randomNum);
        randomString += randomCh;
    }
    return randomString;
}
// END: 3a

// BEGIN: 3c
string readInputToString(int n, char upperLimit, char lowerLimit) {
    string returnString;
    while (true) {
        cout << "Write a string that is " << n << "letters long" << "and all the letters are between " << lowerLimit << " and " << upperLimit << endl;
        cin >> returnString;

        for (int i = 0; i < returnString.length(); i++) {
            returnString.at(i) = toupper(returnString.at(i));
        }

        if (returnString.length() == n) {
            int i = 0;
            while (true) {
                if (static_cast<int>(returnString.at(i)) < static_cast<int>(lowerLimit)) {
                    break;
                }
                if (static_cast<int>(returnString.at(i)) > static_cast<int>(upperLimit)) {
                    break;
                }

                i++;
                if (i == n) {
                    return returnString;
                }
            }
        }
		cout << "try again"<<endl;
    }
}
// END: 3c

// BEGIN: 3d
int countChar(string text, char letter){
	int sum = 0;
	for ( int i = 0; i<text.length();i++){
		sum += (text.at(i)==letter);
	}
	return sum;
}
// END: 3d
