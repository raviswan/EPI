/*This generates permutations by just walking through numbers 0 to 2^n - 1,
where n is the size of input vector.
For each 1 in the number, put a corresponding index of vector in the set
for e.g.
input vec = [3,5,7]
Output will be generated as follows:

000		---> []
001 -> [3]
010	-> [5]
011	-> [5,3]
100	-> [7]
101 -> [7,3]
110	-> [7,5]
111	-> [7,5,3]

Look at Gray code geneeration where every bit varies from its predecessor by only one bit
http://code.geeksforgeeks.org/rwG87C

Recursive
http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
https://discuss.leetcode.com/topic/5881/my-elegant-recursive-c-solution-with-inline-explanation
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> generatePermutations(vector<int> v){
	unsigned int num = 0;
	unsigned int left = 0;
	vector<vector<int>> res ;
	vector<int> temp;
	int len= pow(2,v.size());
	int shiftCount;
	for(int i =0 ;i < (1<<v.size()); ++i){
		shiftCount = 0;
		temp.clear();
		while(shiftCount < v.size()){
			if(i & (1<<shiftCount) )
				temp.push_back(v[shiftCount]);
			++shiftCount;
		}
		res.push_back(temp);
	}
	return res;

}

void permuteHelper(vector<int>& nums, vector<int>& out, vector<vector<int>>& res, int index){
        if (index >= nums.size()){
        	for(auto&i : nums)
        		cout<<i<<" ";
        	cout<<endl;
            res.push_back(nums);
            return;
         }
        for(int i=index; i<nums.size();++i){
        	cout<<"Part1: swap index = "<<index<<" with i="<<i<<endl;
            swap(nums[index], nums[i]);
            permuteHelper(nums, out, res, index+1);
            cout<<"Par2: swap index = "<<index<<" with i= "<<i<<endl;
            swap(nums[index], nums[i]);
        }
        
}

//recursive solution
//

 vector<vector<int>> permute(vector<int>& nums) {
        vector<int> out; 
        vector<vector<int>> res;
        permuteHelper(nums, out, res, 0);
        return res;   
 }


int main(){
	vector<int> v = {1,2,3};
	vector<vector<int>>  res;
	//res = generatePermutations(v);
	res = permute(v);
	for(auto&e : res){
		for(auto& i: e)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}