/*Count number of ways to cover a distance
Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

Input:  n = 3
Output: 4
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

Input:  n = 4
Output: 7
*/

const int N =4;
#include <iostream>

using namespace std;

// 4 :
// 1 1 1 1 
// 1 2 1
// 1 1 2
// 1 3
// 2 2 
// 3 1
// 2 1 1



int countSteps(int n, int* memo){
	if (n<0)
		return 0;
	if (n==0)
		return 1;
	if(memo[n] == 0)
	 	memo[n] = countSteps(n-3, memo) + countSteps(n-2, memo) + countSteps(n-1, memo);
	return memo[n];

}

int main(){
	int n = 4;
	int* memo = new int[n+1];
	cout<<countSteps(4, memo)<<endl;
}
