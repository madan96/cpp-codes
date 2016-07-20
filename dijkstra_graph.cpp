#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <time.h>

#define size1 9
#define int_max 999999

using namespace std;

struct node{
	int weight;
	int x;
	int y;
};
int graph[size1][size1] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                 		 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                 		 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                 		 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                 		 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                 		 {0, 0, 4, 0, 10, 0, 2, 0, 0},
                 		 {0, 0, 0, 14, 0, 2, 0, 1, 6},
                 		 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                 		 {0, 0, 2, 0, 0, 0, 6, 7, 0}
                		};

vector<int> node_queue;
vector<struct node> min_heap;

bool my_cmp(const node& a, const node& b)
{
	//smallest first
    return a.weight > b.weight;
}
int extract_min(vector<int> &min_heap){
	int min;
	min = min_heap[min_heap.size()-1];
	min_heap.erase(min_heap.end()-1);
	return min;
}

void dijkstra(int graph[size1][size1], int start){
	int element,min = int_max;
	struct node graph_copy[size1][size1], graph_element;
	graph_copy[start][start].weight=0;
	graph_copy[start][start].x = start;
	graph_copy[start][start].y = start;

	for(int i = 0; i<size1; i++){
		for(int j=0; j<size1 ; j++){
			if(i!=start || j!=start){
				graph_copy[i][j].weight = int_max;
				graph_copy[i][j].x = i;
				graph_copy[i][j].y = j;
			}
		}
	}
	//stillPending
	min_heap.push_back(graph_copy[start][start]);
	
	sort(min_heap.begin(), min_heap.end(), my_cmp);
	//build_min_heap()
	int count=0;
	while(count!=8){
		element = min_heap[min_heap.size()-1].x;
		cout<<"element: "<<element<<endl;
		min_heap.erase(min_heap.end()-1);
		node_queue.push_back(element);
		for(int i=0; i<size1; i++){
			if(i!=element && graph[element][i]>0){
				graph_copy[element][i].weight = graph_copy[element][element].weight + graph[element][i];
				cout<<"i: "<<i<<endl;
				if(graph_copy[element][i].weight<min){
					graph_element.x = i;
					graph_element.weight = graph_copy[element][i].weight;
					min = graph_copy[element][i].weight;
					cout<<min<<endl;
				}
			}
		}
		count++;
		min_heap.push_back(graph_element);
		sort(min_heap.begin(), min_heap.end(), my_cmp);
	}

}

int main(){
	int start = 0;
	dijkstra(graph,start);

	for(int i=0;i<node_queue.size();i++){
		cout<<"Node: "<<node_queue[i]<<endl;
	}

	return 0;
}
