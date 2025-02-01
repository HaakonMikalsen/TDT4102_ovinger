
#include "std_lib_facilities.h"
#include "test.h"
#include "utilities.h"
#include "mastermind.h"

int main()
{

	// Her kan du teste koden og funksjonene dine, 
	// Ingenting som skrives her blir automatisk rettet, du tester her for din egen del
	testCallByValue();
	testCallByReference();
	int a = 5;
	int b = 100;
	cout << a<< " : " << b<<endl;
	swapNumbers(a,b);
	cout << a<< " : " << b<<endl;

	Student student1 = {"Håkon","ELSYS",20};
	printStudent(student1);
	cout<<isInProgram(student1,"KYB")<<endl;
	cout<<isInProgram(student1,"ELSYS")<<endl;
	randomizeString(10,'G','A');
	cout << randomizeString(20,'X','A')<<endl;
	testString();
	// cout << readInputToString(5,'F','A')<<endl;
	cout << countChar("AoOAooABBCOCKKOKffoTT",'o')<<endl;
	playMastermind();
	return 0;
}
