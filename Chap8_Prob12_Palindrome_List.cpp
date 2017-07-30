#include <iostream>
#include <memory>

template<typename T>
struct Node{
	T data;
	std::shared_ptr<Node<T>> next;
};


bool checkListForPalindrome(std::shared_ptr<Node<int>> head){
	
	auto slow = head;
	auto fast = head;
	while(fast!= nullptr && fast->next != nullptr){
		fast = fast->next->next;
		slow = slow->next;
	}
	
	auto first_half= head;
	auto second_half = reverseList(slow->next);
	while(second_half  && first_half){
		if(second_half->data != first_half->data)
			return false;
		}
		first_half=first_half->next;
		second_half=second_half->next;
	}
	return true;
}