/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Implementation of Huffman heap which is a min heap used for Huffman Coding
 */

#include "HuffmanHeap.h"
using namespace std;

// Constructor
HuffmanHeap::HuffmanHeap(){
    sizeHeap = 0;
}


// size
int HuffmanHeap::size(){
    return sizeHeap;
}

// isEmpty
bool HuffmanHeap::isEmpty() const{
    if (sizeHeap > 0) {
        return false;
    }
    return true;
}

// returns a pointer to the node at the top of the min heap
int HuffmanHeap::peek() {
    // maximum element always be the first element of the heap
    if (!isEmpty()) {
        return (*items[0]).freq;
    }
    return 0;
}

// insert a new value into the heap
void HuffmanHeap::insert(MinHeapNode *& nodePtr){
    // 0) Check whether there is a space left for inserting the value
    // 1) Appand the new value at the end of the array
    // 2) Go up to by checking parents and max heap condition
    if (size() >= MAX_SIZE_HC) {
        // 0) reached to the maximum size
        cout << "ERROR: exceeds max capacity of heap!" << endl;
        return;
    } else {
        // place the item at the end
        items[sizeHeap] = nodePtr;
        
        // remember the place and move the item to the top
        int pos = size();
        
        int parent = (pos -1)/2;
        while ((pos > 0) && ((*items[pos]).freq < (*items[parent]).freq)) {
            // swap elements if parent is smaller than the current element
            // no dynamically allocated data so no leak problem
            MinHeapNode *temp =  items[parent];
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
HuffmanHeap::MinHeapNode* HuffmanHeap::extractMin(){
    if (isEmpty()) {
        // heap is empty
        return NULL;
    } else {
        // get the result pointer
        MinHeapNode *minItem;
        // call heapDelete function
        heapDelete(minItem);
        // return the result
        return minItem;
    }
}


// Creates node and inserts the node in the heap
void HuffmanHeap::insert(const int freq, const char character){
    // 0) Check whether there is a space left for inserting the value
    // 1) Appand the new value at the end of the array
    // 2) Go up to by checking parents and max heap condition
    if (size() >= MAX_SIZE_HC) {
        // 0) reached to the maximum size
        cout << "ERROR: exceeds max capacity of heap!" << endl;
        return;
    } else {
        MinHeapNode *nodePtr = new MinHeapNode;
        nodePtr->freq = freq;
        nodePtr->character = character;
        nodePtr->left = NULL;
        nodePtr->right = NULL;
        // place the item at the end
        items[sizeHeap] = nodePtr;
        
        // remember the place and move the item to the top
        int pos = size();
        
        int parent = (pos -1)/2;
        while ((pos > 0) && ((*items[pos]).freq < (*items[parent]).freq)) {
            // swap elements if parent is smaller than the current element
            // no dynamically allocated data so no leak problem
            MinHeapNode *temp =  items[parent];
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

// ========== PRIVATE HELPER FUNCTIONS =============== //////

// HeapRebuild: satisfy heap property again
void HuffmanHeap::heapRebuild(int root){
    int childPtr = (root * 2) + 1;
    if ( childPtr < sizeHeap) {
        // not a leaf situation check existance of right child
        int rightChildPtr = childPtr + 1;     // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChildPtr < sizeHeap) && ((*items[rightChildPtr]).freq < (*items[childPtr]).freq) ){
            childPtr = rightChildPtr;     // get the position of the smallest child
        }
        // check root value swap if larger
        if ( (*items[root]).freq > (*items[childPtr]).freq) {
            MinHeapNode *temp = items[root];
            items[root] = items[childPtr];
            items[childPtr] = temp;
            
            // obtain the heap property back for child pointer
            heapRebuild(childPtr);
        }
    }
}


// deletes the root item from the heap
void HuffmanHeap::heapDelete(MinHeapNode *&nodeToDel){
    if (isEmpty()) {
        cout << "ERROR: Heap empty!" << endl;
    } else {
        nodeToDel = items[0]; // get the node ptr
        items[0] = items[--sizeHeap]; // just pointer swaps
        heapRebuild(0);
    }
}




