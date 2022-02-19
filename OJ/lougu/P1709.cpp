#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5000110;
int n;
char s[maxn];
int Mini(int l){    
    int i,j,k;  
    i=0;j=1;k=0;  
    while(i<l&&j<l){  
        k=0;  
        while(s[(i+k)%l]==s[(j+k)%l]&&k<l) k++;  
        if(k==l) return (i<j)?i:j;  
        if(s[(i+k)%l]>s[(j+k)%l])i=i+k+1;
        else j=j+k+1;
        if(i==j)j++;
    } 
    return (i<j)?i:j;
}     
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>s[i];
    int l=Mini(n);
    printf("%d\n",l);
    return 0;
}
