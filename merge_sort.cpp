#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>

using namespace std;

vector<int> A;

void merge(vector<int> &A, int p, int q, int r){
	vector<int> L,R,K;
	int i=0,j=0;
	int n1 = q-p+1;
	int n2 = r-q;
	for(int i=0;i<n1;i++){
		L.push_back(A[p+i]);
	}
	L.push_back(10000);

	for(int j=0;j<n2;j++){
		R.push_back(A[q+j+1]);
	}
	R.push_back(10000);

	for(int k=p;k<=r;k++){
		if(L[i]<R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}

void merge_sort(vector<int> &A, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
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
    merge_sort(A,0,A.size()-1);
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