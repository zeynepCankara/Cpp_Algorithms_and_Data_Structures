/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Main file to test the code
 */

#include "BSTNode.h"
#include "BST.h"
#include <iostream>
using namespace std;

int main() {
    // insert code here...
    cout << "Hello, CS201 Homework 01" << endl;
    
    // Create the tree...
    cout << "=== Creating the tree ===" << endl;
    BST tree;
    //test for inserting items into the tree
    tree.insertItem(8);
    tree.insertItem(4);
    tree.insertItem(13);
    tree.insertItem(3);
    tree.insertItem(1);
    tree.insertItem(2);
    tree.insertItem(6);
    tree.insertItem(5);
    tree.insertItem(15);
    tree.insertItem(14);
    tree.insertItem(12);
    tree.insertItem(10);
    BST tree2;
    tree2.insertItem(1);
    tree2.insertItem(2);
    tree2.insertItem(3);
    tree2.insertItem(4);
    tree2.insertItem(5);
    tree2.insertItem(6);
    tree2.insertItem(7);
    BST tree3;
    tree3.insertItem(4);
    tree3.insertItem(3);
    tree3.insertItem(5);
    tree3.insertItem(6);
    tree3.insertItem(2);
    tree3.insertItem(1);
    BST tree4;
    tree4.insertItem(1);
    tree4.insertItem(2);
    BST tree5;
    tree5.insertItem(1);
    // inOrderTraversal than test...
    cout << "=== inorderTraversal method Test ===" << endl;
    cout << "Expected: [1, 2, 3, 4, 5, 6, 8, 10, 12, 13, 14, 15]" << endl;
    int length = 1000; // inOrder handles inappropiate length parameter values
    int *getArray = tree.inorderTraversal(length);
    for (int i = 0; i < length-1; i++) {
        cout << getArray[i] << ", ";
    }
    cout << getArray[length-1] << endl;
    // delete node test
    cout << "=== DeleteItems test delete key = 12 ===" << endl;
    cout << "Expected: [1, 2, 3, 4, 5, 6, 8, 10, 13, 14, 15]" << endl;
    tree.deleteItem(12); // key = 12 will deleted
    getArray = tree.inorderTraversal(length);
    for (int i = 0; i < length-1; i++) {
        cout << getArray[i] << ", ";
    }
    cout << getArray[length-1] << endl;
    cout << "=== DeleteItems test delete key = 1 (root) ===" << endl;
    cout << "Expected: [2, 3, 4, 5, 6, 8, 10, 13, 14, 15]" << endl;
    tree.deleteItem(1); // key = 12 will deleted
    getArray = tree.inorderTraversal(length);
    for (int i = 0; i < length-1; i++) {
        cout << getArray[i] << ", ";
    }
    // create another tree with the same values because the homework assignment has the same tree figure as well
    BST treeCpy;
    //test for inserting items into the tree
    treeCpy.insertItem(8);
    treeCpy.insertItem(4);
    treeCpy.insertItem(13);
    treeCpy.insertItem(3);
    treeCpy.insertItem(1);
    treeCpy.insertItem(2);
    treeCpy.insertItem(6);
    treeCpy.insertItem(5);
    treeCpy.insertItem(15);
    treeCpy.insertItem(14);
    treeCpy.insertItem(12);
    treeCpy.insertItem(10);
    
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << "Check tree contains sequence [1, 2, 3, 4, 5, 6]" << endl;
    // must not traverse subtree rooted at 13
    cout << "Expected: true" << endl;
    if( treeCpy.containsSequence(arr, 6)  ){
        cout << "Tree *contains* the sequence..." << endl;
    } else {
        cout << "Tree *DOES NOT contains* the sequence..." << endl;
    }
    cout << "Check tree contains sequence [10, 12, 13, 15]" << endl;
    cout << "Expected: false" << endl;
    int arr1[4] = {10, 12, 13, 15};
    if( treeCpy.containsSequence(arr1, 4)  ){
        cout << "Tree *contains* the sequence..." << endl;
    } else {
        cout << "Tree *DOES NOT contains* the sequence..." << endl;
    }
    cout << "Check tree contains sequence [10, 11, 12]" << endl;
    cout << "Expected: false" << endl;
    int arr2[3] = {10, 11, 12};
    if( treeCpy.containsSequence(arr2, 3)  ){
        cout << "Tree *contains* the sequence..." << endl;
    } else {
        cout << "Tree *DOES NOT contains* the sequence..." << endl;
    }
    // Count Nodes Deeper than test...
    cout << "=== countNodesDeeperThan method Test ===" << endl;
    int level = 4;
    int resultLevel = treeCpy.countNodesDeeperThan(level);
    cout << "Number of nodes having levels deeper than " << level << ": " << resultLevel << endl;
    level = 3;
    resultLevel = treeCpy.countNodesDeeperThan(level);
    cout << "Number of nodes having levels deeper than " << level << ": " << resultLevel << endl;
    level = 2;
    resultLevel = treeCpy.countNodesDeeperThan(level);
    cout << "Number of nodes having levels deeper than " << level << ": " << resultLevel << endl;
    level = 1;
    resultLevel = treeCpy.countNodesDeeperThan(level);
    cout << "Number of nodes having levels deeper than " << level << ": " << resultLevel << endl;
    // maxHeight Balanced test
    cout << "=== maxBalancedHeight Test ===" << endl;
    int maxBalanced = tree4.maxBalancedHeight();
    cout << "Only 2 node tree max height " << endl;
    cout << "tree will have height of if it's a balanced tree:  " << maxBalanced << endl;
    cout << "Only one node tree max height " << endl;
    maxBalanced = tree5.maxBalancedHeight();
    cout << "tree will have height of if it's a balanced tree:  " << maxBalanced << endl;
    cout << "Tree at homework assignment max height " << endl;
    maxBalanced = treeCpy.maxBalancedHeight();
    cout << "tree will have height of if it's a balanced tree:  " << maxBalanced << endl;
    
    cout << "======== THE END ===== TESTS CS201 ==========" << endl;
    return 0;
}
