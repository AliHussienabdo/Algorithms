#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "..\Linked_list\queue_list.h"
//#include "stack_List.h"
#include "TreeNode.h"
#include <string>
#include <vector>
#include <algorithm>
template<typename NODETYPE>
class Tree{
	public:// insert node in Tree
        void insertNode(const NODETYPE& value) {
            insertNodeHelper(&rootPtr, value); 
        } 
        // begin preorder traversal of Tree
        void preOrderTraversal() const {
            preOrderHelper(rootPtr); 
        } 
        // begin inorder traversal of Tree
        void inOrderTraversal() const {
		     inOrderHelper(rootPtr);
		}
        void OutPutTree() const {       	
            OutPutTreeHelper(rootPtr, 0); 
        } 
        // begin postorder traversal of Tree
        void postOrderTraversal() const {
        	
            postOrderHelper(rootPtr); 
        } 
        
        int getDepth(){
			return DepthHelper(rootPtr);
		}
		
		void levelOrderTraversal(){
			LevelOrderHelper(rootPtr);
		}
		//Tree distructor
		~Tree(){
			std::cout << "\n\n\nDistructor, Delete TreeNodes... \n";
			clearTreeHelper(rootPtr);
			rootPtr = nullptr;
		}
		
    private:
    	TreeNode<NODETYPE>* rootPtr = nullptr;
    	
    	void clearTreeHelper(TreeNode<NODETYPE>* ptr){
    		if(ptr != nullptr){
    			clearTreeHelper(ptr->leftPtr);
    			clearTreeHelper(ptr->rightPtr);
    			std::cout << ptr->data << std::endl;
    			delete ptr;
			}
		}
    	
    	void insertNodeHelper(TreeNode<NODETYPE>**ptr,const NODETYPE& value){
    		if(*ptr == nullptr){
    			*ptr = new TreeNode<NODETYPE>(value);
			}
			else {
				if(value < (*ptr)->data){
					insertNodeHelper(&((*ptr)->leftPtr), value);
			    }
			    else if(value > (*ptr)->data){
			    	insertNodeHelper(&((*ptr)->rightPtr), value);
				}
				else {
					std::cout<<"The value : "<<(*ptr)->data
					        << " is existed in the Tree..Try another\n";
				}
			}
		}
		
		void inOrderHelper(TreeNode<NODETYPE>* ptr)const{
			if(ptr != nullptr){
				inOrderHelper(ptr->leftPtr );
				std::cout << ptr->data << '\n';
				inOrderHelper(ptr->rightPtr); 
			}
		}
		
		void OutPutTreeHelper(TreeNode<NODETYPE>* ptr,int totalSpaces)const{
			if(ptr != nullptr){
				OutPutTreeHelper(ptr->rightPtr ,totalSpaces + 5);
				for(int i=0;i<totalSpaces; ++i) {
					std::cout<<' ';
				}
				std::cout << ptr->data << '\n';
				OutPutTreeHelper(ptr->leftPtr , totalSpaces + 5); 
			}
		}
		
		void preOrderHelper(TreeNode<NODETYPE>* ptr)const{
			if(ptr != nullptr){
				std::cout << ptr->data << ' '; // process node               
                preOrderHelper(ptr->leftPtr); // traverse left subtree  
                preOrderHelper(ptr->rightPtr); // traverse right subtree
			}
		}
		
		void postOrderHelper(TreeNode<NODETYPE>* ptr)const{
			if(ptr != nullptr){	
                postOrderHelper(ptr->leftPtr); // traverse left subtree  
                postOrderHelper(ptr->rightPtr); // traverse right subtree
                std::cout << ptr->data << ' '; // process node                
            } 
		}
		
		int DepthHelper(TreeNode<NODETYPE>* root){
			if(root == nullptr){
				return -1;
			}
			int leftHight = DepthHelper(root->leftPtr);
			int rightHight = DepthHelper(root->rightPtr);
			
			return (leftHight > rightHight)? leftHight + 1 : rightHight + 1;
		}
		
		void LevelOrderHelper(TreeNode<NODETYPE>* root){
			
			Queue<TreeNode<NODETYPE>*>q;
			TreeNode<NODETYPE>* temp;
			q.enqueue(root);
			
			while(!q.isQueueEmpty()){
				q.dequeue(temp);
				std::cout << temp->getData() << std::endl;
				if(temp->leftPtr != nullptr){
					q.enqueue(temp->leftPtr);	
				}
				if(temp->rightPtr != nullptr){
					q.enqueue(temp->rightPtr);
				}
			}
		}
};
#endif
