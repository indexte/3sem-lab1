#include "MyFile.h"

using std::cout;
using std::endl;

MyFile::MyFile()
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	name = "DefaultFileName";
	size = mersenne()%9999;
	creationTime = mersenne()%9999;
	modificationTime = creationTime + mersenne()%9999;
	fileFormat = ".defaultFormat";
	
}

//getters
string MyFile::getName() const {
	return name;
}
size_t MyFile::getSize() {
	return size;
}
size_t MyFile::getCreationTime() {
	return creationTime;
}
size_t MyFile::getModificationTime() {
	return modificationTime;
}

//comparison operators
bool MyFile::operator>(MyFile& toCompare) {
	return modificationTime > toCompare.getModificationTime();
}
bool MyFile::operator<(MyFile& toCompare) {
	return modificationTime < toCompare.getModificationTime();
}
bool MyFile::operator<=(MyFile& toCompare)
{
	return modificationTime <= toCompare.getModificationTime();
}
bool MyFile::operator>=(MyFile& toCompare)
{
	return modificationTime >= toCompare.getModificationTime();
}
bool MyFile::operator==(MyFile& toCompare) {
	return modificationTime == toCompare.getModificationTime();
}

string MyFile::getFileFormat()
{
	return fileFormat;
}

void MyFile::printInfo()
{
	cout << "Name: " << getName() << endl
		<< "Size: " << getSize() << endl
		<< "Creatin time: " << getCreationTime() << endl
		<< "Modification time: " << getModificationTime() << endl
		<< "Format: " << getFileFormat() << endl;
}