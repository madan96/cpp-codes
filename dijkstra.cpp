#include <iostream>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <queue>

using namespace cv;
using namespace std;
struct point{
	int x;
	int y;
}parent[200][200];
typedef struct point pt;

float dist[200][200];
bool visited[200][200];
Mat img = cv::imread("/home/rishabh/Downloads/ps1(2).jpg",CV_LOAD_IMAGE_COLOR);
Mat imgpath = img.clone();
int printpath(pt parent[][200],int end_x,int end_y,int st_x,int st_y){
	if(st_x==end_x && st_y==end_y){
		return 0;
	}
	cout<<parent[end_x][end_y].x<<"||||"<<parent[end_x][end_y].y<<endl;
	imgpath.at<Vec3b>(parent[end_x][end_y].x,parent[end_x][end_y].y).val[0]=255;
    imgpath.at<Vec3b>(parent[end_x][end_y].x,parent[end_x][end_y].y).val[1]=0;
    imgpath.at<Vec3b>(parent[end_x][end_y].x,parent[end_x][end_y].y).val[2]=0;
    imshow("path",imgpath);
	printpath(parent,parent[end_x][end_y].x,parent[end_x][end_y].y,st_x,st_y);
    
}
 
int distcost(int i,int j){
	if((i==0 && (j==1||j==-1)) || ((i==1 || i==-1) && j==0)){
		return 1;
	}
	if((i==1 ||i==-1) && (j==-1 || j==1)){
		return 1.4143;
	}
}
int checkdiagnol(int i, int j){
	if(i*i==1 && j*j==1)
		return 1;

	return 0;
}
void dijkstra(int a[][200], int src_x, int src_y,int end_x, int end_y){
	 float min=999;
	 queue<pt>path;
	 pt begin,temp,current;
	 begin.x = src_x;
     begin.y=src_y; 
     //path.push(begin);
	 parent[0][0].x=0;
	 parent[0][0].y=0;
	 for(int i=0;i<200;i++){
	   for(int j=0;j<200;j++){
	   	 dist[i][j]=99999;
	   	 parent[i][j].x=0;
	   	 parent[i][j].y=0;
	  	 visited[i][j]=false;
	   }
	 }
     dist[src_x][src_y]=0;
     visited[src_x][src_y]=true;
     while(visited[end_x][end_y]!=true){
     	min=999;
     for(int i=0;i<=199;i++){
		for(int j=0;j<=199;j++){
			     //cout<<i<<"---"<<j<<endl;
 
			if(visited[i][j]==true){
              temp.x=i;temp.y=j;
              path.push(temp);
              for(int m=1;m>=-1;m--){
              	for(int n=1;n>=-1;n--){
              		//cout<<m<<"____"<<n;
              		if((temp.x+m<199 && temp.y+n<199 && temp.x+m>0 && temp.y+n>0)){
              		  if(visited[temp.x+m][temp.y+n]==false && a[temp.x+m][temp.y+n]!=0 && dist[temp.x+m][temp.y+n]==99999){
                        
              		  		dist[temp.x+m][temp.y+n]=dist[temp.x][temp.y]+distcost(m,n);
              		  	//}
              		  	//else if(dist[temp.x+m][temp.x+n]>dist[temp.x][temp.y]+1.41 && checkdiagnol(m,n))
              		  	//	dist[temp.x+m][temp.y+n]=dist[temp.x][temp.y]+1.41;
              		  	//}
              		  	//visited[temp.x+m][temp.y+n]=true;
              		  	if(dist[temp.x+m][temp.y+n]<=min){
              		  		//imgpath.at<Vec3b>(temp.x+m,temp.y+n).val[0]=255;
                            //imgpath.at<Vec3b>(temp.x+m,temp.y+n).val[1]=255;
                            //imgpath.at<Vec3b>(temp.x+m,temp.y+n).val[2]=0;
              		  		
              		  		min=dist[temp.x+m][temp.y+n];
              		  	}
              		  }
              		}
              	}
              }
			}
		}
	}  
	  //}
	  while(!path.empty()){
         current=path.front();
         path.pop();
         
         //cout<<current.x<<"////"<<current.y;
         for(int i=-1;i<=1;i++){
         	for(int j=-1;j<=1;j++){
         		if(/*visited[current.x+i][current.y+j]!=true &&*/ dist[current.x+i][current.y+j]==min && (current.x+i<199 && current.y+j<199 && current.x+i>0 && current.y+j>0) && a[current.x+i][current.y+j]!=0){
         			
         			visited[current.x+i][current.y+j]=true;
         			//cout<<i<<"+++"<<j<<endl;
		            parent[current.x+i][current.y+j].x=current.x;
		            parent[current.x+i][current.y+j].y=current.y;
         		}
         	}
         }
 	  }	
 	  }	
 
}
//Mat img = imread("",CV_LOAD_IMAGE_COLOR);
//int graph[200][200];
int a[200][200];
int main(int argc, char **argv)
{  
  int sum1_x=0,sum1_y=0,sum2_x=0,sum2_y=0;
  long  int st_x,st_y,end_x,end_y; 
  int count1=0,count2=0;
  int i=0,j=0,k=0,r,c;
  
  r = img.rows;
  c = img.cols;  
  for(i=0;i<200;i++)
    for(j=0;j<200;j++)
      visited[i][j]=false;

  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      if(img.at<Vec3b>(i,j)[2] > 200  && img.at<Vec3b>(i,j)[0] < 100){
	    sum1_x+=i;
	    sum1_y+=j;
        count1++;
      }
      if(img.at<Vec3b>(i,j)[1] > 200 && img.at<Vec3b>(i,j)[2] < 10){
        sum2_x+=i;
	    sum2_y+=j;
        count2++;
      }
      if(img.at<Vec3b>(i,j)[0]>200 && img.at<Vec3b>(i,j)[1]>200 && img.at<Vec3b>(i,j)[2]>200){
         a[i][j]=0;
      }
      else{
	    a[i][j]=1;
      }
    }
  }
  
  st_x = sum1_x/count1;
  st_y = sum1_y/count1;
  end_x = sum2_x/count2;
  end_y = sum2_y/count2;
  //cout<<st_x<<"   "<<st_y<<"  "<<end_x<<"   "<<end_y;
  dijkstra(a,st_x,st_y,end_x,end_y);
  printpath(parent,end_x,end_y,st_x,st_y);
  waitKey(0);
}