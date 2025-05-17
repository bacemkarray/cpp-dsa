#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
    ArrayList<int> *aList = new ArrayList<int>(5);

	if(aList->isEmpty())
		cout << "List is empty..." << endl;
	else
		cout << "List is not empty..." << endl;

	aList->printList();

	aList->add(0, 2);
	aList->add(1, 5);
	aList->add(2, 13);
	aList->add(3, -6);
	aList->add(4, 9);

	if(aList->isEmpty())
		cout << "List is empty..." << endl;
	else
		cout << "List is not empty..." << endl;

	aList->printList();

	// Insert to the middle
	aList->add(2, -6);
	aList->add(3, 9);

	aList->printList();

	aList->set(0, 10);
	aList->set(5, 2);
	aList->set(3, -15);

	aList->printList();

	cout << "Element 3 with value " << aList->remove(3) << " is removed from the list." << endl;

	aList->printList();

	cout << "Element 5 with value " << aList->remove(5) << " is removed from the list." << endl;

	aList->printList();

	// Test array out of bound access
	cout << "Element 2 has a value of " << aList->get(2) << endl;
	// cout << "Element 10 has a value of " << aList->get(10) << endl;
	// cout << "Element -3 has a value of " << aList->get(-3) << endl;
	cout << "Element 3 has a value of " << aList->get(3) << endl;

	cout << "Element 2 with value " << aList->remove(2) << " is removed from the list." << endl;
	cout << "Element 1 with value " << aList->remove(1) << " is removed from the list." << endl;

	aList->printList();

	delete aList;

    return 0;
}


