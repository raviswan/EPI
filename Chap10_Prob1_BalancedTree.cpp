//check if the tree is balanced
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct BinTreeNode{
	T data;
	unique_ptr<BinTreeNode<T>> left, right;
};



pair<bool, int> checkBalancedTree(const unique_ptr<BinTreeNode<int>>& tree){
	if(tree == nullptr){
		return make_pair(true,-1);
	}
	pair<bool, int> leftSubTree = checkBalancedTree(tree->left);
	if(!leftSubTree.first)
		return make_pair(false,0);
	pair<bool, int> rightSubTree = checkBalancedTree(tree->right);
	if(!rightSubTree.first)
		return make_pair(false,0);
	bool isBalanced = abs(leftSubTree.second - rightSubTree.second) <= 1;
	return (make_pair(isBalanced, max(leftSubTree.second, rightSubTree.second)+1));

}

bool isBalancedTree(const unique_ptr<BinTreeNode<int>>& tree){
	return checkBalancedTree(tree).first;
}

int main(){
	BinTreeNode<int> tree;
	tree.data = 1;
	tree.left = nullptr;
	tree.right = nullptr;
	unique_ptr<BinTreeNode<int>> treePtr (&tree);
	isBalancedTree(treePtr);
	return 1;
}