#include <iostream>
using namespace std;

// function to print the array
void printArray(int array[], int size) ;

void TreeWayPartition(int arr[], int low,int high){
	if(low >= high) return;

	int it = low;
	int i = low + 1;
	int gr = high;

	while(i <= gr){
		if(arr[i] == arr[it]) ++i;
		if(arr[i] < arr[it]){
			swap(arr[i], arr[it]);
			++i;
			++it;
		}
		if(arr[i] > arr[it]){
			swap(arr[i], arr[gr]);
			--gr;
		}
	}

	TreeWayPartition(arr,low,it-1);
	TreeWayPartition(arr,gr+1,high);
}

// function to rearrange array (find the partition point)
int partition(int arr[], int low, int high) {
	
	int i = low;
	int j= high;
	int pivLoc = i ;
	while(true){
		while(arr[pivLoc] <= arr[j] && pivLoc != j ){
			--j;
		}
		if(pivLoc == j){
			break;
		}
		else if (arr[pivLoc] > arr[j]) {
			swap(arr[pivLoc] , arr[j]);
			pivLoc = j;
		}
		while(arr[pivLoc] >= arr[i] && pivLoc != i){
			++i;
		}
		if(pivLoc == i ){
			break;
		}
		else if(arr[pivLoc] < arr[i]){
			swap(arr[pivLoc] , arr[i] );
			pivLoc = i;
		}

	}
	return pivLoc;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Driver code
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Unsorted Array: \n";
  printArray(data, n);
  
  // perform quicksort on data
  TreeWayPartition(data, 0, n - 1);
  
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
