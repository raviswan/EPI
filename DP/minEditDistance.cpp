/*
Minimum edit distance is used to determine the minimum edits needed to make string a == string b

the edits are insertion , deletion and substiution. here we assue each gets equal weight.

 //http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
//https://www.youtube.com/watch?v=We3YDTzNXEk&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=8

Here it is : 
The goal is to convert "column" word to "row" word
Remember to create one extra row and one extran column
If the two chars are equal, the box gets its left diagonal.
Else it is 1+ max of (left OR top OR left-diagonal neighbor)

regarding edits:
Walking back from right corner, if you go up, you insert that "row" char into the "column" word.
If you go left, you delete that char from the "column" word. If you move diagonally left, you substitute
that "column" char grid[i][j] with "row" char of gridi][j]
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


int minEditDistance(string a, string b){
	int cols = a.size();
	int rows = b.size();
	int grid[rows+1][cols+1];
	for(int k = 0; k<cols+1; ++k){
		grid[0][k] = k;
	}
	for(int k = 0; k<rows+1; ++k){
		grid[k][0] = k;
	}
	int minVal = 0;
	bool duplicate = false;
	for (int i = 1; i<rows + 1; ++i){
		for(int j=1;j<cols + 1; ++j){
			if (b[i-1] == a[j-1]){
				grid[i][j] = grid[i-1][j-1];
			}
			else{
				minVal = min(grid[i-1][j], grid[i][j-1]);
				grid[i][j] = 1 + min(minVal, grid[i-1][j-1]);
			}
		}
		duplicate = false;
	}
	//print matrix
	for(int i=0; i<rows+1; ++i){
		for(int j=0; j<cols+1; ++j)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}

	//Display the edits
	int i = rows;
	int j =  cols;
	//return the operation;
	cout<<" -----------------------------------------\n";
	cout << a <<" ---> "<<b<<":"<< endl;
	cout<<" -----------------------------------------\n";
	cout<<"Do the following (right to left)"<<endl;
	while(true){
		if(i==0 || j==0)
			break;

		if (b[i-1] == a[j-1]){
			--i;
			--j;
		}
		//move diagonally up, so substitute
		else if (grid[i][j] == (grid[i-1][j-1] + 1) ){
			cout<<"substitute "<<a[j-1]<<" with "<<b[i-1]<<endl;
			--i;
			--j;
		}
		//moving left, so delete col value
		else if (grid[i][j] == (grid[i][j-1] + 1)){
			cout<<"delete "<<a[j-1]<<endl;
			--j;
		}
		//moving up, so insert row value
		else if (grid[i][j] == (grid[i-1][j] + 1)){
			cout<<"insert "<<b[i-1]<<endl;
			--i;
		}

	}
	while(i){
		cout<<"insert "<<b[i-1]<<endl;
		--i;
	}
	while(j){
		cout<<"delete "<<a[j-1]<<endl;
		--j;
	}


	return grid[rows][cols];

}



int main(){
	string a = "Maya";
	string b = "Ashwini";
	//string a = "geek";
	//string b = "gesek";
	//string a = "sunday";
	//string b = "saturday";
	//string a = "intention";
	//string b = "execution";
	//string a ="abcd";
	//string b = "abcd";
	cout<<minEditDistance(a, b) <<endl;
}