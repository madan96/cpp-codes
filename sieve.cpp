#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>

using namespace std;

struct number{
	int num;
	bool prime;
};

//prime=1 means Prime number

void sieve(struct number A[],int n){
	A[0].prime = A[1].prime = 0;A[2].prime=1;
	for(int i=2;i<=(int)sqrt(n);i++){
		if(A[2].prime==1){
			for(int j=2;i*j<=n;j++){
				A[i*j].prime=0;
			}
		}
	}
}

int main(){
	int n=1000000;
	struct number A[n+1];
	for(int i = 0; i < n+1; ++i){
		A[i].num = i;A[i].prime=1;
	}

	clock_t t;
    t = clock();
    sieve(A,n);
    t = clock() - t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	cout<<"Prime number till "<<n<<" are :\n";
	for (int i = 0; i < n+1; ++i){
		if(A[i].prime==1){
			cout<<A[i].num<<" ";
		}
	}
	cout<<endl;
	cout<<fixed;
	cout<<setprecision(30);
	cout<<"\nExecution time for function: "<<time_taken;
	cout<<endl;
	return 0;
}