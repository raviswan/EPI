%%Find the smallest index equal to key  in a sorted array of integers
#include <iostream>
#include <vector>

using namespace std;

bool bsearch(vector<int>& v, int key, unsigned int low, unsigned int high){
	unsigned int mid;
	while (low <= high){
		mid = low + (high-low)/2;
		if (key == v[mid]){
			cout<<"value "<<v[mid]<<" found at pos ="<<mid<<endl;
			return true;
		}
		else if  (key < v[mid])
			high = mid -1;
		else{
			low = mid + 1;
		}
	}
	return false;
}


int bsearch_first(vector<int>& v, int key, unsigned int low, unsigned int high){
	unsigned int mid;
	int result = -1;
	while (low <= high){
		mid = low + (high-low)/2;
		if (key == v[mid]){
			result = mid;
			high = mid -1;
		}
		else if  (key < v[mid])
			high = mid -1;
		else{
			low = mid + 1;
		}
	}
	return result;
}

int binsearch(vector<int>& v, int key){
	sort(v.begin(), v.end());
	int val = bsearch_first(v, key, 0, v.size()- 1);
	if (!val)
		cout<<"value not found"<<endl;
	else 
		cout<<"value found at "<<val<<endl;
	return val;

}



int main(){
	vector<int> v = {23,55,-1,333,45};
	vector<int> s = {-14,-10,2,108,108,243,285,285,285,401};
	//binsearch(v, 55);
	binsearch(s,108);
	return 0;

}