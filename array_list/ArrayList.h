#include <iostream>
#include "ListInterface.h"


using namespace std;

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <typename E>
class ArrayList : public List<E> {
    private:
        E* Array; //Pointer to an array of type E
        int capacity;
        int size;

    public:
        ArrayList(int initial_capacity);
        ~ArrayList();

        ArrayList(const ArrayList& other);
        ArrayList& operator=(const ArrayList& other);

        int getSize();
        bool isEmpty();
        void add(int index, const E& element);
        E get(int index);
        E remove(int index);
        E set(int index, const E& element);
        void printList();

};


template <typename E>
ArrayList<E>::ArrayList(int initial_capacity) {
    capacity = initial_capacity;
    size = 0;
    Array = new E[capacity]; //New block of memory on heap
}


template <typename E>
ArrayList<E>::~ArrayList() {
    delete[] Array;
}

// Copy Constructor - Makes a new object that has identical data to another
template <typename E>
ArrayList<E>::ArrayList(const ArrayList& other) {
    capacity = other.capacity;
    size = other.size;
    Array = new E[capacity];

    for(int i=0; i<size; i++) {
        Array[i] = other.Array[i];
    }
}

// Copy Assignment Operator - Takes a previously existing object,
// deletes all of its contents (to prevent memory leak), and copies
// the data from another one.
template <typename E>
ArrayList<E>& ArrayList<E>::operator=(const ArrayList<E>& other) {
    if(this == &other) return *this;

    delete[] Array;
    capacity = other.capacity;
    size = other.size;
    Array = new E[capacity];

    for(int i=0; i<size; i++) {
        Array[i] = other.Array[i];
    }

    return *this;
}


template <typename E>
int ArrayList<E>::getSize() {
    return size;
}


template <typename E>
bool ArrayList<E>::isEmpty() {
    return size == 0;
}


template <typename E>
void ArrayList<E>::add(int index, const E& element) {
    if(index < 0 || index > size) {
        throw out_of_range("Index out of bounds");
    }
    
    if(size == capacity) {
        capacity *= 2;
        E* Temp = new E[capacity];

        for(int j=0; j<size; j++) {
            Temp[j] = Array[j]; 
        }
        
        delete[] Array; //Delete old array
        Array = Temp; //Make array point to Temp's array
        // Temp is local and will be deleted when the function ends
    }
    
    for(int j=size; j>index; j--) {
        Array[j] = Array[j-1];
    }
    Array[index] = element;
    size++;
}


template <typename E>
E ArrayList<E>::get(int index) {
    if(index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return Array[index];
}


template <typename E>
E ArrayList<E>::remove(int index) {
    if(index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    
    E temp = Array[index];

    if(index == size-1) {
        size--;
        return temp;
    }

    for(int j=index; j<size-1; j++) {
        Array[j] = Array[j+1];
    }
    size--;

    return temp;
}


template <typename E>
E ArrayList<E>::set(int index, const E& element) {
    if(index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }

    E old = Array[index];
    Array[index] = element;
    
    return old;
}


template <typename E>
void ArrayList<E>::printList() {
    cout << "Size of List: " << size << endl;
    cout << "Capacity of List: " << capacity << endl;
    
    cout << "{";
    for (int i=0; i<size; i++) {
        cout << " " << Array[i] << " "; 
    }
    cout << "}" << endl;
}

#endif