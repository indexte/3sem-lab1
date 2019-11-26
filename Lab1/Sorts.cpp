////#include<algorithm>
#include"MyFile.h"
#include"List.h"
//
////insertion sort for custom List class
//void listInsertionSort(List<MyFile> l, int n) {
//	int i, j;
//	MyFile data;
//	for (i = 1; i < n; i++) {
//		data = l[i];
//		j = i - 1;
//
//		while (j >= 0 && l[j] > data) {
//			l.removeAt(j + 1);
//			l.insert(l[j], j + 1);
//			j = j - 1;
//		}
//		l.removeAt(j + 1);
//		l.insert(data, j + 1);
//	}
//}
//
//template<typename T>
//List<T>* partit(List<T>* b, List<T>* e) {
//	int line = e->key;
//	List<T>* i = b->prev;
//	for (List<T>* j = b; j != e; j = j->next) {
//		if (j->key <= line) {
//			i = (i == NULL) ? b : i->next;
//			swap(&(i->key), &(j->key));
//		}
//	}
//	i = (i == NULL) ? b : i->next;
//	swap(&(i->key), &(e->key));
//	return i;
//}
//
//template<typename T>
//void quickS(List<T>* beg, List<T>* en) {
//	if (en != NULL && beg != en && beg != en->next) {
//		List<T>* part = partit(beg, en);
//		quickS(beg, part->prev);
//		quickS(part->next, en);
//	}
//}