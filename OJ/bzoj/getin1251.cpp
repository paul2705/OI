#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<queue>
#include"sys/time.h"
using namespace std;
int main(){
    freopen("bzoj1251.in","w",stdout);
    struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
    int n=5,qn=7;
    cout<<n<<" "<<qn<<endl;
    for(int i=1;i<=qn;i++){
        int type=rand()%3+1;printf("%d ",type);
        int r=rand()%n+1,l=rand()%n+1;
        if(l > r)
          swap(l, r);
        if(type==1){
            printf("%d %d %d\n",l,r,rand()%100-100);
        }else if(type==2){
            printf("%d %d\n",l,r);
        }else if(type==3){
            printf("%d %d\n",l,r);
        }
    }
	fclose(stdout);
    return 0;
}
