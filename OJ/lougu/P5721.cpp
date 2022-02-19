#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
    int cnt=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n-i+1;j++) printf("%02d",++cnt);
        cout<<endl;
    }
    return 0;
}
