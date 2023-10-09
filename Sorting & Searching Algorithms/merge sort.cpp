#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// firs virgn which is good but we want to elimnate 
//the process of creating more vectors in mergeSort funcion

//void merge(vector<int>&v, vector<int>v1, vector<int>v2){
//
//	int i = 0, j = 0, sz = 0;
//	while(i < v1.size() && j < v2.size()){
//		if(v1[i] <= v2[j]){
//			v[sz++] = v1[i++];
//		}
//		else {
//			v[sz++] = v2[j++];
//		}
//	}
//	
//	while(i < v1.size()){
//		v[sz++] = v1[i++];
//	}
//	while(j < v2.size()){
//		v[sz++] = v2[j++];
//	}
//}
//
//
//void mergeSort(vector<int>&v){
//	
//	if(v.size() < 2){
//		return ;
//	}
//	int mid = v.size()/2, j = 0;
//	vector<int>v1(mid); 
//	vector<int>v2(v.size()-mid);
//	
//    for(int i=0;i<v.size();++i){
//    	if(i < mid){
//    		v1[i] = v[i];
//		}
//		else {
//			v2[j++] = v[i];
//		}
//	}
//	
//	mergeSort(v1);
//	mergeSort(v2);
//	
//	merge(v,v1,v2);
//}


// the better one
void merge(vector<int>&v,int lo, int mid, int hi){
	
	int v1SZ = mid - lo + 1;
	int v2SZ = hi - mid;
	
	vector<int>v1(v1SZ);
	vector<int>v2(v2SZ);
	
	for(int i=0;i<v1SZ;++i){
		v1[i] = v[lo+i];
	}
	for(int j=0;j<v2SZ;++j){
		v2[j] = v[mid+j+1];
	}
	
	int i = 0, j = 0, sz = lo;
	
	while(i < v1SZ && j < v2SZ){
		if(v1[i] <= v2[j]){
			v[sz++] = v1[i++];
		}
		else {
			v[sz++] = v2[j++];
		}
	}
	
	while(i < v1SZ){
		v[sz++] = v1[i++];
	}
	while(j < v2SZ){
		v[sz++] = v2[j++];
	}
}

void mergeSort(vector<int>&v,int lo,int hi){
	if(lo >= hi){
		return;
	}
	int mid = lo + (hi - lo) / 2;
	
	mergeSort(v,lo,mid);
	mergeSort(v,mid+1,hi);
	
	merge(v,lo,mid,hi);
}

int main(){
	vector<int>v{8,2,1,9,9,3,2,0};
	mergeSort(v,0,v.size()-1);
	
	for(int c:v)
	    cout << c << " ";
	cin.get();
}
