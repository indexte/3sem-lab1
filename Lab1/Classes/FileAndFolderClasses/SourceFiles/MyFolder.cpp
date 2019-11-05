#include "MyFolder.h"

using std::cout;
using std::endl;

void MyFolder::printInfo()
{
	cout << "Name: " << getName() << endl
		<< "Size: " << getSize() << endl
		<< "Creatin time: " << getCreationTime() << endl
		<< "Modification time: " << getModificationTime() << endl;
}

void MyFolder::printFolderInclude()
{
	for (auto i : folderInclude)
		cout << i.getName();
}

void MyFolder::setSize()
{
	for (auto i : folderInclude)
		size += i.getSize();
}