#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
int a[5][5],start,endd,pnt=15;
vector<int> ans1,ans2;
map<int,int> vis;
map<int,vector<int> >fun;
int sgn(int x){
    if(x==0)return 0;
    if(x>0)return 1;
    return -1;
}
int incr(int x){
    if(x<0)return x-1;
    return x+1;
}
int bfs(){
    queue<int> que;
    que.push(start);
    vis[start]=1;
    que.push(endd);
    vis[endd]=-1;
    while(!que.empty()){
        int now=que.front();
        que.pop();
        bool r1,r2;long long temp;
        for(int i=1; i<=4; i++){
            for(int j=1; j<=4; j++){
                if(i<4){
                    r1=now&(1<<a[i][j]),r2=now&(1<<a[i+1][j]);
                    temp=now-(1<<a[i][j])*r1+(1<<a[i+1][j])*r1-(1<<a[i+1][j])*r2+(1<<a[i][j])*r2;
                    if(!vis[temp]){
                        vector<int> c;
                        c=fun[now];
                        c.push_back(i*1000+j*100+(i+1)*10+j);
                        que.push(temp);
                        fun[temp]=c;
                        vis[temp]=incr(vis[now]);
                    }
                    else if(sgn(vis[now])!=sgn(vis[temp])){
                        fun[temp].push_back(i*1000+j*100+(i+1)*10+j);
                        ans1=fun[now],ans2=fun[temp];
                        return abs(vis[now])+abs(vis[temp])-1;
                    }
                }
                if(j<4){
                    r1=now&(1<<a[i][j]),r2=now&(1<<a[i][j+1]);
                    temp=now-(1<<a[i][j])*r1+(1<<a[i][j+1])*r1-(1<<a[i][j+1])*r2+(1<<a[i][j])*r2;
                    if(!vis[temp]){
                        vector<int> c;
                        c=fun[now];
                        c.push_back(i*1000+j*100+i*10+j+1);
                        que.push(temp);
                        fun[temp]=c;
                        vis[temp]=incr(vis[now]);
                    }
                    else if(sgn(vis[now])!=sgn(vis[temp])){
                        fun[temp].push_back(i*1000+j*100+i*10+j+1);
                        ans1=fun[now],ans2=fun[temp];
                        return abs(vis[now])+abs(vis[temp])-1;
                    }
                }

            }
        }
    }
	return 0;

}
int main(){
    for(int i=1; i<=16; i++){
        int tmp;
        scanf("%1d",&tmp);
        start<<=1;
        start+=tmp;
    }
    for(int i=1; i<=16; i++){
        int tmp;
        scanf("%1d",&tmp);
        endd<<=1;
        endd+=tmp;
    }
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            a[i][j]=pnt;
            pnt--;
        }
    }
    int ans=bfs();
    printf("%d\n",ans);
    for(int i=0;i<ans1.size();i++){
        printf("%d\n",ans1[i]);
    }
    for(int i=0;i<ans2.size();i++){
        printf("%d\n",ans2[i]);
    }
    return 0;
}
