/**There are two approacjes here:
One is the standard dynamic programming approach where you create a matrix
with one extra row and col

Each row correspondes to one element of input vector, with first row being empty
Each col indicating representing a value in the range[0, sum].
 Rules are:
 Each box takes value from row above if the row above is true
 If row above is false, and the row value < col Value, fill False
 Else, from row above, count 'row' boxes to left, fetch the value from that box, and drop it here.
If the final box on the right corner is true, subset sum exists.

To trace the subset sum, follow the True path. When the true comes from another true above it , keep going up.
When value above is false, move left by value of row. repeat the above.


Second approach: To generate all permutations, and check for sum while creating the permutations.
That would give back the result
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSubsetSumPresent(vector<int>& v, int sum){
	int rows = v.size()+ 1;
	int cols = sum + 1;
	int out[cols];
	bool a[rows][cols];
	int colIndex = 0;;
	vector<int> subsum;
	//initialization
	//initialize out array
	for(int i=0; i<=sum; ++i){
		out[i] = i;
	}
	cout<<endl<<endl;
	//initialize first col with all true as all of v can be sum 0  i.e. empty set
	for (int i=0;i<rows;++i){
		a[i][0] = true;
	}
	//initialize cols with all false, which means when there are no elements in input array, no subsum will
	//return true
	for (int j=1;j<cols;++j){
		a[0][j] = false;
	}

	//start the logic of capturing true or false
	for(int i=1; i< rows; ++i){
		for(int j=1; j<cols; ++j){
			if(a[i-1][j] == true)
				a[i][j] = true;
			else{
				if(v[i-1] > j)
					a[i][j] = false;
				else{
					colIndex = j - v[i-1];
					a[i][j] = a[i-1][colIndex];
				}
			}
		}
	}
	cout<<" ";
	for(int i=0; i<=sum; ++i){
		cout<<out[i]<<" ";
	}
	cout<<"\n\n";
	for(int i= 0; i< rows; ++i){
		//cout<<v[i]<<" ";
		cout<<" ";
		for (int j=0; j< cols; ++j){
			cout<<a[i][j]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;

	//Traversing the array to find the subset
	int i = rows-1; int j =  cols -1;

	if(a[i][j]){
		while(i > 0  && j>0){
			//if true, check the element right above.
			// If element above is true, keep going up
			//If element above is false, capture that num from input vetctor and move that many cols to left 
			if (a[i][j] == true){	
				if(a[i-1][j] != true){
					subsum.push_back(v[i-1]);
					j -= v[i-1];
				}
			}
			--i;
		}
		cout<<endl;
		for(auto&i : subsum){
		 cout<<i<<" ";
		}
		cout<<endl;
		return true;
	}
	else{
		cout<<"subsets can't sum up to "<<sum<<endl;
		return false;
	}

}

/*Second approach*/
vector<vector<int>> checkSubSetSum(vector<int> v, int sum){
	unsigned int num = 0;
	unsigned int left = 0;
	vector<vector<int>> res ;
	vector<int> temp;
	int len= pow(2,v.size());
	int shiftCount;
	int tot = 0;
	for(int i =0 ;i < len; ++i){
		shiftCount = 0;
		temp.clear();
		tot = 0;
		while(shiftCount < v.size()){
			if(i & (1<<shiftCount) ){
				tot += v[shiftCount];
				temp.push_back(v[shiftCount]);
			}
			++shiftCount;
		}
		if(tot == sum){
			res.push_back(temp);
		}
	}
	return res;

}

int main(){
	vector<int> v = {2, 3, 5, 6, 8, 10};
	vector<vector<int>> res;
	int sum = 10;
	isSubsetSumPresent(v, sum);
	res = checkSubSetSum(v, sum);
	cout<<" ---Approach 2: the subsets that sum to "<<sum<<endl;
	for(auto& i: res){
		for(auto&e : i){
			cout<<e<<" ";
		}
		cout<<endl;
	}
	return 0;
}
