#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

vector<int> insertion_sort(vector<int> A){
	int key,i=0;
	for(int j=1;j<A.size();j++){
		key=A[j];
		i=j-1;
		while(i>=0 && A[i]>key){
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;
	}
	return A;
}

int main(){
	vector<int> A,sorted_array;
	A = {4,3,2,5,1,9,8,6,10,7};
	cout<<"Unsorted array is : ";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

	clock_t t;
    t = clock();
    sorted_array = insertion_sort(A);
    t = clock() - t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	cout<<"\nSorted array is : ";
	for(int i=0;i<A.size();i++){
		cout<<sorted_array[i]<<" ";
	}
	cout<<fixed;
	cout<<setprecision(30);
	cout<<"\nExecution time: "<<time_taken;
	cout<<endl;
	return 0;
}
