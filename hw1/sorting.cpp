/**
* Title: Algorithm Efficiency and Sorting
* Author: Zeynep Cankara
* ID: 21703381
* Section: 2
* Assignment: 1
* Description: Cpp file for the sorting algorithms + performance analysis
*/

#include "sorting.h"
using namespace std;

// BUBBLE SORT
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, int size, int &compCount, int &moveCount){
    int boundary = size - 2;
    while (boundary >= 0) {
        for (int i = 0; i <= boundary; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                // swap makes 3 data moves
                moveCount += 3;
            }
            // comparison arr[i] > arr[i+1]
            compCount++;
        }
        boundary -= 1;
    }
}


// MERGE SORT
void mergeSort(int *arr, int size, int &compCount, int &moveCount){
    mergeSort(arr, 0, size-1, compCount, moveCount);
}


void mergeSort(int *arr, int start, int end, int &compCount, int &moveCount){
    if (start != end) {
        // step1: divide from middle
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, end, compCount, moveCount);

        // step2: conquer the divided steps
        merge(arr, start, mid, end, compCount, moveCount);
    }
}


void merge(int *arr, int start, int mid, int end, int &compCount, int &moveCount){
    // pointer to the first half
    int p1 = start;
    // pointer to the second half
    int p2 = mid+1;
    int *temp = new int[end - start + 1];
    int cnt = 0;
    while (p1 <= (mid) && p2 <= end) {
        if (arr[p2] < arr[p1]) {
            temp[cnt++] = arr[p2];
            p2 += 1;
        } else {
            temp[cnt++] = arr[p1];
            p1 += 1;
        }
        // 1 comparison
        compCount++;
        // 1 data movement
        moveCount++;
    }
    // check remeaning element in the first half
    // NOTE: p1 <= (mid) is not an array element comparison it is an index comparison
    while (p1 <= (mid)) {
        temp[cnt++] = arr[p1];
        p1 += 1;
        // 1 data movement
        moveCount++;
    }
    // check remeaning element in the second half
    // NOTE: p2 <= (end) is not an array element comparison it is an index comparison
    while (p2 <= end) {
        temp[cnt++] = arr[p2];
        p2 += 1;
        // 1 data movement
        moveCount++;
    }

    // copy elements over into the original array
    for (int i = 0; i < (cnt); i++) {
        arr[i + start] = temp[i];
        // 1 data movement
        moveCount++;
    }
    // deallocate the space
    delete [] temp;
}

// QUICK SORT
void quickSort(int *arr, int size, int &compCount, int &moveCount){
    quickSort( arr, 0, size-1, compCount, moveCount);
}

void quickSort(int *arr, int start, int end, int &compCount, int &moveCount){
    // choose the first element as pivot
    int pivotIdx;
    // divide the array from the partition
    if (start < end) {
        // divide from the pivot
        // start, pivot, end
        partition(arr, start, end, pivotIdx, compCount, moveCount);

        // sort the first half of the array
        quickSort(arr, start, pivotIdx - 1, compCount, moveCount);
        quickSort(arr, pivotIdx + 1, end, compCount, moveCount);
    }
}


void partition(int *arr, int start, int end, int &pivotIdx, int &compCount, int &moveCount){
    // initially pivot is unknown
    // you can code a choose pivot function as well, if you know your your data well
    // Choosing pivot as first element just like did in class
    int pivot = arr[start];
    // data move (assigning pivot)
    moveCount++;

    int endS1 = start;
    int firstUnknown = start + 1;

    // iterate through the unknown portion of the array
    while (firstUnknown <=  end) {
        if (arr[firstUnknown] < pivot) { // element < pivot
            endS1++;
            swap(arr[firstUnknown], arr[endS1]);
            // swap makes 3 data moves
            moveCount += 3;
        }
        // it belongs to the other array no need to swap
        // comparison: arr[i] < pivot
        compCount++;
        firstUnknown++;
    }
    // place the pivot to the proper place in the array
    swap(arr[start], arr[endS1]);
    // swap makes 3 data moves
    moveCount += 3;
    pivotIdx = endS1;
}

// Performance Analysis helper function function
void createArrays(int *arr1, int *arr2, int *arr3, int *arr4, int size){
    srand((int) time(NULL)); // random seed initialization
    for (int i = 0; i < size; i++) {
        int randNum = rand() % size + 1 ; // random number taking values in between [1:size]
        arr1[i] = randNum; // reserved for radix sort
        arr2[i] = randNum; // reserved for bubble sort
        arr3[i] = randNum; // reserved for quick sort
        arr4[i] = randNum; // reserved for merge sort
    }
}

void printHeader(string algoType){
    if (algoType == "radixSort") {
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part c - Time analysis of Radix Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << endl;
    } else if (algoType == "bubbleSort") {
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part c - Time analysis of Bubble Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    } else if (algoType == "quickSort"){
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part c - Time analysis of Quick Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    } else if(algoType == "mergeSort") {
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part c - Time analysis of Merge Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    } else {
        // invalid algorithm
        cout << "Invalid algorithm type...";
    }
}

