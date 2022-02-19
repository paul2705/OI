#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
int n[10005];
int main(){
    int num;
    int ans=0;
    cin>>num;
    for(int i=1;i<=num;i++){cin>>n[i];}
    for(int k=0;k<=num;k++){for(int i=num-k;i>=2;i--){
    if(n[i]>n[i-1]){swap(n[i],n[i-1]);ans++;}}}
	for (int i=1;i<=num;i++) printf("%d ",n[i]);
	cout<<ans;
    return 0;
}
