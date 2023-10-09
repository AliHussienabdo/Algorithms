#include <iostream>
#include <vector>
using namespace std;

// void print(int[]);
// void insertion_sort(int arr[]){
//     // selection sort
//     // int small = 0;
//     // for(int i=0;i<5;++i){
//     //     small = i;
//     //     for(int j=i+1;j<5;++j){
//     //         if(arr[j] < arr[small]) small = j;
//     //     }
//     //     swap(arr[i],arr[small]);
//     // }
    
//     //insertion sort
//     // for(int i=1;i < 5;++i){
//     //     //int key = arr[i];
//     //     int j = i;
//     //     while(j > 0 && arr[j] > arr[j-1] ){
//     //         swap(arr[j],arr[j-1]);
//     //         --j;
//     //     }
//     // }
// }

void merge(vector<int>&v,int l,int mid,int r){
    // int leftSz = mid - l;
    // int rightSz = r - mid; 0 1 
    int lfsz = mid - l + 1;
    int rgsz = r - mid;

    vector<int>left(lfsz);
    vector<int>right(rgsz);

    for(int i=0;i<lfsz;++i){
        left[i] = v[l + i];
    }
    for(int i=0;i<rgsz;++i){
        right[i] = v[mid + i + 1];
    }

    int i = 0 , j = 0, k = l;

    while(j < right.size() && i < left.size()){
        if(left[i] <= right[j]){
            v[k] = left[i++];
        }
        else {
            v[k] = right[j++];
        }
        ++k;
    }

    while(j < right.size()){
        v[k++] = right[j++];
    }
    while(i < left.size()){
        v[k++] = left[i++];
    }

}

void merge_sort(vector<int>&v,int l,int r){
    if(l >= r) return;
    int mid = (l+r)/2;

    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);

    merge(v,l,mid,r);
}


int main(){
    vector<int>v{1,92,3,9,22,9,11,22,0,-2};
    merge_sort(v,0,v.size()-1);
    for(int c:v) cout << c << " ";
    
}
