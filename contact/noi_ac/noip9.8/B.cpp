#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e4+5;
int n,a[MAXN],b[MAXN],i,j,cnt,l,r;
bool f=1;
void cp(int i,int j){
	l=min(i,j);
	r=max(i,j);
}
void chg(int &x){
	if (f) x--;
	else x++;
	if (j==x) r--;
	else l++;
//	cp(i,j);
//	cout<<j<<endl;
}
void change(int i,int j){
	if (f){
		cnt++; i++; swap(i,j); f=0; l++;
	}else { cnt++; i--; swap(i,j); f=1; l++; }
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	i=1,j=n,cnt=1;
	l=1,r=n;
	sort(b+1,b+n+1);
	while (a[cnt]==b[cnt]) cnt++,i++;
	while (cnt<n){
		for(;a[j]!=b[cnt];chg(j));
		printf("%d %d\n",l,r);
		change(i,j);
		while (a[i]==b[cnt]) cnt++,chg(i);
	}
	printf("-1 -1\n");
	return 0;
}
