#include "MyFile.h"

using std::cout;
using std::endl;

string MyFile::getFileFormat()
{
	return fileFormat;
}

void MyFile::printFileInfo()
{
	cout << "Name: " << getName() << endl
		<< "Size: " << getSize() << endl
		<< "Creatin time: " << getCreationTime() << endl
		<< "Modification time: " << getModificationTime() << endl
		<< "Format: " << getFileFormat() << endl;
}

void MyFile::setFileFormat(string fileFormat)
{
	this->fileFormat = fileFormat;
}