#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

struct number{
	int num;
	bool prime;
};
vector<int> primeno;
//prime=1 means Prime number

void sieve(int n){
	struct number A[n+1];
	for(int i = 0; i < n+1; ++i){
		A[i].num = i;A[i].prime=1;
	}
	A[0].prime = A[1].prime = 0;A[2].prime=1;
	for(int i=2;i<=(int)sqrt(n);i++){
		if(A[i].prime==1){
			for(int j=2;i*j<=n;j++){
				A[i*j].prime=0;
			}
		}
	}
	for(int i=0; i<n+1; ++i){
		if(A[i].prime==1){
			primeno.push_back(A[i].num);
			cout<<A[i].num<<" ";
		}
	}
}

void segmented_sieve(int n){
	int newRange = floor((int)sqrt(n))+1;
	sieve(newRange);

	int begin = newRange,end = 2*newRange,lowerlim;
	while(begin<n){
		struct number A[newRange+1];
		for(int i = 0; i < newRange+1; ++i){
			A[i].num = i;A[i].prime=1;
		}
		for(int i=0; i<primeno.size(); i++){
			if(primeno[i]!=0){
			lowerlim = (begin/primeno[i])*primeno[i];
			}
			if(lowerlim<begin){
				lowerlim+=primeno[i];
			}
			for(int j=lowerlim; j<end; j+=primeno[i])
                A[j-begin].prime = 0;
		}
		for(int i=begin; i<end; i++)
        	if(A[i-begin].prime==1)
                cout<<i<<" ";

        begin = begin+newRange;
        end = end+newRange;
        if(end>=n) 
        	end=n;
	}
}

int main(){
	int n=1000000;

	/*for(int i = 0; i < n+1; ++i){
		A[i].num = i;A[i].prime=1;
	}*/

	clock_t t;
    t = clock();
    segmented_sieve(n);
    t = clock() - t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	/*cout<<"Prime number till "<<n<<" are :\n";
	for (int i = 0; i < n+1; ++i){
		if(A[i].prime==1){
			cout<<A[i].num<<" ";
		}*/

	//}
	cout<<endl;
	cout<<fixed;
	cout<<setprecision(30);
	cout<<"\nExecution time for function: "<<time_taken;
	cout<<endl;
	return 0;
}