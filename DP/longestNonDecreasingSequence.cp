//https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/

/** Find the longest non-decreasing seuquence in a given array
The basic algo is:
1)For any i in vector v[i], longest seq, res[i] is set to 1. 
	a) For all v[j] for j< i; check to see if v[j] <= v[i]. If so, set res[i] = res[j] + 1;
2) Find max of res[i] for all i
**/

#include <iostream>
#include <vector>
using namespace std;

int longestSequence(vector<int>& v){
	int maxLen = 1;
	vector<int> res;
	res.push_back(1);
	for(int i=1; i< v.size(); ++i){
	 	res.push_back(1);
	 	for(int j=0; j < i; j++){
	 		if(v[j]<=v[i] && res[j] +1 > res[i]){
	 			res[i] = res[j] + 1;
	 		}
	 	}
	 	maxLen = res[i] > maxLen ? res[i]: maxLen;
	}
	return maxLen;
}

int main(){
	//vector<int> v ={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 3, 11, 7, 15};
	//vector<int> v ={10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> v = {1, 2 ,3, 4, 10, 5, 6, 7};
	cout<<longestSequence(v);
	return 0;
}