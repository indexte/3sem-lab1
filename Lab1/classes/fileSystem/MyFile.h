#pragma once
#include<iostream>
#include<string>
#include<random>
#include<vector>

using std::vector;
using std::string;

class MyFile
{
protected:
	string name;
	size_t size;
	size_t creationTime;
	size_t modificationTime;

public:
	MyFile();

	//getters
	string getName() const;
	size_t getSize();
	size_t getCreationTime();
	size_t getModificationTime();
	string getFileFormat();

	//comparison operators
	bool operator>(MyFile toCompare);
	bool operator<(MyFile toCompare);
	bool operator==(MyFile toCompare);

	virtual void printInfo();

private:
	string fileFormat;
};