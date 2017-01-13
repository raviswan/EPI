#include <iostream>
#include <memory>

template<typename T>
struct BSTNode{
	T data;
	std::unique_ptr<BSTNode<T>> left,right;
};


class BST{
private:
	std::unique_ptr<BSTNode<int>> root;
public:
	bool insertBST(int key){
		if (root==nullptr){
			std::unique_ptr<BSTNode<int>> newNode(new BSTNode<int>{key, nullptr,nullptr});
			return true;
		}
		else{
			BSTNode<int>* parent = nullptr;
			BSTNode<int>* curr = root.get();
			while(curr){
				if(key > curr->data){
					parent = curr;
					curr = curr->right.get();
				}
				else if (curr->data == key)
					return false;
				else{
					parent = curr;
					curr = curr->left.get();
				}
			}
			std::unique_ptr<BSTNode<int>> newNode(new BSTNode<int>{key, nullptr,nullptr});
			key > curr->data ? (curr->right = std::move(newNode)) : (curr->left = std::move(newNode));
		}
		return true;
	}

	bool deleteBST(int key){
		if (root==nullptr)
			return false;
		BSTNode<int>* curr = root.get();
		BSTNode<int>* parent = curr;
		while(curr){
			if(key < curr->data) {
				parent = curr;
				curr = curr->left.get();
			}
			else if(key > curr->data){
				parent = curr;
				curr = curr->right.get();
			}
			else{
				if(curr->left){
					while(curr->left){
						curr->data = curr->left->data;
						curr = curr->left.get();
					}
					delete(curr);
				}
				else if(curr->right){
					curr->data = curr->right->data;
					curr = curr->right.get();
					while(curr){
						curr->data = curr->left->data;
						curr = curr->left.get();
					}
					delete curr;
				}
				return true;
			}			
		return false;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}