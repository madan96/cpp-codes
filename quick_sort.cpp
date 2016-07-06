#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

int A[10]={4,3,2,5,1,9,8,6,10,7};

int partition(int A[],int p,int r);
void quicksort(int A[],int p,int r);

int partition(int A[],int p,int r){
	int x = A[r],i=p-1,temp,flag=0;
	for(int j=p;j<r;j++){
		if(A[j]<=x){
			i=i+1;
			flag=1;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	temp=A[i+1];
	A[i+1] = A[r];
	A[r]=temp;
	return (i+1);
}
	
void quicksort(int A[],int p,int r){
	int q;
	if(p<r){
		q = partition(A,p,r);
		//Apply quicksort on two halves
		quicksort(A,p,q-1); 
		quicksort(A,q+1,r);
	}
}

int main(){
	cout<<"Unsorted array is : ";
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}

	clock_t t;
    t = clock();
    quicksort(A,0,10-1);
    t = clock() - t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout<<"\nSorted array is : ";
	for(int i=0;i<10;i++){
		cout<<A[i]<<" ";
	}
	cout<<fixed;
	cout<<setprecision(30);
	cout<<"\nExecution time: "<<time_taken;
	cout<<endl;
	return 0;
}

