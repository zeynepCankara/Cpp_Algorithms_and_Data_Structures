/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Source file of Binary Search Tree .
 *              Note: This file contains implementations. Detailed comments are in the header file
 */

#include "BST.h"
#include <iostream>
using namespace std;
// default constructor
BST::BST(){
    root = NULL;
}

// destructor
BST::~BST(){
    deleteTree(root);
}

// Insertion
void BST::insertItem(int key){
    // first find the position to insert
    insertItem(key, root);
}

// Deletion
void BST::deleteItem(int key){
    // First search for the node to delete
    // Case 1) Node has no children
    // Case 2) Node has only 1 child
    // Case 3) Node has 2 childeren
    searchToDelete(key, root);
};

// Fetch
BSTNode* BST::retrieveItem(int key){
    return retrieveItem(key, root);
};

// Inorder traversal
int* BST::inorderTraversal(int& length){
    length = 0; // safety
    countNodes(length, root);
    if (!length) {
        return NULL; // tree empty
    } else {
        // create an dynamically allocated array
        int *treeArray = new int[length];
        int idx = 0; // increment index within the function
        writeInArray(treeArray, idx, root);
        return treeArray;
    }
};


// check whether given array is a subequence within the tree
bool BST::containsSequence(int* seq, int length){
    int idx = 0;
    bool flag = false;
    BSTcontainsSequence(seq, length, idx, root, flag);
    return flag;
}

// Returns number of nodes whose level is greater than the level threshold
int BST::countNodesDeeperThan(int level){
    int numNodes = 0;
    countNodesDeeperThan(level, numNodes, root);
    return numNodes;
}

// returns maximum height if the tree could have height balanced.
int BST::maxBalancedHeight(){
    int curBalanced = 0;
    checkBalancedHeight(root, curBalanced);
    // root has only one child or have no child
    if ((root->rightChildPtr == NULL) || (root->leftChildPtr == NULL)){
        return ++curBalanced;
    }
    return curBalanced;
}



// ======= Private Methods of the BST Class (Helpers) ===========

// insertion
void BST::insertItem(const int &keyItem, BSTNode *&rootNode){
    if (!rootNode) {
        rootNode = new BSTNode(keyItem, NULL, NULL); // dynamic allocated node
    } else {
        // determine which brach to go
        if (keyItem < rootNode->item) {
            // look left
            insertItem(keyItem, rootNode->leftChildPtr);
        } else {
            // look right
            insertItem(keyItem, rootNode->rightChildPtr);
        }
    }
}

// empty check
bool BST::isEmpty(){
    if (root) {
        return false;
    }
    return true;
}

// desrtuctor helper
void BST::deleteTree(BSTNode *&rootNode){
    if (rootNode) { // root is not empty
        deleteTree(rootNode->leftChildPtr); // deallocate left subtree
        deleteTree(rootNode->rightChildPtr); // deallocate right subtree
        delete rootNode; // deallocate current node
        rootNode = NULL; // consistency
    }
}

// retrieve the item which contains the key value
BSTNode* BST::retrieveItem(const int &keyItem, BSTNode *&rootNode){
    // node is empty we searched and not found
    if (!rootNode) {
        // return NULL to indicate not found
        return NULL;
    } else {
        if (keyItem == rootNode->item) {
            return rootNode; // node found
        }
        else if (keyItem < rootNode->item) {
            // look left
            retrieveItem(keyItem, rootNode->leftChildPtr);
        }
        else {
            // look right
            retrieveItem(keyItem, rootNode->rightChildPtr);
        }
    }
    return NULL; // never falls to this case
}

// ======== deleteNode helpers ==========

// when found node delete the node
void BST::deleteNode(BSTNode *&node){
    // Case 1) node does not have a child
    if ((node->leftChildPtr == NULL) && (node->rightChildPtr == NULL)) {
        delete node;
        node = NULL;
    } else if(node->leftChildPtr == NULL){
        // Case 2) node has only the right child
        // copy the value to current node
        node->item = node->rightChildPtr->item;
        // deallocate the left child
        delete node->rightChildPtr;
        node->rightChildPtr = NULL;
    } else if(node->rightChildPtr == NULL){
        // Case 2) node has only the left child
        // copy the value to current node
        node->item = node->leftChildPtr->item;
        // deallocate the left child
        delete node->leftChildPtr;
        node->leftChildPtr = NULL;
    }  else {
    // Case 3) node has 2 children
        // helper function to deal with 2 children case
        // Find the in order succsessor
        int keyItem = -1;
        processLeftMost(keyItem, node->rightChildPtr);
        node->item = keyItem; // write back the value obtained
    }
}

