/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 1
 * Description: Main file for the testing sorting algorithms + performance analysis
 */

#include <iostream>
#include "sorting.h"
using namespace std;
int main() {
    // Start the test BubbleSort
    cout << "Bubble Sort Test" << endl;
    int compCount = 0;
    int moveCount = 0;
    int arrayTestBubble[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,
        14,2,8,10,5};
    bubbleSort(arrayTestBubble, 16, compCount, moveCount);
    printArray(arrayTestBubble, 16);
    // Start the test QuickSort
    cout << " Quick Sort Test" << endl;
    int arrayTestQuick[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,
        14,2,8,10,5};
    compCount = 0;
    moveCount = 0;
    quickSort(arrayTestQuick, 16, compCount, moveCount);
    printArray(arrayTestQuick, 16);
    // start test MergeSort
    cout << " Merge Sort Test" << endl;
    int arrayTestMerge[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,
        14,2,8,10,5};
    compCount = 0;
    moveCount = 0;
    mergeSort(arrayTestMerge, 16, compCount, moveCount);
    printArray(arrayTestMerge, 16);
    // start test RadixSort
     cout << " Radix Sort Test" << endl;
    int arrayTestRadix[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11,
        14,2,8,10,5};
    radixSort(arrayTestRadix, 16);
    printArray(arrayTestRadix, 16);
    // Performance Analysis
    cout << " Start the Performance Analysis" << endl;
    performanceAnalysis();
    
    return 0;
}
