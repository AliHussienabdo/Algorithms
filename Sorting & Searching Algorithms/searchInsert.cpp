#include <iostream>
#include <vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    for(int x=0;x<nums.size();++x){
        if(target == nums[x]){
            return x;
        }
        else if (target > nums[x] && target < nums[x+1]){
            return x+1;
        }
    }
    return 0;
}

int main(){
	vector<int>n={1,3,7,9};
	int target = 5;
	cout<<searchInsert(n,target);
}
