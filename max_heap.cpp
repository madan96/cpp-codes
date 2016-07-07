#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<int> A;

void max_heapify(vector<int> &A, int i){
	int largest,temp;
	int l=2*i+1,r=2*i+2;
	
	if(l<A.size() && A[l]>A[i]){
		largest=l;
	}
	else{
		largest=i;
	}

	if(r<A.size() && A[r]>A[largest]){
		largest=r;
	}
	if(largest!=i){
		temp=A[i];
		A[i]=A[largest];
		A[largest]=temp;
		max_heapify(A,largest);
	}
	
}

void build_max_heap(vector<int> &A){
	int heap_length = A.size();
	for(int i=(A.size())/2;i>=0;i--){
		max_heapify(A,i);
	}
}

int main(){
	A = {4,3,2,5,1,9,8,6,10,7};
	cout<<"Unsorted array is : ";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	build_max_heap(A);
	cout<<"\nMax heap array is : ";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}


	return 0;
}