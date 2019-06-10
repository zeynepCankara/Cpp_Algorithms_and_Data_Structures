/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Header file of Binary Search Tree. Contains protototypes of tree fucntions.
 *              Note: This file is the private interface.
 */

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include "BSTNode.h"

class BST{
public:
    // default constructor
    BST();
    // destructor free nodes
    ~BST();
    
    /**
     *  @brief Inserts the key (int) to corresponding place in the tree
     *  @param key integer item value
     */
    void insertItem(int key);
    
    /**
     *  @brief Deletes the key (int) if it exists
     *  @param key integer target item value
     */
    void deleteItem(int key);
    
    /**
     *  @brief Returns the node which contains the key
     *  @param key integer target item value
     */
    BSTNode* retrieveItem(int key);
    
    /**
     *  @brief Performs inorder traversal writes data into an array returns the size of array within length
     *  @param length size of array
     *  @return array contains node items in sorted order
     */
    int* inorderTraversal(int& length);
    
    /**
     *  @brief Checks whether tree contains the given sequence
     *  @param seq sequence array
     *  @param length size of the array
     *  @return bool indicating whether sequence is a subsequence contained within the tree
     */
    bool containsSequence(int* seq, int length);
    
    /**
     *  @brief Returns number of nodes whose level is greater than the level threshold
     *  @param level threshold values
     *  @return result number of nodes having greater or equal level than level threshold
     */
    int countNodesDeeperThan(int level);
    
    /**
     *  @brief What will the height will be if we remove the nodes which hurts height balanced condition
     *  @return max height tree will have if it's balanced
     */
    int maxBalancedHeight();
    
private:
    // instance variables
    BSTNode *root;
    
    // Tree Helpers
    
    /**
     * @brief Checks whether tree is empty or not
     */
    bool isEmpty();
    
    /**
     * @brief Deallocates the tree starting from given node
     * @param rootNode deletion starting address
     */
    void deleteTree(BSTNode *&rootNode);
    
    /**
     * @brief Insert the item to the tree
     * @param keyItem integer target item to insert into the tree
     * @param rootNode node gives reference to find insertion position
     */
    void insertItem(const int &keyItem, BSTNode *&rootNode);
    
    /**
     * @brief Finds the node with the given key
     * @param keyItem integer target for node retrieval
     * @param rootNode node gives reference for search
     */
    BSTNode* retrieveItem(const int &keyItem, BSTNode *&rootNode);
    
    // ======= delete node helpers ========
    
    /**
     * @brief Searches for the node which contains the given key value
     * @param node to travers tree
     * @param keyItem target key value
     */
    void searchToDelete(int &keyItem, BSTNode *&node);
    
    /**
     * @brief checks cases and deletes the node
     * @param node to delete
     */
    void deleteNode(BSTNode *&node);
    
    /**
     * @brief Case 3 node has 2 children
     * @param node to delete
     */
    void processLeftMost(int &keyItem, BSTNode *&node);
    
    // ========== inorder traversal helpers ==========
    
    /**
     * @brief Count number nodes in the array
     * @param length  height of the array
     * @param node root
     */
    void countNodes(int& length, BSTNode *&node);
    
    /**
     * @brief Write data to the array of interest
     * @param treeArray arrayToWrite
     * @param idx current index
     * @param node current node to write
     */
    void writeInArray(int *treeArray, int &idx, BSTNode *&node);
    
    // ======= contains sequence helper  ========
    /**
     * @brief Checks tree contains the given sequence
     * @param seq arrayToWrite
     * @param length size of the array
     * @param idx current index
     * @param node handle to the tree
     * @param flag indicates whether sequence found or not
     */
    void BSTcontainsSequence(int* seq, const int length, int &idx, BSTNode *&node, bool &flag);
    
    // ======== count nodes deeper than helper
    
    /**
     *  @brief Returns number of nodes whose level is greater than the level threshold
     *  @param level threshold values
     *  @param numNodes in/out param to count nodes whose level greater than the threshold
     *  @param node handle to traverse the tree
     */
    void countNodesDeeperThan(int level, int &numNodes, BSTNode *&node);
    
    /**
     *  @brief Determines level of the choosen node
     *  @param node handle to traverse the tree
     *  @param targetKey node to target starting from root
     *  @param nodeLevel level of the current node
     */
    void getLevel(BSTNode *&node, int targetKey, int &nodeLevel);
    
    // ======== maxBalancedHeight Helpers
    
    /**
     * @brief gets a node and determines height of the tree
     * @return height
     */
    int getHeight(BSTNode *& node);
    
    /**
     * @brief Check tree's balanced height
     */
    void checkBalancedHeight(BSTNode *&node, int &maxBalanced);
    

};

#endif
