#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,count=0,flag=0,len1;
	cin>>t;
	string a,b;
	int n=2;
	while(t--!=0){
		n=3;
		flag=0;
		cin>>a;
		cin>>b;
		len1 = a.length();
		count=0;
		while(a.compare(b)!=0 || n>0){
		for(int i=0;i<len1-1;i++){
			for(int j=i+1;j<len1;j++){
				if(a[i]!=b[i] || a[j]!=b[j]){
					if((a[i]=='1' && a[j]=='1') || (a[i]=='0' && a[j]=='0')){
						continue;
					}
					if((a[i]=='0' && b[i]=='0' && a[j]=='1' && b[j]=='0') || (a[i]=='1' && b[i]=='0' && a[j]=='0' && b[j]=='0')){
						count++;
						a[j]='0';a[i]='0';
						continue;
					}
					if((a[i]=='1' && b[i]=='1' && a[j]=='0' && b[j]=='1') || (a[i]=='0' && b[i]=='0' && a[j]=='1' && b[j]=='0')){
						count++;
						a[i]='1';a[j]='1';
						continue;
					}
					if(a[i]=='0' && b[i]=='1' && a[j]=='1' && b[j]=='0'){
						count+=2;
						a[i]='1';a[j]='0';
						continue;
					}
					if(a[i]=='1' && b[i]=='0' && a[j]=='0' && b[j]=='1'){
						count+=2;
						a[i]='0';a[j]='1';
						continue;
					}
				}
			}
		}
		n--;	
		}
		for(int i=0;i<len1;i++){
				if(a[i]!=b[i]){
					flag=1;
				}
			}
		cout<<a<<endl;
		if(flag==1){
			cout<<"Unlucky Chef"<<endl;
		}
		else{
			cout<<"Lucky Chef"<<endl;
			cout<<count<<endl;
		}
	}
	return 0;
}