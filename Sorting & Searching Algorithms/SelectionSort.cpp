#include <iostream>
using namespace std;

void swapStr(char &a , char &b){
	char c = b;
	b = a;
	a = c;
}

void sortArr(string str){
	
	int min_in;
	for(int x=0;x<str.size()-1;x++){
		min_in=x;
		for(int i=x+1;i<str.size();i++){
			if(int(str[i])<int(str[min_in]))
				min_in = i;  // index for the smallest value
		}
		swapStr(str[x],str[min_in]);
	}
}

int main(){
	
	string a = "samer";
	sortArr(a);
	cout<<a;
	return 0;
}
//void sortArr(int arr[],int n){
//	
//	int min_in,x,i;
//	for( x=0;x<n-1;x++){
//		min_in=x;
//		for( i=x+1;i<n;i++){
//			if(arr[i]<arr[min_in])
//				min_in = i;  // index for the smallest value
//		}
//		swap(arr[x],arr[min_in]);
//	}
//}
//
//int main(){
//	
//	int n;
//	cout<<"Enter the size of array you wanna sort/ selection sort\n";
//	cin>>n;
//	int arr[n];
//	cout<<"Enter the array's values\n";
//	for(int x=0;x<n;++x){
//		cin>>arr[x];
//	}
//
//	cout<<"the array element before sorting\n";
//	for(int i=0;i<n;++i){
//		cout<<arr[i]<<" ";
//	}
//	
//	sortArr(arr,n);
//	
//	cout<<"\nthe array element after sorting\n";
//	for(int i=0;i<n;++i){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//	system("pause");
//	return 0;
//}
