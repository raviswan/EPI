//Return the index of next largest element in a sorted array of integers
#include <iostream>
#include <vector>

using namespace std;

int bsearch_next_largest(vector<int>& v, int key, unsigned int low, unsigned int high){
	unsigned int mid;
	int result = v.size() - 1;
	while (low <= high){
		mid = low + (high-low)/2;
		if (v[mid] > key){
			if (mid != 0 && v[mid-1] > key)
				high = mid -1;
			else {
				result = mid;
				break;
			}
		}
		else{
			low = mid + 1;
		}

	}
	return result;
}

int binsearch(vector<int>& v, int key){
	sort(v.begin(), v.end());
	int val = bsearch_next_largest(v, key, 0, v.size()- 1);
	cout<<"next highest found at  "<<val<<endl;
	return val;
}



int main(){
	vector<int> v = {23,55,-1,333,45};
	vector<int> s = {-14,-10,2,108,108,243,285,285,285,401};
	//binsearch(v, 55);
	binsearch(s,3);
	return 0;

}