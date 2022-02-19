#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read(){
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
int n; bool mp[1010][1010]; 
struct Rec{
	int x,y;
}rec[1000010]; int rectop;
int mrk1[1010][1010];
void getmrk1(int xi,int yi,int xj,int yj){
	mrk1[xi][yi]++; mrk1[xi][yj+1]--;
	mrk1[xj+1][yi]--; mrk1[xj+1][yj+1]++;
}
int mrk2[1010][1010];
void getmrk2(int xi,int yi,int xj,int yj){
	mrk2[xi][yi]++; mrk2[xj+1][yj+1]--;
}
int mrk3[1010][1010];
void getmrk3(int xi,int yi,int xj,int yj){
	mrk3[xi][yi]++; mrk3[xj+1][yj-1]--;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			mp[i][j]=read();
			if (mp[i][j]) rec[++rectop]=(Rec){i,j};
		}
	if (rectop>n+n){
		for (int i=1;i<=n;i++,putchar('\n'))
			for (int j=1;j<=n;j++)
				putchar('Y'),putchar(' ');
		return 0;
	}
	for (int i=1;i<rectop;i++)
		for (int j=i+1;j<=rectop;j++)
			if (((rec[i].x+rec[i].y)&1)==((rec[j].x+rec[j].y)&1)){
				int xi=rec[i].x,yi=rec[i].y,xj=rec[j].x,yj=rec[j].y;
				if (yi==yj){
					int tmp=(xi+xj)>>1;
					getmrk1(tmp,1,tmp,n);
					continue;
				}
				if (xi==xj){
					int tmp=(yi+yj)>>1;
					getmrk1(1,tmp,n,tmp);
					continue;
				}
				if (xi>xj) swap(xi,xj),swap(yi,yj);
				if (yi<yj){
					int dis=xj-xi+yj-yi;
					int xk,yk;
					if (xj-xi>=yj-yi){
						xk=xi+(dis>>1);
						yk=yi;
					}
					else{
						xk=xj;
						yk=yj-(dis>>1);
					}
					int tmp=min(yj-yk,xk-xi);
					int xp=xk-tmp,yp=yk+tmp;
					if (yp==yj&&yp<n) getmrk1(xp,yp+1,xp,n);
					if (xp==xi&&xp>1) getmrk1(1,yp,xp-1,yp);
					if (yp==yj&&xp==xi&&yp<n&&xp>1) getmrk1(1,yp+1,xp-1,n);
					if (yk==yi&&yk>1) getmrk1(xk,1,xk,yk-1);
					if (xk==xj&&xk<n) getmrk1(xk+1,yk,n,yk);
					if (yk==yi&&xk==xj&&yk>1&&xk<n) getmrk1(xk+1,1,n,yk-1);
					getmrk3(xp,yp,xk,yk);
					continue;
				}
				//printf("%d %d  %d %d\n",xi,yi,xj,yj);
				int dis=xj-xi+yi-yj;
				int xk,yk;
				if (xj-xi>=yi-yj){
					xk=xj-(dis>>1);
					yk=yj;
				}
				else{
					xk=xi;
					yk=yi-(dis>>1);
				}
				//printf("%d %d\n",xk,yk);
				int tmp=min(yi-yk,xj-xk);
				int xp=xk+tmp,yp=yk+tmp;
				//printf("%d %d\n",xp,yp);
				if (yp==yi&&yp<n) getmrk1(xp,yp+1,xp,n);
				if (xp==xj&&xp<n) getmrk1(xp+1,yp,n,yp);
				if (yp==yi&&xp==xj&&yp<n&&xp<n) getmrk1(xp+1,yp+1,n,n);
				if (xk==xi&&xk>1) getmrk1(1,yk,xk-1,yk);
				if (yk==yj&&yk>1) getmrk1(xk,1,xk,yk-1);
				if (xk==xi&&yk==yj&&xk>1&&yk>1) getmrk1(1,1,xk-1,yk-1);
				getmrk2(xk,yk,xp,yp);
			}
	for (int i=1;i<=n;i++,putchar('\n')){
		for (int j=1;j<=n;j++){
			mrk1[i][j]=mrk1[i][j]+mrk1[i-1][j]+mrk1[i][j-1]-mrk1[i-1][j-1];
			mrk2[i][j]+=mrk2[i-1][j-1];
			mrk3[i][j]+=mrk3[i-1][j+1];
			if (mrk1[i][j]+mrk2[i][j]+mrk3[i][j]) putchar('Y');
			else putchar('N');
			putchar(' ');
		}
	}
	return 0;
}
