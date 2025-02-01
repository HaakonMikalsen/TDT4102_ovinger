#include "test.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment
         << " iterations: " << iterations << " result: " << result << '\n';
}

void testCallByReference() {
    // BEGIN: 1d

    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0: " << v0 << " increment: " << increment
         << " iterations: " << iterations << " result: " ;
    incrementByValueNumTimesRef(v0, increment, iterations);
	cout << v0 << '\n';

    // END: 1d
}

void testString() {
    // 3b OG 3e gjøres inne i her
    // BEGIN: 3e
    string grades = randomizeString(10,'F','A');
    cout <<grades<<endl;
    vector<int> gradeCount;
    float avarage = 0;
    for( int i = 0;i<= 'F'-'A';i++){
        gradeCount.push_back(countChar(grades,i+'A'));
        avarage+=gradeCount.at(i)*('F'-'A'-i+1);
    }
    avarage /= grades.length();
    cout << avarage<<endl;


    // END: 3e
}