#include"Info.h"
#include"List.h"

//insertion sort for custom List class
void listInsertionSort(List<Info> l, int n) {
	int i, j;
	Info data;
	for (i = 1; i < n; i++) {
		data = l[i];
		j = i - 1;

		while (j >= 0 && l[j] > data) {
			l.removeAt(j + 1);
			l.insert(l[j], j + 1);
			j = j - 1;
		}
		l.removeAt(j + 1);
		l.insert(data, j + 1);
	}
}