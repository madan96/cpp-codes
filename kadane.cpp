//Maximum sum of contiguous sub-arrays

#include <iostream>
#include <vector>
#include <algorithm>
#define size 10
 
using namespace std;

bool my_cmp(const int& a, const int& b)
{
	//greatest first
    return a > b;
}

int kadaneAlgo(vector<int> list){
	int max_so_far = 0, max_ending_here = 0;

	for(int i=0;i<size;i++){
		max_ending_here += list[i];
		if(max_ending_here<0){
			max_ending_here=0;
		}
		if(max_so_far<max_ending_here){
			max_so_far = max_ending_here;
		}
	}

	return max_so_far;
}

int main(){
	vector<int> list = {-2,1,3,-5,7,2,-1,-3,-4,5,8};
	int flag = 0, max;
	for(int i=0; i<size; i++){
		if(list[i]>0){
			flag=1;
		}
	}
	cout<<"Given list is : \n";
	for(int i=0; i<size; i++){
		cout<<list[i]<<" ";
	}
	if(flag==1){
		sort(list.begin(),list.end(),my_cmp);
		cout<<"\nMax sum of sub-contiguous arrays is : "<<list[0]<<endl;
	}
	else{
		cout<<"\nMax sum of sub-contiguous arrays is : "<<kadaneAlgo(list)<<endl;
	}

	return 0;
}