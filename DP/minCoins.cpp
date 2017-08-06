
/*
This code is to get minimum number of coins in a given sum. The coins are of 
denominations 1,3,5
*/

//https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/

/**
Base case is for any suym <= 0; num of coins = 0;
for sum=1, it is 1+ value (num_coins==0) = 1
for sum =2, it is 1+ value(num_coins==1) = 1 +1 = 2
for sum = 3, it is:
			For Coin1: 1 + value(numCoins ==3 - 1) = 1 + value(numCoins ==2) = 3
			For Coin3: 1 + value(numCoins ==3 - 3) = 1 + value(numCoins ==0) = 1
*/
			
#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> coins = {1,3,5};


int getMinimum(vector<int>& v, int sum){
	int minVal = v[0];
	for(int i=1; i< v.size();++i)
		minVal = (v[i] < minVal) ? v[i]: minVal;
	return minVal;
}
int getMinCoins(int sum){
	if(sum <= 0)
		return 0;
	int i = 0;
	vector<int> minC;
	while(i<coins.size() && coins[i]<= sum){
		minC.push_back(1+getMinCoins(sum - coins[i]));
		++i;
	}
	return getMinimum(minC, sum);
}

int main(){
	vector<int> v= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,21};
	for(auto& i: v){
		cout<<i<<" needs "<<getMinCoins(i)<<" coins"<<endl;
	}
	
	return 0;
}