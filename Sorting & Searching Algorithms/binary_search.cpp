#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long k;
	cout<<"Enter the year you wanna know the year after that is distinct \n";
	int h;
	cin>>k;
	cout<<"Enter end year\n";
	cin>>h;
	cout<<"All the distinct years(have distinct digits) \n\n";
	bool sure=false;

	if(k>=1000&&k<=9000){
	    while(k>0&&k<h){
		
		    ++k;
		    int ahad=k%10;
		    int a3rt=k%100-ahad;
		    int m2at=k%1000-a3rt-ahad;
		    m2at/=100;
	     	a3rt/=10;
	    	int alaf=k/1000;

		    if(ahad!=a3rt&&ahad!=m2at&&ahad!=alaf&&a3rt!=m2at&&a3rt!=alaf&&alaf!=m2at){
			    cout<<k<<endl;
			    sure=true;
		    }
	    }
    }
    if(!sure)
       cout<<"there is no any year with distinct digits\n\n\n";
    system("pause");
}
