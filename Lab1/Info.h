#pragma once
#include<string>
#include<random>

using std::string;

class Info
{
protected:
	string name;
	size_t size;
	size_t creationTime;
	size_t modificationTime;

public:

	//getters
	string getName();
	size_t getSize();
	size_t getCreationTime();
	size_t getModificationTime();

	//setters
	void setName(string name);
	virtual void setSize(size_t size);
	void setCreationTime(size_t creationTime);
	void setModificationTime(size_t modificationTime);

	//comparison operators
	bool operator>(Info toCompare);
	bool operator<(Info toCompare);
	bool operator==(Info toCompare);

};