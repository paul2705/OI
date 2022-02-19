#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long x;
int a[100];
int main(){
	char c=getchar();
	while (c!='.') c=getchar(); x=0;
	for (int i=1;i<=10;i++) c=getchar(),x=x*10+c-'0';
	long long res=x,cnt=0,l;
	while (res) cnt++,res/=10;
	x/=23;
//	cout<<cnt<<" "<<x<<endl;
	while (x) a[cnt--]=x%10,x/=10;
	cout<<"0.";
	for (int i=1;i<=8;i++) printf("%d",a[i]);
	return 0;
}
