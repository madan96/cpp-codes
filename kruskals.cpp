#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#define size 5

#define int_max 999999

using namespace std;
struct edge{
	int point1;
	int point2;
};

vector<int> listMST;
int mincost=0;

void kruskalsMST(int adjMatrix[5][5]){

}

int main(){

	int adjMatrix[size][size] = {{6,4,0,2,0},
						   		 {2,0,0,8,5},
						   		 {0,0,0,0,7},
						   		 {9,8,0,0,9},
						   		 {6,0,4,9,0}};
	
	clock_t t;
    t = clock();
    kruskalsMST(adjMatrix);	
    t = clock() - t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;

	cout<<fixed;
	cout<<setprecision(30);
	cout<<"\nExecution time for function: "<<time_taken;
	cout<<endl;
	
	cout<<"\nMinimum Spanning tree is :\n";
	for (int i = 0; i < size-1; ++i){
		cout<<listMST[i].point1<<" <----> "<<listMST[i].point2<<endl;
	}					   
	cout<<"\nCost of spanning tree is : "<<mincost<<endl<<endl;
	
	return 0;
}