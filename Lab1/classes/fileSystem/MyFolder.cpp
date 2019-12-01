#include "MyFolder.h"

using std::cout;
using std::endl;

MyFolder::MyFolder()
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	name = "DefaultFolderName";
	setFolderSize();
	creationTime = mersenne() % 9999;
	modificationTime = creationTime + mersenne() % 9999;
}

void MyFolder::printInfo()
{
	cout << "Name: " << getName() << endl
		<< "Size: " << getSize() << endl
		<< "Creatin time: " << getCreationTime() << endl
		<< "Modification time: " << getModificationTime() << endl;
}

void MyFolder::printFolderInclude()
{
	if (folderInclude.size() == 0) {
		cout << "Nothing found" << endl;
	}
	else {
		for (auto i : folderInclude) {
			cout << i.getName();
		}
	}
}

void MyFolder::setFolderSize()
{
	size = 0;
	for (auto i : folderInclude)
		size += i.getSize();
}