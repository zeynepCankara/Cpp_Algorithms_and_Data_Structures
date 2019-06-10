/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Implementation of an array-baseds max heap.
 *             - Check header file (.h) for more detailed explenation of the code.
 */

#include "MaxHeap.h"
#include <iostream> // for cout <<
using namespace std;
// Constructor
MaxHeap::MaxHeap(){
    sizeHeap = 0;
    items = new int[MAX_SIZE];
}

// Destructor
MaxHeap::~MaxHeap(){
    if (!isEmpty()) {
        // deallocate the heap space
        delete [] items;
        sizeHeap = 0;
    }
}

// size
int MaxHeap::size(){
    return sizeHeap;
}

// isEmpty
bool MaxHeap::isEmpty(){
    if (sizeHeap > 0) {
        return false;
    }
    return true;
}

// returns the max element of the heap
int MaxHeap::peek(){
    // maximum element always be the first element of the heap
    if (!isEmpty()) {
        return items[0];
    }
    // boolean flag indicating not found
    cout << "ERROR: The heap is empty" << endl;
    return -1;
}

// insert a new value into the heap
void MaxHeap::insert(int value){
    // 0) Check whether there is a space left for inserting the value
    // 1) Appand the new value at the end of the array
    // 2) Go up to by checking parents and max heap condition
    if (size() >= MAX_SIZE) {
        // 0) reached to the maximum size
        cout << "ERROR: max size reached can't insert!" << endl;
        return;
    } else {
        // place the item at the end
        items[sizeHeap] = value;
        
        // remember the place and move the item to the top
        int pos = size();
        
        int parent = (pos -1)/2;
        while ((pos > 0) && (items[pos] > items[parent])) {
            // swap elements if parent is smaller than the current element
            int temp =  items[parent];
            items[parent] = items[pos];
            items[pos] = temp;
            
            // move current node and parent up
            pos = parent;
            parent = (pos - 1)/2;
        }
        // increase the size
        sizeHeap++;
    }
}



// retrieves and deletes max element from the heap
int MaxHeap::extractMax(){
    if (isEmpty()) {
        // heap is empty
        cout << "ERROR: Heap is empty can't extract the max" << endl;
        return -1;
    } else {
        // save the maximum element
        int maxItem = peek();
        // call heapDelete function
        heapDelete(items[0]);
        return maxItem;
    }
}


// ========== PRIVATE HELPER FUNCTIONS =============== //////

// HeapRebuild: satisfy heap property again
void MaxHeap::heapRebuild(int root){
    int childPtr = (root * 2) + 1;
    if ( childPtr < size()) {
        // not a leaf situation check existance of right child
        int rightChildPtr = childPtr + 1;     // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChildPtr < size()) && (items[rightChildPtr] >items[childPtr]) ){
            childPtr = rightChildPtr;     // get the position of the largest child
        }
        // check root value swap if smaller
        if ( items[root] < items[childPtr]) {
            int temp = items[root];
            items[root] = items[childPtr];
            items[childPtr] = temp;
            
            // obtain the heap property back for child pointer
            heapRebuild(childPtr);
        }
    }
}


// deletes the root item from the heap
void MaxHeap::heapDelete(int &rootItem){
    if (isEmpty()) {
        cout << "ERROR: Heap is empty !!!" << endl;
    } else {
        rootItem = peek();
        items[0] = items[--sizeHeap];
        heapRebuild(0);
    }
}


