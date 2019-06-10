/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Source (.cpp) file for min priority queue which will be used for Huffman Coding
 *              - Abstraction of a priority queue data structure which use min-heap inside
 */

#include "HuffmanQueue.h"

/**
 * @brief Queue conteins any item or not
 */
bool HuffmanQueue::pqIsEmpty() const {
    if (huffmanHeap.isEmpty()) {
        return true;
    } else {
        return false;
    }
}

// insert a new element within the queue
void HuffmanQueue::pqInsert(int freq, char character){
    huffmanHeap.insert(freq, character);
}

// insertion algorithm which takes node pointer
void HuffmanQueue::pqInsert(HuffmanHeap::MinHeapNode *&newItem){
    huffmanHeap.insert(newItem);
}

// delete the topmost min element from queue
HuffmanHeap::MinHeapNode* HuffmanQueue::pqDelete(){
    return huffmanHeap.extractMin();
}

int HuffmanQueue::size(){
    return huffmanHeap.size();
}

