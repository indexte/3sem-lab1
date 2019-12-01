#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include"classes/fileSystem/MyFile.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

//function for search file or folder by name
void findByName(string searchName, vector<MyFile*> yourListOfObj) {

	//additional list to save found files with a suitable name
	vector<MyFile*> foundWithName;

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