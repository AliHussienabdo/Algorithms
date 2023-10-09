#ifndef TREE2_H
#define TREE2_H
#include "TreeNode.h"
#include "Tree.h"
template<typename NODETYPE>
class Tree2 : public Tree<NODETYPE>{
	
//	public:
//		
//	private:
//		void determineDepth(TreeNode<NODETYPE>* Ptr,int& totPtr,int& currPtr ){
//			if(Ptr != nullptr){
//				++currPtr;
//				
//				if(currPtr > totPtr){
//					totPtr = currPtr;
//				}
//				
//				determineDepth(Ptr->getLeftPtr(), totPtr, currPtr);
//			    determineDepth(Ptr->getRightPtr(), totPtr, currPtr);
//			    --currPtr;
//			}
//		}
};


#endif
