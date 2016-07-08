#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>

using namespace std;

vector<int> A;
int heap_length;

void max_heapify(vector<int> &A, int i){
	int largest,temp;
	int l=2*i+1,r=2*i+2;
	
	if(l<=heap_length && A[l]>A[i]){
		largest=l;
	}
	else{
		largest=i;
	}

	if(r<=heap_length && A[r]>A[largest]){
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
	heap_length = A.size();
	for(int i=(A.size())/2;i>=0;i--){
		max_heapify(A,i);
	}
}

void heap_sort(vector<int> &A){
	int temp;
	build_max_heap(A);
	for(int i=A.size();i>=1;i--){
		temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		heap_length = heap_length-1;
		max_heapify(A,0);
	}

}

int main(){
	A = {4,3,2,5,1,9,8,6,10,7};
	cout<<"Unsorted array is : ";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

	clock_t t;
    t = clock();
    heap_sort(A);
    t = clock() - t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	cout<<"\nSorted array is : ";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

	cout<<fixed;
	cout<<setprecision(30);
	cout<<"\nExecution time: "<<time_taken;
	cout<<endl;

	return 0;
}