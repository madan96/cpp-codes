#include <iostream>
#include <queue>
using namespace std;
 
struct point{
	int x;
	int y;
}parent[5][5];
typedef struct point pt;
int a[5][5] = {  
	             {1,0,1,1,0},
                 {1,1,0,0,0},
                 {0,1,1,0,1},
                 {0,0,1,0,0},
                 {1,1,0,1,0},
              };
 
float dist[5][5];
bool visited[5][5];
 
int printpath(pt parent[][5],int end_x,int end_y,int st_x,int st_y){
	if(st_x==end_x && st_y==end_y){
		return 0;
	}
	cout<<parent[end_x][end_y].x<<"---"<<parent[end_x][end_y].y<<endl;
	printpath(parent,parent[end_x][end_y].x,parent[end_x][end_y].y,st_x,st_y);
}
 
int distcost(int i,int j){
	if((i==0 && (j==1||j==-1)) || ((i==1 || i==-1) && j==0)){
		cout<<"1";
		return 1;
	}
	if((i==1 ||i==-1) && (j==-1 || j==1)){
		cout<<"1.41";
		return 1.41;
	}
}
void dijkstra(int a[][5], int src_x, int src_y,int end_x, int end_y){
	 int min=999;
	 queue<pt>path;
	 pt begin,temp,current;
	 begin.x = src_x;
     begin.y=src_y; 
     path.push(begin);
	 parent[0][0].x=0;
	 parent[0][0].y=0;
	 for(int i=0;i<5;i++){
	   for(int j=0;j<5;j++){
	   	 dist[i][j]=99999;
	   	 parent[i][j].x=0;
	   	 parent[i][j].y=0;
	  	 visited[i][j]=false;
	   }
	 }
     dist[1][0]=0;
     visited[src_x][src_y]=true;
     while(visited[end_x][end_y]!=true){
     for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			     cout<<i<<"---"<<j<<endl;
 
			if(visited[i][j]==true){
              temp.x=i;temp.y=j;
              path.push(temp);
              for(int m=-1;m<=1;m++){
              	for(int n=-1;n<=1;n++){
              		cout<<m<<"____"<<n;
              		if((temp.x+m<4 && temp.y+n<4 && temp.x+m>0 && temp.y+n>0)){
              		  if(visited[temp.x+m][temp.y+n]==false){
              		  	dist[temp.x+m][temp.y+n] = dist[temp.x][temp.y]+distcost(m,n);
              		  	if(dist[temp.x+m][temp.y+n]<=min){
              		  		min=dist[temp.x+m][temp.y+n];
              		  	}
              		  }
              		}
              	}
              }
			}
		}
	  }
	  }
	  while(path.empty()!=1){
         current=path.front();
         path.pop();
         for(int i=-1;i<=1;i++){
         	for(int j=-1;j<=1;j++){
         		if(dist[current.x+i][current.y+j]==min && (current.x+i<4 && current.y+j<4 && current.x+i>0 && current.y+j>0)){
         			visited[current.x+i][current.y+j]=1;
		            parent[current.x+i][current.y+j].x=current.x;
		            parent[current.x+i][current.y+j].y=current.y;
         		}
         	}
         }
 	  }		
 
}
 
int main(){
    dijkstra(a,1,0,4,4);
    printpath(parent,4,4,0,0);
}