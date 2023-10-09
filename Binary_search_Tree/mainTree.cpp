// Creating and traversing a binary tree.
#include <iostream>
#include <iomanip>
#include <string>
#include "Tree.h" 
//#include "Tree2.h"
#include <sstream>
using namespace std;

int main() {
	//SOCKET a;
	Tree<int>t2;
	t2.insertNode(20);//      20  
	t2.insertNode(10);//  10        30
	t2.insertNode(5);// 5     20       40
	t2.insertNode(30);//      
	t2.insertNode(40);
	t2.insertNode(45);
	t2.insertNode(15);
	t2.OutPutTree();


	cin.get();

	
//	t2.levelOrderTraversal();

//	cout<< t2.getDepth();
} 
