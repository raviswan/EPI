//Find the kth largest element in the array...
//Use random key as a pivot. This is not a complete solution.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void quicksort(vector<int>& v,  int left, int right){
	int mid = left + (right-left)/2;
	int pivot = v[mid];
	int i= left; int j = right;
	while(i <= j){
		while(i<= j && v[i] <= pivot)
			++i;
		while(i <= j && v[j] > pivot)
			j--;
		if(i < j){
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			++i;
			--j;
		}
	}
	if(left < j)
		quicksort(v,left,j);
	if (i < right)
		quicksort(v,i,right);
}

int sortPivot(vector<int>& v, int left, int right, int k){
	int pivotIndex = left + (right-left)/2;
	int pivot = v[pivotIndex];
	int i = left;
	int j =  right;
	int largeCount = 0;
	while(i <= j){
		while(i <=j && v[i] <= pivot){
			++i;
		}
		while(i<=j && v[i]>pivot){
			--j;
			++largeCount;
		}
		if(i < j)
			swap(v[i],v[j]);
	}
	if(largeCount == k-1)
		return pivot;
	else if(largeCount > k-1)
		sortPivot(v, pivotIndex+1 , right, k);
	else
		sortPivot(v, left, pivotIndex-1, k);
	return pivot;
}

void findKthLargest(vector<int>& v, int k){
	
	int pivot = sortPivot(v, 0, v.size() -1 );
	
}