#include <iostream>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <queue>
#include <math.h>
#include <vector>

using namespace cv;
using namespace std;
struct point{
	int val;
	int x;
	int y;
	int f;
	int g;
	point *parent;
}**a;

int sum1_x=0,sum1_y=0,sum2_x=0,sum2_y=0;
  long  int st_x,st_y,end_x,end_y; 
  int count1=0,count2=0;
  int r,c;

Mat img = cv::imread("/home/rishabh/Downloads/ps1(2).jpg",CV_LOAD_IMAGE_COLOR);
Mat imgpath = img.clone();

int fdist[200][200],gdist[200][200],h[200][200];
class minqueue{
	public: bool operator()(struct point *i,struct point *j){
	return (i->f>j->f);
	}
};

int distcost(int i,int j){
  if((i==0 && (j==1||j==-1)) || ((i==1 || i==-1) && j==0)){
    return 10;
  }
  if((i==1 ||i==-1) && (j==-1 || j==1)){
    return 14;
    
  }
}
int diagonal(int i,int j)
{ if((i==0 && (j==1||j==-1)) || ((i==1 || i==-1) && j==0))
  return 0;
  return 1;
}
priority_queue<struct point *, vector<struct point *>, minqueue>path;
int hdist[200][200];
bool visited[200][200];

int printpath(struct point *drawpath){
  
    //cout<<parent[end_x][end_y]->x<<"||||"<<parent[end_x][end_y]->y<<endl;
    imgpath.at<Vec3b>(drawpath->x,drawpath->y).val[0]=255;
    imgpath.at<Vec3b>(drawpath->x,drawpath->y).val[1]=0;
    imgpath.at<Vec3b>(drawpath->x,drawpath->y).val[2]=0;
    imshow("path",imgpath);
    if(drawpath->parent==NULL){
    return 0;
  }
    printpath(drawpath->parent);
}

void astar(){
	if(visited[end_x][end_y]==true || path.empty()){
		return;
	}
	struct point *temp,*temp2;
	
    //while(visited[end_x][end_y]!=true && !path.empty()){
        //cout<<"|||"<<endl;
    	temp=path.top()	;
    	
        visited[temp->x][temp->y]=true;
        path.pop();
    	for(int m=1;m>=-1;m--){
    		for(int n=1;n>=-1;n--){
    			//cout<<"&&&&"<<endl;
    			if(temp->x+m>=0 && temp->y+n>=0 && temp->x+m<200 && temp->y+n<200){
    				if(visited[temp->x+m][temp->y+n]!=true && a[temp->x+m][temp->y+n].val!=0){
    					imgpath.at<Vec3b>(temp->x,temp->y).val[1]=255;
                       if(a[temp->x + m][temp->y + n].g>a[temp->x][temp->y].g+10 && !diagonal(m,n)){
                          //cout<<count<<endl;
    				      
    				      a[temp->x+m][temp->y+n].parent=temp;
    				      a[temp->x+m][temp->y+n].g = a[temp->x][temp->y].g + distcost(m,n);
                          a[temp->x+m][temp->y+n].f = a[temp->x+m][temp->y+n].g + hdist[temp->x+m][temp->y+n];
                          path.push(&a[temp->x+m][temp->y+n]);
                          
                       }
                       else if(a[temp->x + m][temp->y + n].g>a[temp->x][temp->y].g+14 && diagonal(m,n)){
                       	  a[temp->x+m][temp->y+n].parent=temp;
    				      a[temp->x+m][temp->y+n].g = a[temp->x][temp->y].g + distcost(m,n);
                          a[temp->x+m][temp->y+n].f = a[temp->x+m][temp->y+n].g + hdist[temp->x+m][temp->y+n];
                          path.push(&a[temp->x+m][temp->y+n]);
                          
                       }
    				}
    			}
    		}
    	}
    	astar();
    //}
}


int main()
{  
  a = (struct point**)malloc(200*sizeof(struct point *));
  for(int i=0;i<200;i++){
	 a[i] = (struct point *)malloc(200*sizeof(struct point));
  }
  /*parent = (struct point***)malloc(200*sizeof(struct point **));
  for(int i=0;i<200;i++){
	 parent[i] = (struct point **)malloc(200*sizeof(struct point*));
  }*/
  int  i=0,j=0,k=0;
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
         a[i][j].val=0;
      }
      else{
        a[i][j].val=1;
      }
    }
  }
  st_x = sum1_x/count1;
  st_y = sum1_y/count1;
  end_x = sum2_x/count2;
  end_y = sum2_y/count2;
  for(int i=0;i<200;i++){
		for(int j=0;j<200;j++){
			a[i][j].g = 999999999;
			hdist[i][j] = 20*sqrt((end_x-i)*(end_x-i)+(end_y-j)*(end_y-j));//abs(end_x-i) + abs(end_y-j);
			visited[i][j]=false;
			a[i][j].x=i;
			a[i][j].y=j;
			a[i][j].parent=NULL;
		}
  }
  a[st_x][st_y].g=0;
	a[st_x][st_y].f=a[st_x][st_y].g+hdist[st_x][st_y];
    //cout<<"asd";
    path.push(&a[st_x][st_y]);
  //a[st_x][st_y].val=1;
  //a[end_x][end_y].val=0;
  //cout<<a[st_x][st_y].val<<"___"<<a[end_x][end_y].val;
  //cout<<st_x<<"   "<<st_y<<"  "<<end_x<<"   "<<end_y;
  astar();
  printpath(&a[end_x][end_y]);
  //printpath(parent,end_x,end_y,st_x,st_y);
  imshow("path", imgpath);
  waitKey(0);
}
