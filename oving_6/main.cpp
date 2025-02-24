#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "FileUtils.h"
#include "bouncingBall.h"

int main()
{
	// Her kan du teste din kode ved å kalle på de ulike funksjonene du har implementert	
	// testCourseCatalog();
	// CourseCatalog catalog;
    // cout << catalog <<endl;

	// cout << "A"<<endl;

	// filesystem::path saveFile("coursesFile.txt");
	// catalog.loadFromFile(saveFile);
	// cout << catalog << endl;

	// filesystem::path fileName{"myFile.txt"};
	// writeUserInputToFile(fileName);
	// addLineNumbers(fileName);

	bouncingBall();
	return 0;
}