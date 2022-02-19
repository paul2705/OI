#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int fa[MAXN],sm[MAXN],a[MAXN];
int n,m,k;
const int dx[4]={1,-1,-2,2};
int get(int x,int y){ return (x-1)*m+y; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx==fy) return;
	fa[fx]=fy;
	sm[fy]+=sm[fx]; sm[fx]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='.'&&c!='*') c=getchar();
			a[get(i,j)]=c=='.';
			fa[get(i,j)]=get(i,j);
			sm[get(i,j)]=1;
		}
	}
	for (int i=1;i<=n*m;i++){
		if (a[i]){
			for (int j=0;j<4;j++){
				if (i%m==1&&j==1) continue;
				if (i%m==0&&j==0) continue;
				int id=i+dx[j];
				if (dx[j]==-2) id+=2-m;
				if (dx[j]==2) id+=m-2;
//				cout<<i<<" "<<id<<endl;
				if (id<1||id>n*m) continue;
				//cout<<i<<" "<<id<<endl;
				if (a[id]) uion(i,id);
			}
		}
	}
//	for (int i=1;i<=n*m;i++) cout<<i<<" "<<find(i)<<" "<<sm[find(i)]<<endl;
	scanf("%d",&k);
	for (int i=0,op,l,x,y;i<k;i++){
		scanf("%d%d",&op,&l);
		int ans=0;
		if (op==1){
			int ret=0;
			for (int j=1;j<=l;j++){
				scanf("%d%d",&x,&y);
//				cout<<x<<" "<<y<<" "<<sm[find(get(x,y))]<<endl;
				if (ans<sm[find(get(x,y))]){
					ret=j;
					ans=sm[find(get(x,y))];
//					cout<<ans<<" ";
				}
			}
//			cout<<endl;
			printf("%d\n",ret);
		}
		else{
			for (int j=1;j<=l;j++){
				scanf("%d%d",&x,&y);
				int id=get(x,y);
				if (a[id]) sm[find(id)]--,fa[id]=id;
				else{
					a[id]=1;
					for (int _=0;_<4;_++){
						if (id%m==1&&_==1) continue;
						if (id%m==0&&_==0) continue;
						int nid=id+dx[_]; 
						if (dx[_]==-2) nid+=2-m;
						if (dx[_]==2) nid+=m-2;
						if (nid<1||nid>n*m) continue;
						if (a[nid]) uion(id,nid);
					}
				}
			}
		}
	}
	return 0;
}
