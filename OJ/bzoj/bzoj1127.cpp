#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e3+5;
int l[MAXN][MAXN],h[MAXN][MAXN];
ll a[MAXN][MAXN];
struct rec{
	int x,y;
} f[MAXN][MAXN];
int n;
ll k;
bool flag=0;
ll sum(int x1,int y1,int x2,int y2){
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
int main(){
	scanf("%lld%d",&k,&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if (!flag&&a[i][j]>=k&&a[i][j]<=2*k){
				printf("%d %d %d %d\n",i,j,i,j);
//				flag=1;
			}
		}
	}
	if (flag) return 0;
//	cout<<"l: "<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]<k) l[i][j]=l[i][j-1]+1;
			else l[i][j]=0;
//			printf("%d %d %d\n",i,j,l[i][j]);
		}
	}
//	cout<<"h: "<<endl;
	for (int j=1;j<=n;j++){
		for (int i=1;i<=n;i++){
			if (a[i][j]<k) h[i][j]=h[i-1][j]+1;
			else h[i][j]=0;
//			printf("%d %d %d\n",i,j,h[i][j]);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	for (int i=1;i<=n;i++){
		f[i][1]=(rec){l[i][1],h[i][1]};
		for (int j=2;j<=n;j++){
			if (l[i][j]-1>=f[i-1][j-1].x&&h[i][j]-1>=f[i-1][j-1].y) f[i][j]=(rec){f[i-1][j-1].x+1,f[i-1][j-1].y+1};
			else if (l[i][j]-1>=f[i-1][j-1].x) f[i][j]=(rec){f[i-1][j-1].x+1,h[i][j]};
			else if (h[i][j]-1>=f[i-1][j-1].y) f[i][j]=(rec){l[i][j],f[i-1][j-1].y+1};
			else f[i][j]=(rec){l[i][j],h[i][j]};
//			printf("%d %d %d %d\n",i,j,f[i][j].x,f[i][j].y);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<f[i][j].x<<" "<<f[i][j].y<<endl;
			int x1=i-f[i][j].y+1,y1=j-f[i][j].x+1;
			int x2=i,y2=j;
			if (flag) break;
			if (sum(x1,y1,x2,y2)>=k){
				if (sum(x1,y1,x2,y2)<=2*k){
					flag=1;
					printf("%d %d %d %d\n",x1,y1,x2,y2);
				}
				else {
					while (x1<x2&&sum(x1+1,y1,x2,y2)>2*k){
						x1++;
					}
					if (x1<x2&&sum(x1+1,y1,x2,y2)<k){
						for (int x=y1;x<=y2;x++){
							if (sum(x1,x,x2,y2)>=k&&sum(x1,x,x2,y2)<=2*k){
								printf("%d %d %d %d\n",x1,y1,x1,y2);
								flag=1;
								break;
							}
						}
					}
					else if (x1<x2){
						printf("%d %d %d %d\n",x1+1,y1,x2,y2);
						flag=1;
					}
					else {
						for (int x=y1;x<=y2;x++){
							if (sum(x2,x,x2,y2)>=k&&sum(x2,x,x2,y2)<=2*k){
								flag=1;
								printf("%d %d %d %d\n",x2,x,x2,y2);
								break;
							}
						}
					}
				}
			}
		}
	}
//	cout<<"f "<<flag<<endl;
	if (!flag) printf("NIE\n");
	return 0;
}
