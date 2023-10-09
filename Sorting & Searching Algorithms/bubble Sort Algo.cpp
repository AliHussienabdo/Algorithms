#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < (size-1); ++step) {
      
    // check if swapping occurs
    int swapped = 0;
    
    // loop to compare two elements
    for (int i = 0; i < (size-step-1); ++i) {
        
      // compare two array elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping occurs if elements
        // are not in intended order 
        swap(array[i] , array[i + 1]);
        
        swapped = 1;
      }
    }

    // no swapping means the array is already sorted
    // so no need of further comparison
    if (swapped == 0)
      break;
  }
}
//
//void bubbleSort(int array[], int size) {
//
//  // loop to access each array element
//  for (int step = 0; step < size; ++step) {
//      
//    // loop to compare array elements
//    for (int i = 0; i < size - step; ++i) {
//
//      // compare two adjacent elements
//      // change > to < to sort in descending order
//      if (array[i] > array[i + 1]) {
//
//        // swapping elements if elements
//        // are not in the intended order
//        swap(array[i] , array[i + 1]);
//      }
//    }
//  }
//}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int size = 5;
  int data[size] = {-2, 45, 0, 11, -9};
  
  bubbleSort(data, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}
