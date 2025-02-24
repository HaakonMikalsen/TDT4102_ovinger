#include "CourseCatalog.h"

// BEGIN: 3a
void CourseCatalog::addCourse(const string& key, const string& value) {
    courses.insert({key, value});
}
// END: 3a

// BEGIN: 3b
void CourseCatalog::removeCourse(const string& key) {
    courses.erase(key);
}
// END: 3b

// BEGIN: 3c
string CourseCatalog::getCourse(const string& key) const {
    return courses.at(key);
}
// END: 3c

// BEGIN: 3d
ostream& operator<<(ostream& os, const CourseCatalog& cc) {
    for (const auto& c : cc.courses) {
        os << c.first << ":" << c.second << endl;
    }
    return os;
}
// END: 3d

// BEGIN: 3e
void testCourseCatalog() {
    CourseCatalog catalog;
    catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    catalog.addCourse("TDT4102","Prosedyre- og objektorientert programmering ");
    catalog.addCourse("TMA4100","Matematikk 1");
    catalog.addCourse("Hei","A");
    catalog.removeCourse("Hei");
    cout << catalog <<endl;
}
// END: 3e

// BEGIN: 3g
void CourseCatalog::saveToFile(const std::string& filename) const {
    ofstream writeFile{filename};
    for (const auto& c : courses){
        writeFile << c.first << ":"<<c.second<<endl;
    }
}
// END: 3g

// BEGIN: 3h
void CourseCatalog::loadFromFile(const std::string& filename){
    ifstream saveFile{filename};
    string nextLine;
    if (!saveFile){
        cout << "no save file"<<endl;
        return;
    }
    while(getline(saveFile,nextLine)){
        int pos = 0;
        string key = "";
        string val = "";
        for(const auto& ch : nextLine){
            if (ch == ':'){
                pos = 1;
            }
            if(pos==1){
                val.push_back(ch);
            }
            else{
                key.push_back(ch);
            }
        }
        addCourse(key,val);
    }
}
// END: 3h