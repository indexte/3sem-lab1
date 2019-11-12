#pragma once
#include"Info.h"
#include"MyFile.h"
#include<list>
#include<iostream>

using std::list;

class MyFolder : public Info
{
protected:
	list<Info> folderInclude;

	void printInfo() override;
	void printFolderInclude();

	void setSize() override;
};