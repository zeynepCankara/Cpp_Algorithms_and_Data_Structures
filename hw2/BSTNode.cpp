/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Source file of Binary Search Tree Node Class. Node data type: int.
 *              Note: Header file contains comments
 */

#include "BSTNode.h"

// Default constructor
BSTNode::BSTNode(){};

// Constructor
BSTNode::BSTNode(const int &nodeItem, BSTNode *left, BSTNode *right){
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    }


