#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		system("./getinA");
		system("./A_40");
		cnt++;
		if (cnt>=1e3) break;
	}
	return 0;
}
