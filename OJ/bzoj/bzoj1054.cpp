#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct rec{
	int a[MAXN][MAXN],d;
	bool operator == (const rec& b) const {
		for (int i=1;i<=4;i++){
			for (int j=1;j<=4;j++){
				if (a[i][j]!=b.a[i][j]) return 0;
			}
		}
		return 1;
	}
	void prt(){
		cout<<d<<endl;
		for (int i=1;i<=4;i++){
			for (int j=1;j<=4;j++) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
};
queue<rec> ql,qr;
rec S,T;
int use[(1<<17)];
bool ubd(int x,int y){
	 return x<1||x>4||y<1||y>4;
}
int main(){
	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			char c=getchar(); while (c!='1'&&c!='0') c=getchar();
			S.a[i][j]=c-'0';
		}
	}
	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			char c=getchar(); while (c!='1'&&c!='0') c=getchar();
			T.a[i][j]=c-'0';
		}
	}
	S.d=T.d=0;
	if (S==T) return printf("0\n"),0;
//	cout<<"done"<<endl;
	ql.push(S); qr.push(T);
	int now=0;
	while (true){
//		cout<<"stp: "<<now<<endl;
		rec x=ql.front();
		while (x.d<=now){
//			cout<<"in "<<ql.empty()<<endl;
			ql.pop();
//			x.prt();
			for (int i=1;i<=4;i++){
				for (int j=1;j<=4;j++){
//					cout<<i<<" "<<j<<" "<<endl;
					if (x.a[i][j]==0) continue;
					for (int k=0;k<4;k++){
//						cout<<k<<endl;
						int nx=i+dx[k],ny=j+dy[k];
						if (x.a[nx][ny]==1) continue;
						if (ubd(nx,ny)) continue;
//						cout<<k<<endl;
						rec tmp=x;
//						cout<<k<<endl;
						swap(tmp.a[i][j],tmp.a[nx][ny]);
//						cout<<"fu"<<k<<endl;
						tmp.d++;
						int t=0;
//						cout<<k<<endl;
						for (int l=1;l<=4;l++){
							for (int r=1;r<=4;r++){
								t=t*2+tmp.a[l][r];
							}
						}
						if (use[t]==0){
							use[t]=tmp.d;
							ql.push(tmp);
						}
//						cout<<k<<endl;
					}
				}
			}
//			cout<<"nxt"<<endl;
			x=ql.front();
		}
//		cout<<"fuck"<<endl;
		bool flag=0;
		x=qr.front();
		while (x.d<=now){
			qr.pop(); if (flag) break;
			for (int i=1;i<=4;i++){
				for (int j=1;j<=4;j++){
					if (x.a[i][j]==1) continue;
					for (int k=0;k<4;k++){
						int nx=i+dx[k],ny=j+dy[k];
						if (x.a[nx][ny]==0) continue;
						if (ubd(nx,ny)) continue;
						rec tmp=x;
						swap(tmp.a[i][j],tmp.a[nx][ny]);
						tmp.d++;
						qr.push(tmp);
						int t=0;
						for (int l=1;l<=4;l++){
							for (int r=1;r<=4;r++){
								t=t*2+tmp.a[l][r];
							}
						}
						if (!flag&&use[t]){
							flag=1;
							printf("%d\n",now+use[t]+1);
						}
					}
				}
			}
			x=qr.front();
		}
		now++;
//		cout<<"out"<<endl;
		if (flag) break;
/*		while (true){
			rec x=ql.front(); ql.pop();
			int t=0;
			for (int i=1;i<=4;i++){
				for (int j=1;j<=4;j++){
					t=t*2+x.a[i][j];
				}
			}
			if (!use[t]) break;
			use[t]=0;
			ql.push(x);
		}*/
	}
//	cout<<"out"<<endl;
	return 0;
}
