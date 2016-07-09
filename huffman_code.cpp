#include <iostream>
#include <vector>
#include "stdlib.h"
#include <algorithm>

using namespace std;

struct node{
	char alphabhet;
	int frequency;
	struct node *left, *right;
};

vector<struct node*> test;
vector<struct node> minheap;
struct node *left1, *right1, *temp;

bool my_cmp(const node& a, const node& b)
{
	//smallest first
    return a.frequency > b.frequency;
}

struct node* newNode(char ch,int freq){
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	temp->frequency=freq;
	temp->alphabhet=ch;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void printhcode(struct node *rootnode, int *code, int top){
	
	struct node *temp;
	temp = rootnode->left;
	cout<<"alphabhet : "<<temp->alphabhet<<"\n";
	/*if(rootnode->left){
		code[top]=0;
		printhcode(rootnode->left,code,top+1);
	}
	if(rootnode->right){
		code[top]=1;
		printhcode(rootnode->right,code,top+1);
	}
	if(rootnode->left==NULL && rootnode->right==NULL){
		cout<<rootnode->alphabhet<<": ";
		for(int i=0;i<top;i++){
			cout<<code[i];
		}
		cout<<endl;
	}*/
}

void printCodes(struct node* root, string str)
{
    if (!root)
        return;
 
    if (root->alphabhet != '$')
        cout << root->alphabhet << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct node* extractmin(vector<struct node> &minheap){
	struct node* min;
	min = &minheap[minheap.size()-1];
	minheap.erase(minheap.end()-1);
	return min;
}

void huffman(vector<node> &minheap){
	
	int code[50];
	int n = 4;
	for(int i=0;i<n-1;i++){
		//struct node* z = newNode()
		left1 = extractmin(minheap);
		right1 = extractmin(minheap);

		cout<<"\n"<<left1->frequency<<"  "<<right1->frequency<<"\n";
		temp =  newNode('$',left1->frequency + right1->frequency);
		temp->left = left1;
		temp->right = right1;
		minheap.push_back(*temp); 
		test.push_back(temp);
		sort(minheap.begin(), minheap.end(), my_cmp);
	}
	//printhcode(temp,code,0);
	//printCodes(left,"");
} 

int main(){
	minheap = {{'a',50}, {'b',40},{'c',5},{'d',5}};
	sort(minheap.begin(), minheap.end(), my_cmp);
	//struct node* temp1 = extractmin(minheap);
	//cout<<"\n"<<temp1->alphabhet;
	huffman(minheap);
	struct node *root;
	root = test[1];
	cout<<"alphabhets \n";
	for (int i = 0; i < 3; ++i)
	{
		cout<<root->alphabhet<<" ";
		root = root->left;
		/* code */
	}
	return 0;
}