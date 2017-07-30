#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

//Reverse Polish Notation
int flag = 1;
int compute(stack<string>& s, stack<int>& si, string op){
	int op1, op2;
	if(op=="-" && s.empty()){
		flag = -1;
		return flag;
	}
	op2 = stoi(s.top());
	s.pop();
	if(!si.empty()){
		op1 = si.top();
		si.pop();
	}
	else{
		op1 = stoi(s.top());
		s.pop();
	}

	if  (op == "+")
		si.push(op1+op2);
	else if  (op == "-")
		si.push(op1-op2);
	else if  (op == "*")
		si.push(op1*op2);
	else
		si.push(op1/op2);

	cout<<si.top()<<endl;
	return si.top();
	
}

int rpn(string& str){
	stringstream ss;
	ss<<str;
	string input;
	int val = 0;
	int i = 0;
	stack<string> s;
	stack<int> si;
	while(getline(ss,input,',')){
		if(input == "+"|| input == "-" || input == "*" || input == "/"){
			val = compute(s, si, input);
		}
		else{
			s.push(input);
		}
	}
	return flag*val;
	
}

int main(){
	string s("-,6,3,/,2,+,2,*");
	cout<<rpn(s)<<endl;
}