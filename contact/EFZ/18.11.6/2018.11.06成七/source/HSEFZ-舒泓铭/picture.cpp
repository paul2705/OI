#include<iostream>
#include<cstdio>
#include<algorithm>

const int maxn=1024;

int an,am;
int bn,bm;
char a[maxn][maxn];
char b[maxn][maxn];
char aa[maxn][maxn];
char bb[maxn][maxn];

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
#ifndef lll
    freopen("./picture.in","r",stdin);
    freopen("./picture.out","w",stdout);
#endif

    std::cin>>an>>am;
    for(int i=0;i<an;i++){
        for(int j=0;j<am;j++){
            std::cin>>a[i][j];
        }
    }
    std::cin>>bn>>bm;
    for(int i=0;i<bn;i++){
        for(int j=0;j<bm;j++){
            std::cin>>b[i][j];
        }
    }

    int nn=an*bn/gcd(an,bn);
    int mm=am*bm/gcd(am,bm);
    for(int i=0;i<nn;i++){
        for(int j=0;j<mm;j++){
            aa[i][j]=a[i/(bn/gcd(an,bn))][j/(bm/gcd(am,bm))];
        }
    }
    for(int i=0;i<nn;i++){
        for(int j=0;j<mm;j++){
            bb[i][j]=b[i/(an/gcd(an,bn))][j/(am/gcd(am,bm))];
        }
    }

    int cnt=0;
    for(int i=0;i<nn;i++){
        for(int j=0;j<mm;j++){
            if(aa[i][j]==bb[i][j]){
                cnt++;
            }
        }
    }

    std::cout<<cnt<<std::endl;
    return 0;
}

