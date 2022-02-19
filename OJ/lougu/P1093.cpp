#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e2+5;
struct stu{
	int id,ch,score;
} a[MAXN];
int n;
bool cmp(stu a,stu b){
	if (a.score==b.score){
		if (a.ch==b.ch) return a.id<b.id;
		else return a.ch>b.ch;
	}
	else return a.score>b.score;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		a[i]=(stu){i,x,x+y+z};
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=5;i++) printf("%d %d\n",a[i].id,a[i].score);
	return 0;
}
