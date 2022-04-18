#ifndef LinkedList_H
#define LinkedList_H
//#include <iostream>
namespace Data{
template <class T>
class Map;

}

namespace DataStructure{
template <class T>
struct Node{
    T data;
    Node<T> *next = NULL;
    //T *before;
};

template <class T>
class LinkedList{
private:
    Node<T> *head = NULL;
    Node<T> *last = NULL;
    int count = 0;

    Node<T>* MergeSortedList(Node<T>* lst1, Node<T>* lst2){
	Node<T>* result = NULL;
	// Base Cases
	if (lst1 == NULL)
		return (lst2);
	else if (lst2 == NULL)
		return (lst1);

	// recursively merging two lists
	if (lst1->data <= lst2->data) {
		result = lst1;
		result->next = MergeSortedList(lst1->next, lst2);
	}
	else {
		result = lst2;
		result->next = MergeSortedList(lst1, lst2->next);
	}
	return result;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.

void SplitList(Node<T>* source, Node<T>** front, Node<T>** back)
{
	Node<T>* ptr1;
	Node<T>* ptr2;
	ptr2 = source;
	ptr1 = source->next;

	// ptr1 is incrmented twice and ptr2 is icremented once.
	while (ptr1 != NULL) {
		ptr1 = ptr1->next;
		if (ptr1 != NULL) {
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}

	// ptr2 is at the midpoint.
	*front = source;
	*back = ptr2->next;
	ptr2->next = NULL;
}


// Merge Sort

void MergeSort(Node<T>** thead)
{
	Node<T>* head = *thead;
	Node<T>* ptr1;
	Node<T>* ptr2;

  // Base Case
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	// Splitting list
	SplitList(head, &ptr1, &ptr2);

	// Recursively sorting two lists.
	MergeSort(&ptr1);
	MergeSort(&ptr2);

	// Sorted List.
	*thead = MergeSortedList(ptr1, ptr2);
}


public:

    ~LinkedList();

    void sortList();

    void insertFirst(T Val);
    void insertLast(T Val);
    void insertAt(T Val, int indx);

    void destroyList();
    //void copyList();

    void arrToList(T *Arr, int size);

    void printList();

    bool isEmpty();

    //Node<T> *getHead();

    void removeMultiple();

    bool searchFor(T x);

    //T &(int indx);
    void deleteAt(int indx);
    T &getAt(int indx);

    int getLength();


    void copyList(LinkedList<T> &Dest);

    friend class Data::Map<T>;

};




}

#endif // LinkedList_H
