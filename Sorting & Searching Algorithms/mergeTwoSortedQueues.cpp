#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>>q1,q2;
    cout << "insrt q1 values\n";
    for(int i=0;i<10;i++) q1.push(i);
    cout << "insrt q2 values\n";
    for(int i=0;i<10;i++) q2.push(i);

    vector<int>v;

    while(!q1.empty() && !q2.empty()){

        if(q1.top() < q2.top()){
            v.push_back(q1.top());
            q1.pop(); 
        }
        else {
            v.push_back(q2.top());
            q2.pop();
        }
    }

    while(!q1.empty()){
        v.push_back(q1.top());
        q1.pop();
    }

    while(!q2.empty()){
        v.push_back(q2.top());
        q2.pop();
    }

    for(int vl:v) cout << vl << " ";

    cout << "\n********************************\n";

    cin.get();
}