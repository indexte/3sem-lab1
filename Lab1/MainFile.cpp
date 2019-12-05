/**
	\file Mainfile.cpp

	\brief Lab 1 - Linked list and STL list with custom filesystem (Files and folders)

	\author Lypynets Yaroslav K-29
*/
#include<vector>
#include<list>
#include<algorithm>
#include"classes/fileSystem/MyFile.h"
#include"classes/fileSystem/MyFolder.h"
#include"classes/List.h"

using std::vector;
using std::list;
using std::cout;
using std::endl;

void findByName(string searchName, vector<MyFile*> yourListOfObj);

int main() {

	std::random_device rd;
	std::mt19937 mersenne(rd());


	//singly linked list test for int
	cout << "singly linked list test for int---------------------------" << endl << endl;

	List<int> mlstInt;

	for (auto i = 0; i < 5; i++)
		mlstInt.pushBack(mersenne()%100);

	//test linked list insertion sort for int
	mlstInt.insertionSort();

	//print mlstInt
	for (auto i = 0; i < mlstInt.getsize(); i++)
		cout << mlstInt[i] << endl;

	mlstInt.clear();

	cout << endl;

	//singly linked list test for double
	cout << "singly linked list test for double---------------------------" << endl << endl;

	List<double> mlstDouble;

	mlstDouble.pushBack(5.3);
	mlstDouble.pushBack(3.2);
	mlstDouble.pushBack(8.34);
	mlstDouble.pushBack(23.11);
	mlstDouble.pushBack(7.67);

	//print mlstDouble
	for (auto i = 0; i < mlstDouble.getsize(); i++)
		cout << mlstDouble[i] << endl;

	mlstDouble.clear();

	cout << endl;

	//singly linked list test for MyFile class

	cout << "singly linked list test for string---------------------------" << endl << endl;

	List<string> mlstString;

	mlstString.pushBack("some");
	mlstString.pushBack("string");
	mlstString.pushBack("for");
	mlstString.pushBack("testing");
	mlstString.pushBack("linked list");

	mlstString.insertionSort();
	//print mlstString
	for (auto i = 0; i < mlstString.getsize(); i++)
		cout << mlstString[i] << endl;

	mlstString.clear();

	cout << endl;
	

	cout << "singly linked list test for MyFile class---------------------------" << endl << endl;

	List<MyFile*> mlstClass;

	for (auto i = 0; i < 2; i++) {
		mlstClass.pushBack(new MyFile());
		mlstClass.pushBack(new MyFolder());
	}

	//print mlstClass
	for (auto i = 0; i < mlstClass.getsize(); i++)
		mlstClass[i]->printInfo();

	mlstClass.clear();

	cout << endl;

	//test STL vector
	cout << "test STL vector---------------------------" << endl << endl;
	vector<MyFile*> mlstSort;

	for (auto i = 0; i < 2; i++) {
		mlstSort.push_back(new MyFile());
		mlstSort.push_back(new MyFolder());
	}

	for (auto i : mlstSort)
		i->printInfo();

	mlstSort.clear();

	cout << endl;

	//test findByName function
	cout << "test findByName func---------------------------" << endl << endl;
	vector<MyFile*> mlstFind;

	for (auto i = 0; i < 2; i++) {
		mlstFind.push_back(new MyFile());
		mlstFind.push_back(new MyFolder());
	}

	findByName("DefaultFolderName", mlstFind);

	mlstFind.clear();

	cout << endl;

	return 0;
}