string printPerformanceOut(int * arr, int size, string algoType){
    int compCount = 0;
    int moveCount = 0;
    string result = "";
    clock_t counter; // time elapsed
    if (algoType == "radixSort") {
        counter = clock();
        radixSort(arr, size);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "           " + to_string(timeElapsed) + " ms";
    } else if (algoType == "bubbleSort") {
        counter = clock();
        bubbleSort(arr, size, compCount, moveCount);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "          " + to_string(timeElapsed) + " ms     " + to_string(compCount)+ "        " + to_string(moveCount);
    } else if (algoType == "quickSort"){
        counter = clock();
        quickSort(arr, size, compCount, moveCount);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "          " + to_string(timeElapsed) + " ms      " + to_string(compCount)+ "       " + to_string(moveCount);
    } else if(algoType == "mergeSort") {
        counter = clock();
        mergeSort(arr, size, compCount, moveCount);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "            " + to_string(timeElapsed) + " ms       " + to_string(compCount)+ "         " + to_string(moveCount);
    } else {
        // invalid algorithm
        cout << "Invalid algorithm type...";
    }
    return result;
}

void getResult(int size, string *resArr){
    // alloc memory
    int *arr1 = new int[size];
    int *arr2 =  new int[size];
    int *arr3 =  new int[size];
    int *arr4 =  new int[size];
    createArrays(arr1, arr2, arr3, arr4, size);
    //printHeader("radixSort");
    string res1 = printPerformanceOut(arr1, size, "radixSort");
    string res2 = printPerformanceOut(arr2, size, "bubbleSort");
    string res3 = printPerformanceOut(arr3, size, "quickSort");
    string res4 = printPerformanceOut(arr4,size, "mergeSort");
    // write result into an array of strings
    resArr[0] = res1;
    resArr[1] = res2;
    resArr[2] = res3;
    resArr[3] = res4;
    // deallocate the memory
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}

void performanceAnalysis(){
    int algoSizes[8] = {2000, 6000, 10000, 14000, 18000, 22000, 26000, 30000};
    // 2D array for storing the result
    string resultArray[8][4];
    for (int i = 0; i < 8; i++) {
        string resArr[4];
        getResult(algoSizes[i], resArr);
        for (int j = 0; j < 4; j++) {
            resultArray[i][j] = resArr[j];
        }
    }
    // start the printing
    printHeader("radixSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][0] << endl;
    }
    printHeader("bubbleSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][1] << endl;
    }
    printHeader("quickSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][2] << endl;
    }
    printHeader("mergeSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][3] << endl;
    }

}


// RADIX SORT

// Function determines how many digits.By Vitali Taken from: https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
int numDigits(int number){
    int digits = 0;
    if (number < 0){
        digits = 1;
    }
    while (int(number != 0)) {
        number /= 10;
        digits++;
    }
    return digits;
}

int getMaxItemDigit(int *arr, int size){
    int numDigit = numDigits(arr[0]);
    for (int i = 0; i < size; i++) {
        if (numDigit < numDigits(arr[i]) ) {
            numDigit = numDigits(arr[i]);
        }
    }
    return numDigit;
}


void radixSort(int *arr, int size){
    int maxDigit = getMaxItemDigit(arr, size);
    radixSort(arr, size, maxDigit);
}

void radixSort(int *arr, int n, int numDigits){
    for (int j = 0; j < numDigits ; j++) {
        int array[10][n]; // 2D Array initialized to 0
        int countArray[10] = {0}; // Counter to count items in the arrays.
        //cout << "DEBUG: ---j change ------" << endl;
        for (int i = 0; i < n; i++){
            // place the digit to the corresponding place
            int k  = ((int)(arr[i]/pow(10, j)))%10; // last digit
            int pos = countArray[((int)(arr[i]/pow(10, j)))%10]; // increment the number

            //cout << "DEBUG: ---num elements in containers ------" << endl;
            //printArray(countArray, 10);
            //printArray(array[k], 10);

            array[ k ][pos] = arr[i]; // add the element to there
            countArray[(int)(arr[i]/pow(10, j))%10] = pos+1; // increment the number at the position
        }
        // get elements back and place to the array
        int curPos = 0;
        for (int i = 0; i < 10; i++) {
            // get the element write to the array
            int cur = 0;
            while(cur < countArray[i]){
                arr[curPos++] = array[i][cur];
                cur++;
            }
        }
    }
}

// PRINT ARRAY
void printArray(int *arr, int size){
    if (arr != NULL) {
        cout << "[";
        for(int i = 0; i < size-1; i++){
            cout << arr[i] << ", ";
        }
        cout << arr[size-1];
        cout << "]" << endl;
    } else {
        cout << "[]" << endl;
    }
}
