/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Interface for the min heap data structure.
 *             - Note: Methods with TODO are required functions for the assignment
 */

#ifndef MinHeap_h
#define MinHeap_h

// ========= MIN HEAP =========== //
class MinHeap{
public:
    // Constructor
    MinHeap();
    
    // Destructor
    ~MinHeap();
    
    /**
     * @brief inserts integer into heap
     * @param value type(int)
     * TODO: Done
     */
    void insert(int value);
    
    /**
     * @brief returns the value of the min element
     * @return minElement -1 if the heap is empty
     * TODO: Done
     */
    int peek();
    
    /**
     * @brief retrieves and removes the min element
     * TODO:
     */
    int extractMin();
    
    /**
     * @brief returns the number of elements in the heap
     * TODO: Done
     */
    int size();
    
    /**
     * @brief Check heap is empty or not
     * @return flag indicating heap is empty or not
     */
    bool isEmpty();
private:
    int sizeHeap; // for tracking size of the array
    int *items; // array to keep the min-heap structure
    
    /**
     * @brief Deletes the root item which is also the min item from the heap
     */
    void heapDelete(int &rootItem);
    
    
    /**
     * @brief Rearrange the heap in order to satisfy heap property again
     */
    void heapRebuild(int root);
};
#endif

