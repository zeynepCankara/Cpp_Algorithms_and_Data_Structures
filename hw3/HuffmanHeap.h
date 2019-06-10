/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Header (.h) file for Min Heap algorithms which modified for Huffman Coding
 */

#ifndef HuffmanHeap_h
#define HuffmanHeap_h

const int MAX_SIZE_HC = 10000;
#include <iostream>
class HuffmanHeap {
private:
    // struct for Huffman heap
    struct MinHeapNode {
        char character; // An input character
        int freq; // Frequency of the character
        MinHeapNode *left, *right; // Left and right child
    };
    // data
    int sizeHeap; // for tracking size of the array
    MinHeapNode *items[MAX_SIZE_HC]; // keeps array of min heap node pointers
    
    friend class HuffmanQueue;
    friend class HuffmanCode;
public:

    // Constructor
    HuffmanHeap();

    /**
     * @brief inserts a pointer to the node of interest into the min heap
     */
    void insert(MinHeapNode *& nodePtr);
    
    /**
     * @brief creates node and inserts the node in the heap
     */
    void insert(const int freq, const char character);
    
    /**
     * @brief Returns node with the min frequency
     */
    int peek();
    
    /**
     * @brief Returns a pointer to the min element in the heap
     */
    MinHeapNode* extractMin();
    
    /**
     * @brief returns the number of elements in the heap
     * TODO: Done
     */
    int size();
    
    /**
     * @brief Check heap is empty or not
     * @return flag indicating heap is empty or not
     */
    bool isEmpty() const;
    /**
     * @brief Deletes the root item which is also the min item from the heap
     */
    void heapDelete(MinHeapNode *&nodeToDel);
    
protected:
    /**
     * @brief Rearrange the heap in order to satisfy heap property again
     */
    void heapRebuild(int root);
};


#endif
