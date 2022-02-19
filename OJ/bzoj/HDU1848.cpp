
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
int f[N];
int sg[N];
int Hash[N];

void getSG(int n){
    memset(sg,0,sizeof(sg));
    for(int i = 1; i <= n; i++){
        memset(Hash,0,sizeof(Hash));
        for(int j = 1; f[j] <= i; j++)
            Hash[sg[i-f[j]]] = 1;
        for(int j = 0; j <= n; j++){   
            if(Hash[j] == 0){
                sg[i] = j;
                break;
            }
        }
    }
}

int main(){
    f[0] = f[1] = 1;
    for(int i = 2; i <= 16; i++)
        f[i] = f[i-1]+f[i-2];
    getSG(1000);
    int m,n,p;
    while(scanf("%d%d%d",&m,&n,&p),m+n+p){
        if(sg[m]^sg[n]^sg[p])
            puts("Fibo");
        else
            puts("Nacci");
    }
    return 0;
}
