#include<iostream>
#include<list>
#include<algorithm>
#include"MyFile.h"
#include"MyFolder.h"
#include"List.h"

using std::list;
using std::cout;
using std::endl;

//find file or folder by parameter
void findByName(string searchName, list<MyFile*> yourListOfObj);


int main() {
	list<MyFile*> mlst;
	for (int i = 0; i < 5; i++) {
		mlst.push_back(new MyFile());
	}

	mlst.push_back(new MyFolder());

	//for (auto i = 0; i < mlst.getSize(); i++) {
	//	mlst[i]->printInfo();
	//	cout << endl;
	//}
	
	for (auto i : mlst) {
		i->printInfo();
		cout << endl;
	}

	cout << "----------------------------------" << endl;

	findByName("DefaultFoldeName", mlst);



	//for (auto i = 0; i < mlst.getSize(); i++) {
	//	mlst[i]->printInfo();
	//	cout << endl;
	//}
	return 0;
}