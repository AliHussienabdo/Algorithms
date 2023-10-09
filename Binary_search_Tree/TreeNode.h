#ifndef TREENODE_H
#define TREENODE_H
//forward declaration class tree
template<typename NODETYPE> class Tree;

template<typename NODETYPE>
class TreeNode{
	friend class Tree<NODETYPE>;
	//friend class Tree2<NODETYPE>;
	public:
		TreeNode(const NODETYPE& value)
		: data(value) {}
		
		TreeNode* getLeftPtr() const {
			return leftPtr;
		}
		TreeNode* getRightPtr() const {
			return rightPtr;
		}
		
		NODETYPE getData() const{
			return data;
		}
	private:
		NODETYPE data;
		TreeNode<NODETYPE>* leftPtr = nullptr; 
		TreeNode<NODETYPE>* rightPtr = nullptr;
};

#endif
