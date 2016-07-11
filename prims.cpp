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

vector<struct edge> listMST;
	int mincost=0;

void primsMST(int adjMatrix[size][size]){

	int near[size];
	int min = int_max,k,l;
	struct edge t;
	
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			if(adjMatrix[i][j]<min && adjMatrix[i][j]!=0){
				min = adjMatrix[i][j];
				k=i;l=j;
			}
		}	
	}
	mincost = adjMatrix[k][l];
	t.point1 = k;
	t.point2 = l;
	listMST.push_back(t);
	for(int i=0; i < size; i++){
		if ( adjMatrix[i][k]!=0 || adjMatrix[i][l]!=0){
			if(adjMatrix[i][k]==0){
				near[i]=l;
			}
			else if(adjMatrix[i][l]==0){
				near[i]=k;
			}
			else if( adjMatrix[i][k] < adjMatrix[i][l] ){
				near[i]=k;
			}
		}
		else
			near[i]=l;
	}
	near[k]=near[l]=-1;
	for(int i = 1; i < (size-1); ++i){
		int min2=int_max;
		for (int j = 0; j< size; ++j){
			if(near[j]!=(-1)){
				if( adjMatrix[j][near[j]]<min2 && adjMatrix[j][near[j]]!=0 ){
					min2 = adjMatrix[j][near[j]];
					t.point1 = j;
					t.point2 = near[j];
				}
			}
		}
		listMST.push_back(t);
		mincost+=adjMatrix[t.point1][t.point2];
		near[t.point1]=-1;

		for (int k = 0; k < size; ++k){
			if(near[k]!=-1){
				if( adjMatrix[k][near[k]]==0 && adjMatrix[k][t.point1]==0 ){
					continue;
				}
				if ( adjMatrix[k][near[k]] > adjMatrix[k][t.point1] && adjMatrix[k][t.point1]!=0 ){
					near[k] = t.point1;
				}
				if(adjMatrix[k][near[k]]==0){
					near[k]=t.point1;
				}
			}
		}
	}
}

int main(){

	int adjMatrix[size][size] = {{0,2,0,6,0},
						   		 {2,0,3,8,5},
						   		 {0,3,0,0,7},
						   		 {6,8,0,0,9},
						   		 {0,5,7,9,0}};
	
	primsMST(adjMatrix);	
	cout<<"\nMinimum Spanning tree is :\n";
	for (int i = 0; i < size-1; ++i){
		cout<<listMST[i].point1<<" <----> "<<listMST[i].point2<<endl;
	}					   
	cout<<"\nCost of spanning tree is : "<<mincost<<endl<<endl;
	return 0;
}