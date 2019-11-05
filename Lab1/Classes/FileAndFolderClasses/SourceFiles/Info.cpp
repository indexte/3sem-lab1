#include "Info.h"

//getters
string Info::getName() {
	return name;
}
size_t Info::getSize() {
	return size;
}
size_t Info::getCreationTime() {
	return creationTime;
}
size_t Info::getModificationTime() {
	return modificationTime;
}

//setters
void Info::setName(string fileName) {
	this->name = fileName;
}
void Info::setSize(size_t fileSize) {
	this->size = fileSize;
}
void Info::setCreationTime(size_t fileCreationTime) {
	this->creationTime = fileCreationTime;
}
void Info::setModificationTime(size_t fileModificationTime) {
	this->modificationTime = fileModificationTime;
}

//comparison operators
bool Info::operator>(Info toCompare) {
	if (this->getModificationTime() != toCompare.getModificationTime())
		return this->getModificationTime() > toCompare.getModificationTime();
}
bool Info::operator<(Info toCompare) {
	if (this->getModificationTime() != toCompare.getModificationTime())
		return this->getModificationTime() < toCompare.getModificationTime();
}
bool Info::operator==(Info toCompare) {
	return this->getModificationTime() == toCompare.getModificationTime();
}