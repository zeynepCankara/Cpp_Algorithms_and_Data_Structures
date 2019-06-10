/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Driver file which reads from a input file called as input.txt and performs Huffman Coding  Outputs the huffman coding pattern on a file called as output.txt
 */

#include <iostream> // cout
#include <fstream> // file read and write

#include "HuffmanCode.h"
using namespace std;

int main() {
    // insert code here...
    cout << "Driver (Test) program of Homework 03\n";
    // read from input file
    ifstream inputF;
    inputF.open("./input.txt");
    if (!inputF) {
        cout << "ERROR: file not opened!!!" << endl; //if failed to open the file
    } else {
        // initialize the Huffman Tree
        HuffmanCode huffmanTree;
        int pqSize; // number of elements in the priority queue
        inputF >> pqSize; // read size of priority queue from the file
        // declare the priority queue
        for (int i = 0; i < pqSize; i++) { //read huffman heap items
            int freq;
            char character;
            // read character and frequency from the txt file
            inputF >> character >> freq;
            // insert a node with given character and frequency into the huffman tree's priority queue
            huffmanTree.hcInsert(freq, character);
        }
        // initialize the root of the huffman tree
        huffmanTree.createHuffmanTree();
        // close the input file stream
        inputF.close();
        // obtain the pattern and write on an output file
        huffmanTree.getCodingPattern();
    }
    return 0;
}


