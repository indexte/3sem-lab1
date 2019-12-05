//Inheritance class for description folder

#pragma once
#include<iostream>
#include<list>
#include"MyFile.h"

using std::list;

class MyFolder : public MyFile
{
private:
	list<MyFile> folderInclude;

	void setFolderSize();
public:
	MyFolder();

	void printInfo() override;
	void printFolderInclude();
};