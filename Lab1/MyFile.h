#pragma once
#include"Info.h"
#include<iostream>

class MyFile : public Info
{
protected:
	string fileFormat;
public:
	string getFileFormat();

	void printFileInfo();

	void setFileFormat(string fileFormat);
};