// Handle deletion case3 node have 2 children
void BST::processLeftMost(int &keyItem, BSTNode *&node){
    if(!(node->leftChildPtr)){
        // found the in order successor
        keyItem =  node->item;
        // delete the node
        delete node;
        node = NULL; // safe-check
    } else {
        // recurse left
        processLeftMost(keyItem, node->leftChildPtr);
    }
}

// search for the node to delete
void BST::searchToDelete(int &keyItem, BSTNode *&node){
    if (!node) {
        // item not found
        return;
    } else {
        if (node->item == keyItem) {
            // delete node
            deleteNode(node);
        } else if (keyItem < node->item){
            // search left
            searchToDelete(keyItem, node->leftChildPtr);
        } else {
            // search right
            searchToDelete(keyItem, node->rightChildPtr);
        }
    }
}

// ================= inorder traversal helpers ====================
// count nodes of the tree
void BST::countNodes(int& length, BSTNode *&node){
    if (node == NULL) {
        return;
    }
    // go left subtree
    countNodes(length, node->leftChildPtr);
    // current node
    length++;
    // go right subtree
    countNodes(length, node->rightChildPtr);
}

// write the values to the array
void BST::writeInArray(int *treeArray, int &idx, BSTNode *&node){
    if (node == NULL) {
        return;
    }
    // go left subtree
    writeInArray(treeArray, idx, node->leftChildPtr);
    // process node
    treeArray[idx++] = node->item;
    // go right subtree
    writeInArray(treeArray, idx, node->rightChildPtr);
}

// ============= containsSequence helpers =============
void BST::BSTcontainsSequence(int* seq, const int length, int &idx, BSTNode *&node, bool &flag){
    // perform in order traversal
    // check match between current node
    // increment sequence index if there is match
    // keep checking untill matching fails
    if (flag) {
        return;
    }
    if (!node) {
        return;
    }
    else {
        // search left
        BSTcontainsSequence(seq, length, idx, node->leftChildPtr, flag);
        // process current node
        cout << "Visit Node: " << node->item << endl;
        if (node->item == seq[idx]) {
            // increment index
            idx++;
        } else {
            // fails to contain item
            idx = 0;
        }
        if (idx == length) {
            flag =  true; // all sequence traversed
            return;
        }
        if(node->item > seq[idx] && !flag){
            // current node element greater than the index and sequence does not marked contained 
            flag = false;
            return;
        }
        // search right
        BSTcontainsSequence(seq, length, idx, node->rightChildPtr, flag);
    }
}

// ============= countNodesDeeperThan helpers =============

void BST::countNodesDeeperThan(int level, int &numNodes, BSTNode *&node){
    if (node == NULL) {
        return;
    } else {
        // search through left
        countNodesDeeperThan(level, numNodes, node->leftChildPtr);
        // process current node determine current node's level
        int nodeLevel = 1;
        getLevel(root, node->item, nodeLevel);
        if (nodeLevel >= level) {
            //cout << "node value: " << node->item << endl;
            //cout << "node level: " << nodeLevel << endl;
            numNodes++;
        }
        // search through right
        countNodesDeeperThan(level, numNodes, node->rightChildPtr);
    }
}

void BST::getLevel(BSTNode *&node, int targetKey, int &nodeLevel){
    if (!node) {
        // node is NULL
        return;
    }
    else {
        if (targetKey == node->item) {
            return;
        }
        else if (targetKey < node->item) {
            nodeLevel++;
            getLevel(node->leftChildPtr, targetKey, nodeLevel);
        } else {
            nodeLevel++;
            getLevel(node->rightChildPtr, targetKey, nodeLevel);
        }
    }
};

// ========== maxBalancedHeight helpers ===========

// returns height of the tree
int BST::getHeight(BSTNode *&node){
    if (node == NULL) {
        return 0;
    }
    else {
        return 1 + max(getHeight(node->leftChildPtr), getHeight(node->rightChildPtr));
    }
}

// checls the balanced height so far
void BST::checkBalancedHeight(BSTNode *&node, int &maxBalanced){
    // if node' left subtree and right subtree height differs no more than 1 than the tree is balanced
    if (node == NULL) {
        return;
    }
    // obtain the subree heights
    int leftSubtree = getHeight(node->leftChildPtr);
    int rightSubtree = getHeight(node->rightChildPtr);
    int curBalanced;
    // get the minimum of the height where tree is balanced
    if (abs(leftSubtree - rightSubtree) >= 1) {
        // get minimum to obtain height balanced
        curBalanced  =  1 + min(leftSubtree, rightSubtree);
    }
    else {
        // tree is balanced differ only less than or equal 1 level
        curBalanced = max(leftSubtree, rightSubtree);
    }
    maxBalanced = max(maxBalanced, curBalanced);
}


