/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 
So a string of length n has 2^n different possible subsequences.

It is a classic computer science problem, the basis of diff (a file comparison program that 
outputs the differences between two files), and has applications in bioinformatics.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Number of subsequences in a string:
https://math.stackexchange.com/questions/982949/number-of-subsequences-in-a-string

DP SOLUTION EXPLANATION:
https://www.youtube.com/watch?v=NnD96abizww

1) Remember to create one extra row and one extran column initialized with zeros.
2) Here it is : every box is 1+ value of its left diagonal neighbor if the two chars are equal.
3) Else it is max of left OR  top neighbor.

Printing the sequence.
start from right corner. Work way up. Only when you move left diagnoally, you 
add the char to the end result. Keep track of each string index. So when you 
go up, subtract rowIndex, when you go left, subtrace colIndex.

*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;


// void printgrid(int* grid, int rows, int cols){
// 	for(int i=0; i<=rows; ++i){
// 		for(int j=0; j<=cols;++j){
// 			cout<<grid[i][j]<< " ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;
// }
void longestCommonSubSequence(string& first, string& second){
	int cols = first.size();
	int rows = second.size();
	int grid[rows+1][cols+1];
	vector<char> res;
	for(int k=0;k < cols+1;++k){
		grid[0][k] = 0;
	}
	for(int k=0;k < rows+1;++k){
		grid[k][0] = 0;
	}
	
	for(int i=1; i< rows+1; ++i){
		for (int j=1; j< cols+1; ++j){
			if(second[i-1] == first[j-1]){
				grid[i][j] = grid[i-1][j-1] + 1;
			}
			else{
				grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
			}
		}
	}
	int i= rows;
	int j= cols;
	int sIndex = second.size() - 1;
	int fIndex = first.size() - 1;
	/*------compute common sequence------*/
	while(grid[i][j] != 0){
		if(grid[i][j] == grid[i-1][j]){
			--i;
			--sIndex;
		}
		else if(grid[i][j] == grid[i][j-1]){
			--j;
			--fIndex;
		}
		else if(grid[i][j] == (1+ grid[i-1][j-1])){
			cout<<"grid value = "<<grid[i][j]<<" is for "<<first[i-1]<<endl;
			res.push_back(first[fIndex--]);
			--sIndex;
			--i;
			--j;
		}
	}

	//-------print array
	cout<<"    ";
	for(auto& c : first){
		cout<<c<<" ";
	}
	cout<<endl;
	cout<<"  ";
	for(int k=0;k < cols+1;++k){
		cout<<grid[0][k]<<" ";
	}
	cout<<endl;
	for(int i=1; i<rows+1; ++i){
		if(i<=second.size())
			cout<<second[i-1]<<" ";
		for(int j=0; j< cols+1;++j){
			//cout<<"gr id["<<i<<"],["<<j<<"]"<<" = "<<grid[i][j]<<endl;
			cout<<grid[i][j]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"longest sequence length is "<<res.size()<<endl;
	reverse(res.begin(), res.end());
	for(auto& i: res){
		cout<<i;
	}
	cout<<endl;

}

int main(){
	string first = "AshBalan"; 
	string second = "GeethaBalan";  
	longestCommonSubSequence(first, second);
	return 0;
}