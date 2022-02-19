#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++;
		cout<<cnt<<endl;
		system("./getinA");
		system("./gift");
		system("./A");
		if (system("diff gift.out gift.ans -b")) break;
	}
	return 0;
}
