
//Use two stacks. Always return top() from first stack.
//Every time first stack becomes empty, transfter all contents over
//from second stack till the second becomes empty, before returning
//pop()
//For push(), if first stack empty add element, else add to second stack
//
#include <stack>
#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class Queue {
	private:
	stack<T> first;
	stack<T> second;
	public:
		void push(T a){
			if(first.empty())
				first.push(a);
			else{
				second.push(a);
			}
		}

		void pop(){
			if(!first.empty()){
				first.pop();
				if(first.empty()){
					while(!second.empty()){
						first.push(second.top());
						second.pop();
					}
				}
			}
			else{
				cout<<"error"<<endl;
				throw("error");
			}
		}


		T front(){
			if (!first.empty()){
				return first.top();
			}
			else{
				cout<<"error"<<endl;
				throw("error");
			}
		}
};

int main(){
	Queue<int> q;
	q.push(1);
	q.push(2);
	cout<<q.front()<<endl;
	q.pop();
	q.push(3);
	q.push(4);
	q.push(5);
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	q.push(41);
	q.pop();
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	q.push(77);
	cout<<q.front()<<endl;


}