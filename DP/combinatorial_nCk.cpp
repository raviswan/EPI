//https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c
//No DP here
#include <iostream>
#include <vector>


using namespace std;
static int cnt = 1;

void printCombo(vector<int>& v){
	for(auto&i : v)
		cout<<i<<" ";
	cout<<endl;
}
void computeComboHelper(int k, vector<int>&input, vector<int>& output, int index){
	if(k==0){
		cout<<cnt++<<endl;
		printCombo(output);
		return;
	}
	for(int i=index; i<=input.size()-k; ++i){
		//cout<<"index ="<<i<<endl;
		output.push_back(input[i]);
		computeComboHelper(k-1, input, output, i+1);
		output.pop_back();
	}

	
}

void computeCombo(int n, int k){
	vector<int> input;
	vector<int> output;
	for(int i=0; i< n;++i){
		input.push_back(i+1);
	}
	computeComboHelper(k, input, output, 0);
}

int main(){
	
	computeCombo(7,3);
	return 0;
}