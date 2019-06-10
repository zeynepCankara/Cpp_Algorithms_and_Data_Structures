/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Header (.h) file for priority queue algorithms which modified for Huffman Coding
 *                 - Solution of Question 3)
 */


#ifndef HuffmanQueue_h
#define HuffmanQueue_h
#include "HuffmanHeap.h"

class HuffmanQueue {
private:
    // use HuffmanHeap for the queue implementation
    HuffmanHeap huffmanHeap;
    
    // huffman code is a friend class
    friend class HuffmanCode;
public:
    // check whether queue contains any elements
    bool pqIsEmpty() const;
    
    // insert into the priority queue 2 signatures for insertion type
    void pqInsert(int freq, char character);
    void pqInsert(HuffmanHeap::MinHeapNode *&newItem);
    
    // deletes the element with highest priority
    HuffmanHeap::MinHeapNode* pqDelete();
    
    // size function
    int size();
};

#endif

