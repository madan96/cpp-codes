#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <map>

using namespace std;

struct data{
	int profit;
	int weight;
	float ppu;
};

vector<data> A;
int m = 15;

bool my_cmp(const data& a, const data& b)
{
	//greatest first
    return a.ppu > b.ppu;
}

float greedy_knapsack(vector<data> &A){
	float profit1=0;
	int i=0;
	sort(A.begin(), A.end(), my_cmp);
	for(i=0;i<A.size();i++){
		if(m>0 && A[i].weight<=m){
			m-=A[i].weight;
			profit1+=A[i].profit;
		}
		else{
			break;
		}
	}
	if(m>0){
		profit1+=A[i].profit*float(m)/A[i].weight;
	}
	return profit1;
}

int main(){
	struct data temp;
	float max_profit;
	A = {{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
	for(int i=0;i<A.size();i++){
		A[i].ppu = (float)A[i].profit/A[i].weight;
	}
	cout<<"\tWeight\t\tProfit\n";
	for(int i=0;i<A.size();i++){
		cout<<"\t"<<A[i].weight<<"\t\t"<<A[i].profit<<"\n";
		
	}
	max_profit = greedy_knapsack(A);
	cout<<"\n    Max profit is : "<<max_profit<<"\n\n";
	return 0;
}