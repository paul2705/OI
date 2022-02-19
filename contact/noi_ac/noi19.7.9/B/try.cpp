#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1e5+5;
int n,m;
bitset<33> t;
struct base{
	int bin[23];
	base(){
		for (int i=0;i<23;i++) bin[i]=0;
	}
	void prt(){
		for (int i=0;i<23;i++){
			if (!bin[i]) continue;
			t=bin[i];
			cout<<i<<" "<<t<<endl;
		}
		cout<<endl;
	}
} a,b,c;
void ins(base& a,int x){
	for (int i=22;i>=0;i--){
		if (!(x&(1<<i))) continue;
		if (!a.bin[i]){
			a.bin[i]=x;
			break;
		}
		else x^=a.bin[i];
	}
}
bool ext(base a,int x){
	for (int i=22;i>=0;i--){
		if (!(x&(1<<i))) continue;
		if (a.bin[i]) x^=a.bin[i];
	}
	return x==0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		ins(a,x);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		ins(b,x);
	}
	for (int s=0;s<(1<<8);s++){
		if (ext(a,s)&&ext(b,s)) ins(c,s);
	}
	a.prt();
	b.prt();
	printf("-------------\n");
	c.prt();
	return 0;
}
