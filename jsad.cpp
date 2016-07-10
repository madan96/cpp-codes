#include <iostream>
#include <vector>
#include <algorithm>

#define max_d 5

using namespace std;

struct job{
	char jobtype;
	int deadline;
	int profit;
	bool flag;
};

vector<struct job> jobs;
struct job order[max_d];

bool my_cmp(const job& a, const job& b)
{
	//greatest first
    return a.profit > b.profit;
}

void job_sequencing(vector<struct job> &jobs){
	int count=0,i=0;
	for(i=0;i<jobs.size();i++){
		if(jobs[i].deadline<=max_d && order[jobs[i].deadline-1].flag==0){
			order[jobs[i].deadline-1] = jobs[i];
			order[jobs[i].deadline-1].flag=1;
			jobs[i].flag=1;	
		}
	}
	for(i=0;i<max_d;i++){
		for(int j=0;j<jobs.size();j++){
			if(order[i].flag==0 && jobs[j].flag==0){
				order[i] = jobs[j];
				order[i].flag = jobs[j].flag = 1;
				break;
			}
		}
	}
}

int main(){
	int maxprofit=0;

	jobs = {{'a',5,200,0},{'b',3,180,0},{'c',3,190,0},{'d',2,300,0},{'e',4,120,0},{'f',2,100,0}};
	sort(jobs.begin(), jobs.end(), my_cmp);
	job_sequencing(jobs);
	
	cout<<"\nInitial Job Sequencing order\n";
	for (int i = 0; i < jobs.size(); ++i)
	{	
		cout<<jobs[i].jobtype<<"  ";
	}
	
	cout<<"\n\nJob Sequencing order for max profit : \n";
	for (int i = 0; i < max_d; ++i)
	{	
		cout<<order[i].jobtype<<"  ";//  b  d  c e a
		maxprofit+=order[i].profit;
	}
	
	cout<<"\n\nMax profit : "<<maxprofit<<"\n\n";

	return 0;
}