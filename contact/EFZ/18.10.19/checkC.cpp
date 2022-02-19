#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++;
		system("./getinC");
		system("./icekingdom2");
		system("./icekingdomC");
		if (system("diff icekingdom.out icekingdom1.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
