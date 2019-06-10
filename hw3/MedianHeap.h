/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Interface for the median heap data structure.
 *               Calculates median of the values inserted in O(1) time
 */

#ifndef MedianHeap_h
#define MedianHeap_h

#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream> // cout
using namespace std; // cout

class MedianHeap{
public:
    // constructor
    MedianHeap();
    
    /**
     * @brief inserts an element into MedianHeap
     * @param value integer to insert
     */
    void insert(int value);
    
    /**
     * @brief Find the median of the heap
     */
    int findMedian();
    
private:
    // 2 heaps to get median in O(1) time
    MaxHeap lower;
    MinHeap upper;
    // size of the median heap
    int size;
    /**
     * @brief Function for rebalancing the median heap
     * The heap needs to rebalanced when size of max heap and min heap differ more than 1 item
     */
    void rebalance();
    
    /**
     * @brief Function for finding the heap with the bigger size
     * @param flag 1 if the max heap has the bigger size 0 if min heap has the bigger size
     * @param maxSize type(int) heap with the mazimum size
     * @param minSize type(int) heap with the minimum size
     */
    void findBiggerHeap(int &flag, int &maxSize, int &minSize);
    
};
#endif
