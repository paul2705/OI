#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
char a[MAXN];
int T;
int main(){
	scanf("%d",&T);
	while (T--){
		cin>>a;
		int len=strlen(a);
		int f=0,f1=0,f2=0;
		for (int i=0;i<len;i++){
			if (a[i]>='A'&&a[i]<='Z') f++;
			if (a[i]>='a'&&a[i]<='z') f1++;
			if (a[i]>='0'&&a[i]<='9') f2++;
		}
//		cout<<f<<" "<<f1<<" "<<f2<<endl;
	if (f&&f1&&f2) a[len+1]='0';
		else if (f&&f1) for (int i=0;i<len;i++){
			if (a[i]>='A'&&a[i]<='Z'&&f>1){
				a[i]='0';
				break;
			}
			if (a[i]>='a'&&a[i]<='z'&&f1>1){
				a[i]='0';
				break;
			}
//			cout<<'i'<<endl;
		}
		else if (f&&f2) for (int i=0;i<len;i++){
			if (a[i]>='A'&&a[i]<='Z'&&f>1){
				a[i]='a';
				break;
			}
			if (a[i]>='0'&&a[i]<='9'&&f2>1){
				a[i]='a';
				break;
			}
		}
		else if (f1&&f2) for (int i=0;i<len;i++){
			if (a[i]>='a'&&a[i]<='z'&&f1>1){
				a[i]='A';
				break;
			}
			if (a[i]>='0'&&a[i]<='9'&&f2>1){
				a[i]='A';
				break;
			}
		}
		else if (f){
			int mn=1e9,l=0,r=0;
		for (int i=0;i<len;i++){
			for (int j=i+1;j<len;j++){
				if (a[i]>='A'&&a[i]<='Z'&&a[j]>='A'&&a[j]<='Z') 
					if (j-i+1<mn){
						mn=j-i+1; l=i,r=j;
					}
				}
			}
			a[l]='a'; a[r]='0';
    		}
	else if (f1){
        int mn=1e9,l=0,r=0;
        for (int i=0;i<len;i++){
            for (int j=i+1;j<len;j++){
                if (a[i]>='a'&&a[i]<='z'&&a[j]>='a'&&a[j]<='z')
                    if (j-i+1<mn){
                        mn=j-i+1; l=i,r=j;
                    }
            }
        }
	a[l]='A'; a[r]='0';
    }
else if (f2){
    int mn=1e9,l=0,r=0;
    for (int i=0;i<len;i++){
        for (int j=i+1;j<len;j++){
            if (a[i]>='0'&&a[i]<='9'&&a[j]>='0'&&a[j]<='9')
                if (j-i+1<mn){
                    mn=j-i+1; l=i,r=j;
                }
        }
    }
	a[l]='A'; a[r]='a';
}
		for (int i=0;i<len;i++) cout<<a[i];
		cout<<endl;
	}
	return 0;
}
