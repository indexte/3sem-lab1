#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include"MyFile.h"

using std::cout;
using std::endl;
using std::string;
using std::list;

//function for search file or folder by name
void findByName(string searchName, list<MyFile*> yourListOfObj) {

	//additional list to save found files with a suitable name
	list<MyFile*> foundWithName;

	//if the file has a suitable name, then copy it to a new "foundWithName" list
	copy_if(yourListOfObj.begin(), yourListOfObj.end(), back_inserter(foundWithName), [&searchName](const MyFile* file) {
		return file->getName() == searchName;
		});

	//print "foundWithName" list
	//if we found nothing, then print "nothing found"
	if (foundWithName.size() == 0) {
		cout << "Nothing found" << endl;
	}
	else {
		for (auto i : foundWithName) {
			i->printInfo();
		}
	}
}