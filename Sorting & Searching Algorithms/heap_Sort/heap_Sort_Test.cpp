#include <iostream>
#include <vector>
#include "maxHeap.h"
using namespace std;

int main(){
    vector<int>v{2,3,2,12,0,1234,9,-1,3,2,12,0,1234,9,-1};
    maxHeap mx(v);
    //mx.insert(3);
    mx.HeapSort();
    cout << '\n' << mx.isItMaxHeap() << endl;
    cin.get();

    //maxHeap mxhp(vector<int>{1,9,2,11,21,0,-1,2});
}